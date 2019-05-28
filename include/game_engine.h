#ifndef SRC_GAME_ENGINE_H_
#define SRC_GAME_ENGINE_H_

#include<SDL2/SDL.h>
#include<vector>

class GameState;

class GameEngine{
public:
    GameEngine(); //SDL初始化

    void clean_up();

    void change_state(GameState* state);
    void push_state(GameState* state);
    void pop_state();

    void execute();
    void input();
    void update();
    void render();

    bool runnning(){return !exit;}
    void quit(){exit = true;}

    //窗口长宽
    int width;
    int height;

    //窗口和渲染器
    SDL_Window * window;
    SDL_Renderer * renderer;

private:

    std::vector<GameState*> states;

    bool exit;

};
#endif
