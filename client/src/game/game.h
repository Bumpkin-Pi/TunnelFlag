//
// Created by holly on 15/03/23.
//

#ifndef TUNNELFLAG_GAME_H
#define TUNNELFLAG_GAME_H
#include "objects.h"

struct Map{
    int width;
    int height;
    int map[128][128];
};

struct ServerInfo{
    int port;
    int address;
    std::string name;
};


class Game{
public:
    ServerInfo server;
    Map map;
    Player players[64];
    int number_of_players;
    int localPlayerID;

    bool connected; //Check to stop client from attempting to get server info from localhost while loading

    Game();
    Game(ServerInfo, Map, int, int); // Parameters are in the order of the above declaration
};

#endif //TUNNELFLAG_GAME_H
