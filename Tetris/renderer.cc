#include "renderer.h"

#include <iostream>

Renderer::Renderer() : renderer_(nullptr) {}

Renderer::~Renderer() { destroy(); }

void Renderer::init(SDL_Window *window) {
  renderer_ = SDL_CreateRenderer(window, -1, 0);
}

void Renderer::destroy() {
  if (renderer_ != nullptr) {
    std::cout << "Destroy renderer\n";
    SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
  }
}

void Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  if (renderer_ == nullptr) {
    std::cout << "Renderer: setDrawColor: Renderer not exists\n";
    return;
  }

  SDL_SetRenderDrawColor(renderer_, r, g, b, a);
}

void Renderer::present() {
  if (renderer_ == nullptr) {
    std::cout << "Renderer: present: Renderer not exists\n";
    return;
  }

  SDL_RenderPresent(renderer_);
}

void Renderer::clear() {
  if (renderer_ == nullptr) {
    std::cout << "Renderer: clear: Renderer not exists\n";
    return;
  }

  SDL_RenderClear(renderer_);
}
