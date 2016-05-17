#include "StateEngine.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "Timer.h"

const int FRAMES_PER_SECOND = 60;
const int MAX_TICK = 1000 / FRAMES_PER_SECOND;

GHStateEngine::GHStateEngine(int w, int h) : width(w), height(h) {
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();

  SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_OPENGL, &window,
                              &renderer);

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
  SDL_RenderClear(renderer);

  state_id = STATE_NULL;
  next_state = STATE_NULL;
  current_state = NULL;
}

GHStateEngine::~GHStateEngine() {
  if (current_state != NULL) {
    delete current_state;
  }

  SDL_DestroyRenderer(renderer);
  renderer = NULL;

  SDL_DestroyWindow(window);
  window = NULL;

  SDL_Quit();
}

void GHStateEngine::set_next_state(int next) {
  if (next_state == STATE_EXIT) {
    return;
  }

  next_state = next;
}

void GHStateEngine::change_state() {

  // no state change
  if (next_state == STATE_NULL) {
    return;
  }

  // if we're not exiting, free dat memory
  if (next_state != STATE_EXIT) {
    delete current_state;
  }

  switch (next_state) {
  case STATE_TITLE:
    current_state = new GHTitle(this);
    break;

  case STATE_AREA:
    current_state = new GHArea(this);
    break;
  }

  state_id = next_state;
  next_state = STATE_NULL;
}

const int GHStateEngine::get_width() { return width; }

const int GHStateEngine::get_height() { return height; }

void GHStateEngine::apply_surface(SDL_Surface *surface, SDL_Rect srcRect,
                                  SDL_Rect destRect) {
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
  SDL_DestroyTexture(texture);
}

SDL_Surface *GHStateEngine::get_surface() {
  return SDL_GetWindowSurface(window);
}

void GHStateEngine::run() {
  int frame = 0;
  int ticks;
  Timer fps;
  while (state_id != STATE_EXIT) {
    fps.start();

    SDL_RenderClear(renderer);

    current_state->handle_events(this);

    current_state->update(this);

    change_state();

    current_state->render(this);

    SDL_RenderPresent(renderer);

    frame++;

    ticks = fps.get_ticks();

    if ((ticks < MAX_TICK)) {
      // Limit FPS to FRAMES_PER_SECOND
      SDL_Delay(MAX_TICK - ticks);
    }
  }
}