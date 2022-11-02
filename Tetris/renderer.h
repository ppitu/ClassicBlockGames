#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

class Renderer {
public:
  static Renderer &getInstance() {
    static Renderer instance;
    return instance;
  }

  ~Renderer();

  void init(SDL_Window *window);
  void destroy();

  void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  void clear();
  void present();

private:
  Renderer();

  SDL_Renderer *renderer_;
};

#endif // RENDERER_H
