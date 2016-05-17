#include "Util.h"

SDL_Surface *load_image(std::string filename) {
  SDL_Surface *image = NULL;

  image = IMG_Load(filename.c_str());

  // TODO: Error Handling
  if (image != NULL) {
    SDL_SetColorKey(image, SDL_TRUE,
                    SDL_MapRGB(image->format, 0, 0xFF, 0xFF));
  }

  return image;
}