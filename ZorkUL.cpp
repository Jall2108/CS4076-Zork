#include <iostream>
#include <vector>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "Weapon.h"
#include "item.h"

using namespace std;
#include "ZorkUL.h"
#include "mainwindow.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

     MainWindow w;
      w.show();
      return a.exec();
}

ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    Room *lab, *armoury, *messhall, *medbay, *wheelhouse, *storage, *dorms, *hallway, *stairs, *kitchen;

    lab = new Room("Lab");
    armoury = new Room("Armoury");
    messhall = new Room("Mess Hall");
    medbay = new Room("Medbay");
    wheelhouse = new Room("Wheelhouse");
    storage = new Room("Storage");
    dorms = new Room("Dorms");
    hallway = new Room("Hallway");
    stairs = new Room("Stairs");
    kitchen = new Room("Kitchen");
    lab->addItem(new Item("Clues", 1, 11));
    armoury->addItem(new Item("Gun", 10, 22));
    wheelhouse->addItem(new Item("Tracker", 2, 33));
    medbay->addItem(new Item("Bandages", 5, 44));

//             (N, E, S, W)
    lab->setExits(armoury, hallway , medbay , NULL);
    armoury->setExits(NULL, medbay, lab, NULL);
    messhall->setExits(kitchen, NULL, dorms, hallway);
    medbay->setExits(lab, NULL, NULL, armoury);
    wheelhouse->setExits(NULL, NULL, hallway, NULL);
    storage->setExits(stairs, NULL, NULL, NULL);
    dorms->setExits(messhall, NULL, NULL, kitchen);
    hallway->setExits(wheelhouse, messhall, stairs, lab);
    stairs->setExits(hallway, NULL, storage, NULL);
    kitchen->setExits(NULL, dorms, messhall, NULL);

        currentRoom = armoury;


        rooms.push_back(*lab);
        rooms.push_back(*armoury);
        rooms.push_back(*messhall);
        rooms.push_back(*wheelhouse);
        rooms.push_back(*medbay);
        rooms.push_back(*storage);
        rooms.push_back(*dorms);
        rooms.push_back(*hallway);
        rooms.push_back(*stairs);
        rooms.push_back(*kitchen);

    }


/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        cout << "[armoury] --- [medbay] --- [lab]" << endl;
        cout << "                             |         " << endl;
        cout << "                             |         " << endl;
        cout << "                            [hallway] --- [messhall] --- [kitchen] --- [dorms]" << endl;
        cout << "                                                                          |         " << endl;
        cout << "                                                                          |         " << endl;
        cout << "                                                                         [hallway] --- [wheelhouse] --- [hallway]" << endl;
        cout << "                                                                                                            |         " << endl;
        cout << "                                                                                                            |         " << endl;
        cout << "                                                                                                        [stairs] --- [storage]" << endl;
        }


    else if (commandWord.compare("go") == 0)
        goRoom(command);

    else if (commandWord.compare("teleport") == 0)
            ranTeleport();


    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
    }
    return false;
}

void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}


string ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return currentRoom->longDescription();

    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;        

    }
    return currentRoom->longDescription();

}

string ZorkUL::ranTeleport() {
    currentRoom = &rooms.at((int) rand() % rooms.size());
    cout << currentRoom->longDescription() << endl;
    return "";
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
