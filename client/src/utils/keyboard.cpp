//
// Created by holly on 09/03/23.
//
#include "keyboard.h"

#include <iostream>
#include <SDL2/SDL.h>
#include "vector2.h"


#include "../game/game.h"
#include "../camera/camera.h"
//Keyboard::Keyboard(bool isit) {
//    this->number = 2;
//    std::cout <<(isit);
//}

extern bool closing;
extern SDL_Event event;
extern Game game;
extern Camera camera;
extern Keybinds keys;

Keyboard::Keyboard() {

}


void Keyboard::listen() { //TODO: System for single click detection and for held detection (open inventory vs WASD)
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {  // Closes the window, if user stops running
        closing = true;
    }else if (event.type == SDL_MOUSEWHEEL){
        if(event.wheel.y > 0){ // scroll up
            this->scale = this->scale*1.1;
        }
        else if(event.wheel.y < 0){// scroll down
            this->scale = this->scale*0.909;
        }
    }
    if (state[keys.player.right]) {
        this->player_move.x = 1;
    }else if (state[keys.player.left]) {
        this->player_move.x = -1;
    }else{
        this->player_move.x = 0;
    }
    if (state[keys.player.up]) {
        this->player_move.y = -1;
    }else if (state[keys.player.down]) {
        this->player_move.y = 1;
    }else{
        this->player_move.y = 0;
    }
}