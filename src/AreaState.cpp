#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

#include "StateEngine.h"

SDL_Surface *load_image(std::string filename);

GHArea::GHArea(GHStateEngine *const &engine) {
  SDL_Color textColor = {255, 255, 255};

  font = TTF_OpenFont("resources/FiraSans-Medium.ttf", 64);
  if (!font) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
    // handle error
  }
  background = engine->get_surface();
  SDL_FillRect(background, NULL, SDL_MapRGB(background->format, 0, 0, 0));

  message = TTF_RenderUTF8_Blended(font, "Main Screen", textColor);
}

GHArea::~GHArea() {
  SDL_FreeSurface(background);
  SDL_FreeSurface(message);
}

void GHArea::handle_events(GHStateEngine *const &engine) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      engine->set_next_state(STATE_EXIT);
    } else if (event.type == SDL_KEYDOWN) {
      if (event.key.keysym.sym == SDLK_RETURN) {
        engine->set_next_state(STATE_TITLE);
      } else if (event.key.keysym.sym == SDLK_ESCAPE) {
        engine->set_next_state(STATE_EXIT);
      }
    }
  }
}

void GHArea::update(GHStateEngine *const &engine) {}

void GHArea::render(GHStateEngine *const &engine) {
  int screenWidth = engine->get_width();
  int screenHeight = engine->get_height();

  srcRect.x = destRect.x = destRect.y = srcRect.y = 0;
  srcRect.w = destRect.w = screenWidth;
  srcRect.h = destRect.h = screenHeight;

  engine->apply_surface(background, srcRect, destRect);

  srcRect.w = destRect.w = message->w;
  srcRect.h = destRect.h = message->h;

  destRect.x = (screenWidth - message->w) / 2;
  destRect.y = (screenHeight - message->h) / 2;

  engine->apply_surface(message, srcRect, destRect);
}