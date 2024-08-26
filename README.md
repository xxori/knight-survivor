# Knight Survivor

Object Oriented Programming Major Practical Assignment

## Build

To build this project, make sure to have CMake installed locally.

```sh
mkdir build
cd build
cmake .. # Debug
cmake -DCMAKE_BUILD_TYPE=Release .. # Release
make
```

## Run

In `build` folder

```sh
./game # Game
./test_runner # Tests
```

## Class Diagram

```mermaid
classDiagram
    class Game {
        -Player player
        -GameObject[] enemies
        -GameObject[] UIElements
        -Projectile[] projectiles
        -GameObject[] mainMenu
        -GameObject[] pauseMenu
        -GameObject[] deathMenu
        -enum gameState
        +updateAll()
        +drawAll(Camera2D camera)
        +addEnemy(GameEntity *enemy)
        +addProjectile(Projectile *projectile)
        +removeEnemy(GameEntity *enemy)
        +removeProjectile(Projectile *projectile)
        +addUIElement(GameObject *element)
        +removeUIElement(GameObject *element)
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
        -Weapon[] weapons
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
        -time timeToFire
        +update(float deltaTime)
    }
    Player o-- Weapon
    class Projectile {
        -int damage
        -float speed
        +update(float DeltaTime)
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
    class Button {
        -string text
        -int width
        -int height
        -int fontSize
        -Color color
    }
    GameObject <|-- Button
```
