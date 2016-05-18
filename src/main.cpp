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

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "StateEngine.h"

int main(int argc, char *args[]) {
  // TODO: configurable?
  const int SCREEN_WIDTH = 1280;
  const int SCREEN_HEIGHT = 768;

  // initialize the state engine
  GHStateEngine* stateEngine = new GHStateEngine(SCREEN_WIDTH, SCREEN_HEIGHT);
  
  // Start the game loop
  stateEngine->run();

  // free the memory
  delete stateEngine;

  // end program
  return 0;
}