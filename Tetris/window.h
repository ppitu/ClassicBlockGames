#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <SDL2/SDL.h>

class Window {
public:
  static Window &getInstance() {
    static Window instance;
    return instance;
  }

  ~Window();

  void init(const std::string &title, int x, int y, int w, int h, Uint32 flags);
  void destroy();

  SDL_Window *getWindow();

private:
  Window();

  SDL_Window *window_;
};

#endif // WINDOW_H
