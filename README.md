# 🏰 Echoes of the Forgotten Realm

A mysterious text adventure game where you explore ancient ruins, solve puzzles, and battle shadowy creatures. Navigate through interconnected rooms, collect powerful artifacts, and decide your fate in this immersive console-based experience.

## ✨ Features

- **Immersive Exploration**: Navigate through 5 unique locations, each with atmospheric descriptions
  - Ancient Entrance
  - Grand Hall
  - Forgotten Library
  - Dark Crypt
  - Throne of Echoes

- **Combat System**: Engage in dynamic turn-based battles with shadowy enemies
  - Attack with your sword
  - Use items from your inventory
  - Attempt to escape from danger

- **Inventory Management**: Collect and carry items throughout your journey
  - Rusty Sword - A sturdy blade for combat
  - Ancient Scroll - Mysterious ancient knowledge
  - Crown of Echoes - A glowing artifact of power

- **Multiple Endings**: Your choices determine your fate
  - **Good Ending**: Claim the throne with the proper artifacts
  - **Bad Ending**: Face the consequences of being unprepared

- **Intuitive Commands**: Simple text-based commands for exploration and interaction

## 🎮 How to Play

### Commands
- **Movement**: `north`, `south`, `east`, `west` - Navigate to different rooms
- **Items**: `take [item name]` - Pick up items in your current location
- **Inventory**: `inventory` or `inv` - View items you're carrying
- **Look**: `look` - Examine your current surroundings again
- **Help**: `help` - Display available commands
- **Quit**: `quit` or `exit` - Leave the game

### Gameplay Tips
1. Explore all rooms to find valuable items
2. Combat involves strategic choices - decide whether to fight, use items, or escape
3. Collect multiple artifacts to achieve the good ending
4. Pay attention to room descriptions for clues and atmosphere

## 🛠️ Requirements

- C++17 or later
- CMake 3.10 or higher
- A C++ compiler (GCC, Clang, MSVC, etc.)

## 📦 Installation

### Clone the Repository
```bash
git clone https://github.com/Naji-Ullah/echoes-of-the-forgotten-realm.git
cd echoes-of-the-forgotten-realm
```

### Build the Project
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Run the Game
```bash
./EchoesOfTheRealm
```

## 🏗️ Project Structure

```
echoes-of-the-forgotten-realm/
├── main.cpp          # Main game logic and classes
├── CMakeLists.txt    # Build configuration
└── README.md         # This file
```

## 📖 Code Overview

### Classes

#### `Item`
Represents collectible objects in the game world.
- `name`: Display name of the item
- `description`: Detailed item description

#### `Room`
Defines the game world structure.
- `name`: Room identifier
- `description`: Atmospheric description
- `exits`: Map of directions to connected rooms
- `items`: Items available in the room
- `hasEnemy`: Whether the room contains an enemy

#### `Player`
Represents the adventurer exploring the realm.
- `name`: Player's chosen name
- `health`: Current HP (starts at 100)
- `inventory`: Collection of items carried

## 🎯 Game Flow

1. **Welcome**: Player enters their name
2. **Exploration**: Navigate through rooms and interact with the environment
3. **Combat**: Battle enemies using strategy and items
4. **Ending**: Reach the Throne of Echoes to determine your destiny

## 🤝 Contributing

Contributions are welcome! Feel free to:
- Add new rooms and storylines
- Enhance the combat system
- Improve item mechanics
- Add sound or visual enhancements

## 📝 License

This project is open source and available under the MIT License. Feel free to use, modify, and distribute as you see fit.

## 🚀 Future Enhancements

- [ ] Save/Load game functionality
- [ ] Experience and leveling system
- [ ] More diverse enemy types
- [ ] Puzzle-solving elements
- [ ] NPC interactions and dialogue
- [ ] Magic system
- [ ] Multiple difficulty levels
- [ ] Improved combat AI

## 👤 Author

**Naji-Ullah** - [GitHub Profile](https://github.com/Naji-Ullah)

---

**Venture forth, adventurer!** The Forgotten Realm awaits your arrival. 🌙✨