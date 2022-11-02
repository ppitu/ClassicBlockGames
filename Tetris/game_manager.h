#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

class Window;
class Renderer;

class GameManager {
public:
  static GameManager &getInstace() {
    static GameManager instance;
    return instance;
  }

  ~GameManager();

  void init();
  void destroy();

private:
  GameManager();

  void gameLoop();
  void handleEvent();
  void update();
  void render();

  bool is_running_;

  Window &window_;
  Renderer &renderer_;
};

#endif // GAME_MANAGER_H
