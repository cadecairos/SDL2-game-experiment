#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "StateEngine.h"

int main(int argc, char *args[]) {
  const int SCREEN_WIDTH = 1280;
  const int SCREEN_HEIGHT = 768;

  GHStateEngine* stateEngine = new GHStateEngine(SCREEN_WIDTH, SCREEN_HEIGHT);

  stateEngine->set_next_state(STATE_TITLE);
  stateEngine->change_state();

  stateEngine->run();

  delete stateEngine;

  return 0;
}