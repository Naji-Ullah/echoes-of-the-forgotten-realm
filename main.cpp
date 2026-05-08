#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

// Simple Item class
class Item {
public:
    string name;
    string description;
    Item(string n, string desc) : name(n), description(desc) {}
};

// Room class
class Room {
public:
    string name;
    string description;
    map<string, Room*> exits;
    vector<Item> items;
    bool hasEnemy;

    Room(string n, string desc, bool enemy = false) : name(n), description(desc), hasEnemy(enemy) {}

    void addExit(string direction, Room* room) {
        exits[direction] = room;
    }

    void addItem(Item item) {
        items.push_back(item);
    }
};

// Player class
class Player {
public:
    string name;
    int health;
    vector<Item> inventory;

    Player(string playerName) : name(playerName), health(100) {}

    void addItem(Item item) {
        inventory.push_back(item);
        cout << "You picked up: " << item.name << endl;
    }

    void showInventory() {
        cout << "\n=== Inventory ===" << endl;
        if (inventory.empty()) {
            cout << "Your inventory is empty." << endl;
        } else {
            for (const auto& item : inventory) {
                cout << "- " << item.name << ": " << item.description << endl;
            }
        }
        cout << "=================" << endl;
    }
};

// Global rooms
Room* currentRoom = nullptr;

void printWelcome() {
    cout << "\n========================================" << endl;
    cout << "   ECHOES OF THE FORGOTTEN REALM" << endl;
    cout << "========================================" << endl;
    cout << "A mysterious text adventure awaits..." << endl << endl;
}

void describeRoom() {
    cout << "\nYou are in: " << currentRoom->name << endl;
    cout << currentRoom->description << endl;

    if (!currentRoom->items.empty()) {
        cout << "\nYou see: ";
        for (const auto& item : currentRoom->items) {
            cout << item.name << " ";
        }
        cout << endl;
    }

    cout << "\nExits: ";
    for (const auto& exit : currentRoom->exits) {
        cout << exit.first << " ";
    }
    cout << endl;
}

bool fightEnemy(Player& player) {
    cout << "\nA shadowy creature appears!" << endl;
    int enemyHealth = 60;

    while (enemyHealth > 0 && player.health > 0) {
        cout << "\nYour health: " << player.health << " | Enemy health: " << enemyHealth << endl;
        cout << "1. Attack with sword\n2. Use item\n3. Run" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            int damage = 15 + rand() % 10;
            enemyHealth -= damage;
            cout << "You strike for " << damage << " damage!" << endl;

            if (enemyHealth > 0) {
                int edamage = 10 + rand() % 15;
                player.health -= edamage;
                cout << "The creature hits you for " << edamage << "!" << endl;
            }
        } else if (choice == 2) {
            if (!player.inventory.empty()) {
                cout << "You throw an item at the creature!" << endl;
                enemyHealth -= 25;
                player.inventory.pop_back();
            } else {
                cout << "No items to use!" << endl;
            }
        } else if (choice == 3) {
            if (rand() % 2 == 0) {
                cout << "You successfully escaped!" << endl;
                return true;
            } else {
                cout << "Escape failed!" << endl;
            }
        }
    }

    if (player.health <= 0) {
        cout << "You were defeated..." << endl;
        return false;
    }
    cout << "Victory! The creature is defeated." << endl;
    return true;
}

int main() {
    srand(time(0));

    printWelcome();

    string playerName;
    cout << "Enter your name, adventurer: ";
    getline(cin, playerName);
    Player player(playerName);

    // Create rooms
    Room entrance("Ancient Entrance", "You stand before a crumbling stone archway covered in glowing runes.", false);
    Room hall("Grand Hall", "A vast hall with faded tapestries. Dust dances in the moonlight.", true);
    Room library("Forgotten Library", "Shelves tower around you, filled with ancient tomes.", false);
    Room crypt("Dark Crypt", "The air is cold. Shadows seem to move on their own.", true);
    Room throne("Throne of Echoes", "A majestic yet eerie throne room. Power lingers here.", false);

    // Connect rooms
    entrance.addExit("north", &hall);
    hall.addExit("south", &entrance);
    hall.addExit("east", &library);
    hall.addExit("west", &crypt);
    library.addExit("west", &hall);
    crypt.addExit("east", &hall);
    crypt.addExit("north", &throne);
    throne.addExit("south", &crypt);

    // Add items
    entrance.addItem(Item("Rusty Sword", "An old but sturdy blade"));
    library.addItem(Item("Ancient Scroll", "A scroll with mysterious runes"));
    throne.addItem(Item("Crown of Echoes", "A glowing crown that hums with energy"));

    currentRoom = &entrance;

    cout << "\nType 'help' for commands." << endl;

    string command;
    bool gameOver = false;

    while (!gameOver) {
        describeRoom();

        if (currentRoom->hasEnemy) {
            if (!fightEnemy(player)) {
                cout << "\nGame Over. The realm claims another soul..." << endl;
                break;
            }
            currentRoom->hasEnemy = false;
        }

        cout << "\nWhat do you do? > ";
        getline(cin, command);

        if (command == "quit" || command == "exit") {
            cout << "Farewell, adventurer..." << endl;
            break;
        } else if (command == "help") {
            cout << "\nCommands: north, south, east, west, take [item], inventory, look, quit" << endl;
        } else if (command == "look") {
            describeRoom();
        } else if (command == "inventory" || command == "inv") {
            player.showInventory();
        } else if (command.find("take ") == 0) {
            string itemName = command.substr(5);
            bool found = false;
            for (auto it = currentRoom->items.begin(); it != currentRoom->items.end(); ++it) {
                if (it->name == itemName || it->name.find(itemName) != string::npos) {
                    player.addItem(*it);
                    currentRoom->items.erase(it);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "No such item here." << endl;
        } else if (currentRoom->exits.find(command) != currentRoom->exits.end()) {
            currentRoom = currentRoom->exits[command];
            cout << "You move " << command << "..." << endl;

            if (currentRoom->name == "Throne of Echoes" && player.inventory.size() >= 2) {
                cout << "\nWith the sword and crown, you claim the throne!" << endl;
                cout << "\n=== GOOD ENDING: Ruler of the Realm ===" << endl;
                gameOver = true;
            } else if (currentRoom->name == "Throne of Echoes") {
                cout << "\nYou sit on the throne but without artifacts... shadows consume you." << endl;
                cout << "=== BAD ENDING ===" << endl;
                gameOver = true;
            }
        } else {
            cout << "Unknown command. Type 'help'." << endl;
        }
    }

    cout << "\nThanks for playing!" << endl;
    return 0;
}