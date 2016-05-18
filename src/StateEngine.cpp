#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include "StateEngine.h"
#include "Timer.h"

const int FRAMES_PER_SECOND = 60;
const int MAX_TICK = 1000 / FRAMES_PER_SECOND;

GHStateEngine::GHStateEngine(int w, int h) : width(w), height(h) {
  // TODO: SDL and TTF instantiation in separate module
  // initialize SDL and TTF
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();

  // Create a window and render, assign references to them to the class members
  SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_OPENGL, &window,
                              &renderer);

  // make sure the render buffer is a clean slate
  SDL_RenderClear(renderer);

  // Start with no current state
  current_state = NULL;
  state_id = STATE_NULL;

  // Set the initial state to be the title screen state
  next_state = STATE_TITLE;

  // have the game engine instantiate the title screen state
  change_state();
}

GHStateEngine::~GHStateEngine() {
  // Ensure this is still non-null before wiping
  if (current_state != NULL) {
    delete current_state;
  }

  // Have SDL dereference and free the renderer
  SDL_DestroyRenderer(renderer);
  renderer = NULL;

  // Have SDL dereference and free the window
  SDL_DestroyWindow(window);
  window = NULL;

  // de-init the SDL subsystems
  SDL_Quit();
}

void GHStateEngine::set_next_state(int next_state) {
  // Prevent SDLEvents processed after STATE_EXIT is set,
  // to prevent hijacking a quit operation
  if (this->next_state == STATE_EXIT) {
    return;
  }

  this->next_state = next_state;
}

void GHStateEngine::change_state() {
  // no state change
  if (next_state == STATE_NULL) {
    return;
  }

  // if we're not exiting, destruct the current_state
  // exiting will free this in the descructor otherwise
  if (next_state != STATE_EXIT) {
    delete current_state;
  }

  // Construct the correct state instance based on next_state
  switch (next_state) {
  case STATE_TITLE:
    current_state = new GHTitle(this);
    break;

  case STATE_AREA:
    current_state = new GHArea(this);
    break;
  }
  // current state is now next_state
  state_id = next_state;

  // make sure we only change state once per the setting of next_state
  next_state = STATE_NULL;
}

void GHStateEngine::apply_surface(SDL_Surface *surface, SDL_Rect srcRect,
                                  SDL_Rect destRect) {
  // Take an SDL_Surface, transform it into an SDL_Texture
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  // copy the texture tocthe render buffer, using the srcRect and destRect
  // variables to set position and size
  SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
  // Destruct the texture
  SDL_DestroyTexture(texture);
}

// the main game loop
void GHStateEngine::run() {
  // variable to support frame rate limiting
  Timer fps;
  unsigned long int frame = 0;
  int ticks;

  // Loop while we aren't trying to exit
  while (state_id != STATE_EXIT) {
    // start counting approx. ms since loop iteration began
    fps.start();

    // clear the render buffer
    SDL_RenderClear(renderer);

    // Have the current state instance handle SDL_Events in queue
    current_state->handle_events(this);

    // apply any game logic the current state instance has (i.e. collision detection)
    current_state->update(this);

    // check if state needs to change
    change_state();

    // Render the current state
    current_state->render(this);

    // Render the buffer to the window
    SDL_RenderPresent(renderer);

    // count this frame
    frame++;

    // how many ms passed since fps.start()
    ticks = fps.get_ticks();

    if ((ticks < MAX_TICK)) {
      // Limit FPS to FRAMES_PER_SECOND
      SDL_Delay(MAX_TICK - ticks);
    }
  }
}

// Helpers for external rendering functions
// TODO: better way to do this?
const int GHStateEngine::get_width() { return width; }
const int GHStateEngine::get_height() { return height; }
SDL_Surface *GHStateEngine::get_surface() {
  return SDL_GetWindowSurface(window);
}
