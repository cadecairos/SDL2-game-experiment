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

#include <string>

#include "SDL2/SDL_ttf.h"

enum GHGameStates {
  STATE_NULL,
  STATE_TITLE,
  STATE_MENU,
  STATE_CREATE_CHAR,
  STATE_MAP,
  STATE_AREA,
  STATE_BATTLE,
  STATE_EXIT
};

class GHGameState;

class GHStateEngine {
public:
  GHStateEngine(int w, int h);
  ~GHStateEngine();

  void set_next_state(int next);
  void change_state();
  SDL_Surface *load_image(std::string filename);
  const int get_width();
  const int get_height();
  void apply_surface(SDL_Surface *surface, SDL_Rect srcRect, SDL_Rect destRect);
  SDL_Surface *get_surface();
  int get_current_state_id();
  void run();

private:
  int state_id;
  int next_state;
  int width;
  int height;
  int frame = 0;

  GHGameState *current_state = NULL;
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
};

class GHGameState {
public:
  virtual void handle_events(GHStateEngine *const &engine) = 0;
  virtual void update(GHStateEngine *const &engine) = 0;
  virtual void render(GHStateEngine *const &engine) = 0;
  virtual ~GHGameState(){};

protected:
  GHGameState() {}
};

class GHTitle : public GHGameState {
private:
  SDL_Surface *background;
  SDL_Surface *message;
  TTF_Font *font = NULL;
  SDL_Rect srcRect;
  SDL_Rect destRect;

public:
  GHTitle(GHStateEngine *const &engine);
  ~GHTitle();

  void handle_events(GHStateEngine *const &engine);
  void update(GHStateEngine *const &engine);
  void render(GHStateEngine *const &engine);
};

class GHArea : public GHGameState {
private:
  SDL_Surface *background;
  SDL_Surface *message;
  TTF_Font *font = NULL;
  SDL_Rect srcRect;
  SDL_Rect destRect;

public:
  GHArea(GHStateEngine *const &engine);
  ~GHArea();

  void handle_events(GHStateEngine *const &engine);
  void update(GHStateEngine *const &engine);
  void render(GHStateEngine *const &engine);
};