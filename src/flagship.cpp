//main file for the flagship enemy
#include <flagship.hpp>
#include <cstdlib>
#include <ctime>

interceptors::flagship::flagship(sf::RenderWindow& window) {
	using interceptors::flagship;
    health = 100;

    window_size = window.getSize();
    int lateral_range = window_size.x;
    int lateral_step = lateral_range / 25;
    int vertical_range = window_size.y;

    position = sf::Vector2f(0, vertical_range / 20);
    pathPosition = 0;

    sf::Texture flagship;
    flagship.loadFromFile("interceptorsprite.png"); // replace with correct flagship sprite file
    enemySprite.setTexture(flagship);

    path[0] = sf::Vector2f(position.x + lateral_step, position.y);
    path[1] = sf::Vector2f(position.x + lateral_step, position.y);
    path[2] = sf::Vector2f(position.x + lateral_step, position.y);
    path[3] = sf::Vector2f(position.x + lateral_step, position.y);
    path[4] = sf::Vector2f(position.x + lateral_step, position.y);
    path[5] = sf::Vector2f(position.x + lateral_step, position.y);
    path[6] = sf::Vector2f(position.x + lateral_step, position.y);
    path[7] = sf::Vector2f(position.x + lateral_step, position.y);
    path[8] = sf::Vector2f(position.x + lateral_step, position.y);
    path[9] = sf::Vector2f(position.x + lateral_step, position.y);

    path[10] = sf::Vector2f(position.x + lateral_step, position.y);
    path[11] = sf::Vector2f(position.x + lateral_step, position.y);
    path[12] = sf::Vector2f(position.x + lateral_step, position.y);
    path[13] = sf::Vector2f(position.x + lateral_step, position.y);
    path[14] = sf::Vector2f(position.x + lateral_step, position.y);
    path[15] = sf::Vector2f(position.x + lateral_step, position.y);
    path[16] = sf::Vector2f(position.x + lateral_step, position.y);
    path[17] = sf::Vector2f(position.x + lateral_step, position.y);
    path[18] = sf::Vector2f(position.x + lateral_step, position.y);
    path[19] = sf::Vector2f(position.x + lateral_step, position.y);

    path[20] = sf::Vector2f(position.x + lateral_step, position.y);
    path[21] = sf::Vector2f(position.x + lateral_step, position.y);
    path[22] = sf::Vector2f(position.x + lateral_step, position.y);
    path[23] = sf::Vector2f(position.x + lateral_step, position.y);
    path[24] = sf::Vector2f(position.x + lateral_step, position.y);

    path[25] = sf::Vector2f(position.x - lateral_step, position.y);
    path[26] = sf::Vector2f(position.x - lateral_step, position.y);
    path[27] = sf::Vector2f(position.x - lateral_step, position.y);
    path[28] = sf::Vector2f(position.x - lateral_step, position.y);
    path[29] = sf::Vector2f(position.x - lateral_step, position.y);

    path[30] = sf::Vector2f(position.x - lateral_step, position.y);
    path[31] = sf::Vector2f(position.x - lateral_step, position.y);
    path[32] = sf::Vector2f(position.x - lateral_step, position.y);
    path[33] = sf::Vector2f(position.x - lateral_step, position.y);
    path[34] = sf::Vector2f(position.x - lateral_step, position.y);
    path[35] = sf::Vector2f(position.x - lateral_step, position.y);
    path[36] = sf::Vector2f(position.x - lateral_step, position.y);
    path[37] = sf::Vector2f(position.x - lateral_step, position.y);
    path[38] = sf::Vector2f(position.x - lateral_step, position.y);
    path[39] = sf::Vector2f(position.x - lateral_step, position.y);

    path[40] = sf::Vector2f(position.x - lateral_step, position.y);
    path[41] = sf::Vector2f(position.x - lateral_step, position.y);
    path[42] = sf::Vector2f(position.x - lateral_step, position.y);
    path[43] = sf::Vector2f(position.x - lateral_step, position.y);
    path[44] = sf::Vector2f(position.x - lateral_step, position.y);
    path[45] = sf::Vector2f(position.x - lateral_step, position.y);
    path[46] = sf::Vector2f(position.x - lateral_step, position.y);
    path[47] = sf::Vector2f(position.x - lateral_step, position.y);
    path[48] = sf::Vector2f(position.x - lateral_step, position.y);
    path[49] = sf::Vector2f(position.x - lateral_step, position.y);

    fireSteps[0] = 4;
    fireSteps[1] = 9;
    fireSteps[2] = 14;
    fireSteps[3] = 19;
    fireSteps[4] = 24;
    fireSteps[5] = 29;
    fireSteps[6] = 34;
    fireSteps[7] = 39;
    fireSteps[8] = 44;
    fireSteps[9] = 49;
}

void interceptors::flagship::death() {
	using interceptors::flagship;
    sf::Texture explosion;
    explosion.loadFromFile("interceptorsprite.png"); //replace with explosion file
    enemySprite.setTexture(explosion);
}

sf::Vector2f interceptors::flagship::getPosition() {
	using interceptors::flagship;
    return position;
}

void interceptors::flagship::setPosition(float a, float b) {
	using interceptors::flagship;
    position = sf::Vector2f(a, b);
}

void interceptors::flagship::shoot() {
	using interceptors::flagship;
    bullet shot;
    for (int i = 0; i < 10; i++) {
        if (pathPosition = fireSteps[i]) {
            shot.fire();
        }
    }
}

void interceptors::flagship::takeHit() {
	using interceptors::flagship;
    health--;
}

int interceptors::flagship::getHealth() {
	using interceptors::flagship;
    return health;
}

//function for retrieving the current path step of the enemy
sf::Vector2f interceptors::flagship::getNextMovement() {
	using interceptors::flagship;
    return path[pathPosition + 1];
}
		
void interceptors::flagship::move() {
	using interceptors::flagship;
    position = path[pathPosition + 1];
}
