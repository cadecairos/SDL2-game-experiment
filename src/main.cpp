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