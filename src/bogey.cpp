//main file for the bogey enemy
#include <bogey.hpp>
#include <cstdlib>
#include <ctime>

interceptors::bogey::bogey(sf::RenderWindow& window){
	using interceptors::bogey;
	//TODO
	health = 3;

    window_size = window.getSize();

    position = sf::Vector2f(0, 0);
    pathPosition = 0;

    sf::Texture bogey;
    bogey.loadFromFile("interceptorsprite.png"); // replace with correct bogey sprite file
    enemySprite.setTexture(bogey);

	// randomly generate start position from one of ten options, five on each side of the screen
	// generate off the screen first?

	//srand(time(NULL));

//	int start_side; = rand() % 2;
//	if (spawn_side = 0) {
//	    position.x = 0.0f;
//	    path = left_path;
//	}
//	else {
//	    position.x = 200.0f;
//	    path = right_path;
//	}

//	float spawn [5];
//	spawn[0] = 3.0f;
//    spawn[1] = 6.0f;
//    spawn[2] = 9.0f;
//    spawn[3] = 12.0f;
//    spawn[4] = 15.0f;
//	int start_point = rand() % 5;
//	for (int i; i < 5; i++) {
//        if (start_point = i) {
//            position.y = spawn[i];
//        }
//    }

    int lateral_range = window_size.x;
    int lateral_step = lateral_range / 50;

    int vertical_range = window_size.y;
    int vertical_step = vertical_range / 75;

    path[0] = sf::Vector2f(position.x + lateral_step, position.y);
    path[1] = sf::Vector2f(position.x + lateral_step, position.y);
    path[2] = sf::Vector2f(position.x + lateral_step, position.y);
    path[3] = sf::Vector2f(position.x + lateral_step, position.y);
    path[4] = sf::Vector2f(position.x + lateral_step, position.y);

    path[5] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[6] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[7] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[8] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[9] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);

    path[10] = sf::Vector2f(position.x, position.y + vertical_step);
    path[11] = sf::Vector2f(position.x, position.y + vertical_step);
    path[12] = sf::Vector2f(position.x, position.y + vertical_step);
    path[13] = sf::Vector2f(position.x, position.y + vertical_step);
    path[14] = sf::Vector2f(position.x, position.y + vertical_step);

    path[15] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[16] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[17] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[18] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[19] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);

    path[20] = sf::Vector2f(position.x + lateral_step, position.y);
    path[21] = sf::Vector2f(position.x + lateral_step, position.y);
    path[22] = sf::Vector2f(position.x + lateral_step, position.y);
    path[23] = sf::Vector2f(position.x + lateral_step, position.y);
    path[24] = sf::Vector2f(position.x + lateral_step, position.y);

    path[25] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[26] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[27] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[28] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[29] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);

    path[30] = sf::Vector2f(position.x, position.y + vertical_step);
    path[31] = sf::Vector2f(position.x, position.y + vertical_step);
    path[32] = sf::Vector2f(position.x, position.y + vertical_step);
    path[33] = sf::Vector2f(position.x, position.y + vertical_step);
    path[34] = sf::Vector2f(position.x, position.y + vertical_step);

    path[35] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[36] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[37] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[38] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[39] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);

    path[40] = sf::Vector2f(position.x + lateral_step, position.y);
    path[41] = sf::Vector2f(position.x + lateral_step, position.y);
    path[42] = sf::Vector2f(position.x + lateral_step, position.y);
    path[43] = sf::Vector2f(position.x + lateral_step, position.y);
    path[44] = sf::Vector2f(position.x + lateral_step, position.y);

    path[45] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[46] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[47] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[48] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);
    path[49] = sf::Vector2f(position.x + lateral_step, position.y + vertical_step);

	fireSteps[0] = 4;
    fireSteps[1] = 14;
    fireSteps[2] = 24;
    fireSteps[3] = 34;
    fireSteps[4] = 44;
}

void interceptors::bogey::death() {
	using interceptors::bogey;
	sf::Texture explosion;
	explosion.loadFromFile("interceptorsprite.png"); // replace with correct explosion sprite file
	enemySprite.setTexture(explosion);
}

sf::Vector2f interceptors::bogey::getPosition() {
	using interceptors::bogey;
	return position;
}

void interceptors::bogey::setPosition(float a, float b) {
	using interceptors::bogey;
	position = sf::Vector2f(a, b);
}

void interceptors::bogey::shoot() {
	using interceptors::bogey;
	bullet shot;
	for (int i = 0; i < 5; i++) {
	    if (pathPosition = fireSteps[i]) {
	        shot.fire();
	    }
	}
}

void interceptors::bogey::takeHit() {
	using interceptors::bogey;
	health--;
}

int interceptors::bogey::getHealth() {
	using interceptors::bogey;
	return health;
}

sf::Vector2f interceptors::bogey::getNextMovement() {
	using interceptors::bogey;
	return path[pathPosition + 1];
}

void interceptors::bogey::move() {
	using interceptors::bogey;
	position = path[pathPosition + 1];
}
