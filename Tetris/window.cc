#include "window.h"

#include <iostream>

Window::Window() : window_(nullptr) {}

Window::~Window() { destroy(); }

void Window::init(const std::string &title, int x, int y, int w, int h,
                  Uint32 flags) {
  window_ = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
}

void Window::destroy() {
  if (window_ != nullptr) {
    std::cout << "Destroy window\n";
    SDL_DestroyWindow(window_);
    window_ = nullptr;
  }
}

SDL_Window *Window::getWindow() { return window_; }
