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

## Class Diagram

```mermaid
classDiagram
    class Game {
        -Player player
        -GameObject[] enemies
        -GameObject[] uiElements
        -GameObject[] projectiles
        -bool pause
        +updateAll()
        +drawAll(Camera2D camera)
        +addEntity(GameObject entity)
        +addUIElement(GameObject entity)
    }
    Game o-- GameObject
    GameObject <-- Game
    class GameObject {
        -Vector2 position
        -Game game
        +update(float deltaTime)*
        +draw()*
    }
    class GameEntity {
        -Texture texture
        -Rectangle collider
        +collide(GameEntity other) bool
    }
    GameObject <|-- GameEntity
    class Player {
        -float speed
        -Weapon[] weapon
        -int health
        -time lastDamaged
        -Vector2 direction
        +takeDamage(int damage)
    }
    GameEntity <|-- Player
    Game <-- Player
    class Enemy {
        -string name
        -int health
        -int damage
        -time lastDamaged
    }
    GameEntity <|-- Enemy
    class Weapon {
        -string name
        -float fireSpeed
        -time lastFire
        +fireProjectile()
    }
    Player o-- Weapon
    class Projectile {
        -int damage
        -float speed
    }
    GameEntity <|-- Projectile
    class Background {
        -Texture texture
    }
    GameObject <|-- Background
    class Text {
        -string text
        -Color color
        -int size
    }
    GameObject <|-- Text
```
