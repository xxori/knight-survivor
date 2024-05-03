# UOA OOP Project

Object Oriented Programming Major Practical Assignment

## Build

To build this project, make sure to have CMake installed locally.

### Desktop

```
mkdir build
cd build
cmake ..
make
```

## Run

```
./game
```

## UML

```mermaid
classDiagram
    class Game {
        -Player player
        -vector~GameEntity~ entities
        -vector~GameEntity~ ui_entities
        -float dt
        +UpdateAll()
        +DrawAll(Camera2D camera)
        +AddEntity(GameEntity entity)
        +AddUIEntity(GameEntity entity)
        +get_player() Player
    }
    Game o-- GameEntity
    class GameEntity {
        -Vector2 pos
        -Game game
        +GameEntity(Game game)
        +Update(float dt)*
        +Draw()*
        +get_pos() Vector2
        +set_pos(Vector2 pos)
        +get_game() Game
    }
    class Player {
        -float speed$
        +Player(Game game)
    }
    GameEntity <|-- Player
    class Text {
        -string text
        -int size
        -Color color
        +Text(Game game)
        +Text(Game game, string text, Vector2 pos, int size, Color color)
        +get_size() int
        +set_size(int size)
        +get_text() string
        +set_text(string text)
    }
    GameEntity <|-- Text
    class Background {
        -int size
        +Background(Game game, int size)
    }
    GameEntity <|-- Background
    class FPSCounter {
        -int max_count$
        -int counter
        -float dt_average
        +FPSCounter(Game game)
    }
    Text <|-- FPSCounter
```
