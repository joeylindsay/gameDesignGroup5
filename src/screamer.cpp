//main file for the screamer enemy
#include <screamer.hpp>
#include <cstdlib>
#include <ctime>

interceptors::screamer::screamer(sf::RenderWindow& window){
	using interceptors::screamer;
    health = 1;

    window_size = window.getSize();
    int lateral_range = window_size.x;
    int lateral_step_fast = lateral_range / 15;
    int lateral_step_slow = lateral_range / 75;
    int vertical_range = window_size.y;
    int vertical_step_fast = vertical_range / 15;
    int vertical_step_slow = vertical_range / 75;

    position = sf::Vector2f(0, vertical_range / 100);
    pathPosition = 0;

    sf::Texture screamer;
    screamer.loadFromFile("interceptorsprite.png"); // replace with correct screamer sprite file
    enemySprite.setTexture(screamer);

    path[0] = sf::Vector2f(position.x + lateral_step_fast, position.y);
    path[1] = sf::Vector2f(position.x + lateral_step_fast, position.y + vertical_step_slow);
    path[2] = sf::Vector2f(position.x + lateral_step_fast, position.y);
    path[3] = sf::Vector2f(position.x + lateral_step_fast, position.y - vertical_step_slow);
    path[4] = sf::Vector2f(position.x + lateral_step_fast, position.y);

    path[5] = sf::Vector2f(position.x + lateral_step_fast, position.y);
    path[6] = sf::Vector2f(position.x + lateral_step_fast, position.y - vertical_step_slow);
    path[7] = sf::Vector2f(position.x + lateral_step_fast, position.y);
    path[8] = sf::Vector2f(position.x + lateral_step_fast, position.y + vertical_step_slow);
    path[9] = sf::Vector2f(position.x + lateral_step_fast, position.y);

    path[10] = sf::Vector2f(position.x, position.y + vertical_step_fast);
    path[11] = sf::Vector2f(position.x - lateral_step_slow, position.y + vertical_step_fast);
    path[12] = sf::Vector2f(position.x, position.y + vertical_step_fast);
    path[13] = sf::Vector2f(position.x + lateral_step_slow, position.y + vertical_step_fast);
    path[14] = sf::Vector2f(position.x, position.y + vertical_step_fast);

    path[15] = sf::Vector2f(position.x - lateral_step_fast, position.y);
    path[16] = sf::Vector2f(position.x - lateral_step_fast, position.y - vertical_step_slow);
    path[17] = sf::Vector2f(position.x - lateral_step_fast, position.y);
    path[18] = sf::Vector2f(position.x - lateral_step_fast, position.y + vertical_step_slow);
    path[19] = sf::Vector2f(position.x - lateral_step_fast, position.y);

    path[20] = sf::Vector2f(position.x - lateral_step_fast, position.y);
    path[21] = sf::Vector2f(position.x - lateral_step_fast, position.y + vertical_step_slow);
    path[22] = sf::Vector2f(position.x - lateral_step_fast, position.y);
    path[23] = sf::Vector2f(position.x - lateral_step_fast, position.y - vertical_step_slow);
    path[24] = sf::Vector2f(position.x - lateral_step_fast, position.y);

    path[25] = sf::Vector2f(position.x, position.y + vertical_step_fast);
    path[26] = sf::Vector2f(position.x + lateral_step_slow, position.y + vertical_step_fast);
    path[27] = sf::Vector2f(position.x, position.y + vertical_step_fast);
    path[28] = sf::Vector2f(position.x - lateral_step_slow, position.y + vertical_step_fast);
    path[29] = sf::Vector2f(position.x, position.y + vertical_step_fast);

    path[30] = sf::Vector2f(position.x + lateral_step_fast, position.y);
    path[31] = sf::Vector2f(position.x + lateral_step_fast, position.y - vertical_step_slow);
    path[32] = sf::Vector2f(position.x + lateral_step_fast, position.y);
    path[33] = sf::Vector2f(position.x + lateral_step_fast, position.y + vertical_step_slow);
    path[34] = sf::Vector2f(position.x + lateral_step_fast, position.y);

    path[35] = sf::Vector2f(position.x + lateral_step_fast, position.y);
    path[36] = sf::Vector2f(position.x + lateral_step_fast, position.y + vertical_step_slow);
    path[37] = sf::Vector2f(position.x + lateral_step_fast, position.y);
    path[38] = sf::Vector2f(position.x + lateral_step_fast, position.y - vertical_step_slow);
    path[39] = sf::Vector2f(position.x + lateral_step_fast, position.y);

    path[40] = sf::Vector2f(position.x + lateral_step_slow, position.y);
    path[41] = sf::Vector2f(position.x + lateral_step_slow, position.y - vertical_step_slow);
    path[42] = sf::Vector2f(position.x, position.y - vertical_step_slow);
    path[43] = sf::Vector2f(position.x - lateral_step_slow, position.y - vertical_step_slow);
    path[44] = sf::Vector2f(position.x - lateral_step_slow, position.y);

    path[45] = sf::Vector2f(position.x - lateral_step_slow, position.y + vertical_step_slow);
    path[46] = sf::Vector2f(position.x, position.y + vertical_step_slow);
    path[47] = sf::Vector2f(position.x + lateral_step_slow, position.y + vertical_step_slow);
    path[48] = sf::Vector2f(position.x + lateral_step_slow, position.y + vertical_step_slow);
    path[49] = sf::Vector2f(position.x, position.y + vertical_step_fast);

    fireSteps[0] = 2;
    fireSteps[1] = 7;
    fireSteps[2] = 17;
    fireSteps[3] = 22;
    fireSteps[4] = 31;
    fireSteps[5] = 33;
    fireSteps[6] = 36;
    fireSteps[7] = 38;
}

void interceptors::screamer::death() {
	using interceptors::screamer;
    sf::Texture explosion;
    explosion.loadFromFile("interceptorsprite.png"); // replace with correct explosion sprite file
    enemySprite.setTexture(explosion);
}

sf::Vector2f interceptors::screamer::getPosition() {
	using interceptors::screamer;
    return position;
}

void interceptors::screamer::setPosition(float a, float b) {
	using interceptors::screamer;
    position = sf::Vector2f(a, b);
}

void interceptors::screamer::shoot() {
	using interceptors::screamer;
    bullet shot;
    for (int i = 0; i < 5; i++) {
        if (pathPosition = fireSteps[i]) {
            shot.fire();
        }
    }
}

void interceptors::screamer::takeHit() {
	using interceptors::screamer;
    health--;
}

int interceptors::screamer::getHealth() {
	using interceptors::screamer;
    return health;
}

sf::Vector2f interceptors::screamer::getNextMovement() {
	using interceptors::screamer;
    return path[pathPosition + 1];
}

void interceptors::screamer::move() {
	using interceptors::screamer;
    position = path[pathPosition + 1];
}
