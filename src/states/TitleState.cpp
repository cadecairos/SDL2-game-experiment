/*
** Copyright 2016 Christopher De Cairos
**
** This file is part of Ghost Hunter.
**
** Ghost Hunter is free software: you can redistribute it and/or modify it under
** the terms of the GNU General Public License as published by the Free Software
** Foundation, either version 3 of the License, or (at your option) any later version.
**
** Ghost Hunter is distributed in the hope that it will be useful, but WITHOUT ANY 
** WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
** PARTICULAR PURPOSE. See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with
** Ghost Hunter. If not, see http://www.gnu.org/licenses/.
*/

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

#include "../engine/StateEngine.h"
#include "../lib/Util.h"

GHTitle::GHTitle(GHStateEngine *const &engine) {
  SDL_Color textColor = {255, 255, 255};

  font = TTF_OpenFont("resources/FiraSans-Medium.ttf", 64);
  if (!font) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
    // handle error
  }
  background = engine->get_surface();
  SDL_FillRect(background, NULL, SDL_MapRGB(background->format, 0, 0, 0));

  message = TTF_RenderUTF8_Blended(font, "Title Screen", textColor);
}

GHTitle::~GHTitle() {
  SDL_FreeSurface(background);
  SDL_FreeSurface(message);
}

void GHTitle::handle_events(GHStateEngine *const &engine) {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      engine->set_next_state(STATE_EXIT);
    } else if (event.type == SDL_KEYDOWN) {
      if (event.key.keysym.sym == SDLK_RETURN) {
        engine->set_next_state(STATE_AREA);
      } else if (event.key.keysym.sym == SDLK_ESCAPE) {
        engine->set_next_state(STATE_EXIT);
      }
    }
  }
}

void GHTitle::update(GHStateEngine *const &engine) {}

void GHTitle::render(GHStateEngine *const &engine) {
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