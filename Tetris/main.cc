
#include "game_manager.h"

int main() {
  auto &gameManager = GameManager::getInstace();

  gameManager.init();

  return 0;
}
