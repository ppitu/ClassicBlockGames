#include "game_manager.h"

#include <SDL2/SDL.h>

#include "renderer.h"
#include "window.h"

GameManager::GameManager()
    : is_running_(false), window_(Window::getInstance()),
      renderer_(Renderer::getInstance()) {}

GameManager::~GameManager() {}

void GameManager::init() {
  SDL_Init(SDL_INIT_EVERYTHING);

  window_.init("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,
               480, 0);

  renderer_.init(window_.getWindow());

  is_running_ = true;

  gameLoop();
}

void GameManager::destroy() {
  is_running_ = false;

  renderer_.destroy();
  window_.destroy();

  SDL_Quit();
}

void GameManager::gameLoop() {

  while (is_running_) {
    handleEvent();
    update();
    render();
  }

  destroy();
}

void GameManager::handleEvent() {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT:
    is_running_ = false;
    break;
  }
}

void GameManager::update() {}

void GameManager::render() {
  renderer_.clear();
  renderer_.setDrawColor(132, 20, 2, 0);
  renderer_.present();
}
