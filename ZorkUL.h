#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Parser parser;
    void createRooms();
    void printWelcome();
    void printHelp();
    void createItems();
    void displayItems();

public:
    bool processCommand(Command command);
    ZorkUL();
    void play();
    vector<Room>rooms;
    string ranTeleport();
    string go(string direction);
    Room *currentRoom;
    string goRoom(Command command);


};

#endif /*ZORKUL_H_*/


