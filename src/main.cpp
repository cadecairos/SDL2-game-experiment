#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char *args[]) {
  SDL_Window *window = NULL;
  SDL_Surface *surface = NULL;

  SDL_Init(SDL_INIT_VIDEO);

  const int SCREEN_WIDTH = 1280;
  const int SCREEN_HEIGHT = 768;

  window = SDL_CreateWindow("GhostHunter", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  surface = SDL_GetWindowSurface(window);

  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

  SDL_UpdateWindowSurface(window);

  SDL_Delay(5000);

  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}