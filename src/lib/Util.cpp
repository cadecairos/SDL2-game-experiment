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