//main file for the bogey enemy
#include <bogey.hpp>
#include <cstdlib>
#include <ctime>

interceptors::bogey::bogey(){
	using interceptors::bogey;
	//TODO
	health = 3;
    position = sf::Vector2f(0.0f, 0.0f);
    pathPosition = 0;
    sf::Texture bogey;
    //bogey.loadFromFile("bogey.png");
    //enemySprite.setTexture(bogey);

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

//	  path[0] = sf::Vector2f(position.x + 1, position.y);
//    path[1] = sf::Vector2f(position.x + 1, position.y);
//    path[2] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[3] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[4] = sf::Vector2f(position.x, position.y + 1);
//    path[5] = sf::Vector2f(position.x, position.y + 1);
//    path[6] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[7] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[8] = sf::Vector2f(position.x + 1, position.y);
//    path[9] = sf::Vector2f(position.x + 1, position.y);
//
//    path[10] = sf::Vector2f(position.x + 1, position.y);
//    path[11] = sf::Vector2f(position.x + 1, position.y);
//    path[12] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[13] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[14] = sf::Vector2f(position.x, position.y + 1);
//    path[15] = sf::Vector2f(position.x, position.y + 1);
//    path[16] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[17] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[18] = sf::Vector2f(position.x + 1, position.y);
//    path[19] = sf::Vector2f(position.x + 1, position.y);
//
//    path[20] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[21] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[22] = sf::Vector2f(position.x, position.y + 1);
//    path[23] = sf::Vector2f(position.x, position.y + 1);
//    path[24] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[25] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[26] = sf::Vector2f(position.x - 1, position.y);
//    path[27] = sf::Vector2f(position.x - 1, position.y);
//    path[28] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[29] = sf::Vector2f(position.x - 1, position.y + 1);
//
//    path[30] = sf::Vector2f(position.x - 1, position.y);
//    path[31] = sf::Vector2f(position.x - 1, position.y);
//    path[32] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[33] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[34] = sf::Vector2f(position.x, position.y + 1);
//    path[35] = sf::Vector2f(position.x, position.y + 1);
//    path[36] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[37] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[38] = sf::Vector2f(position.x - 1, position.y);
//    path[39] = sf::Vector2f(position.x - 1, position.y);
//
//    path[40] = sf::Vector2f(position.x - 1, position.y);
//    path[41] = sf::Vector2f(position.x - 1, position.y);
//    path[42] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[43] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[44] = sf::Vector2f(position.x, position.y + 1);
//    path[45] = sf::Vector2f(position.x, position.y + 1);
//    path[46] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[47] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[48] = sf::Vector2f(position.x - 1, position.y);
//    path[49] = sf::Vector2f(position.x - 1, position.y);

	fireSteps[0] = 4;
    fireSteps[1] = 14;
    fireSteps[2] = 24;
    fireSteps[3] = 34;
    fireSteps[4] = 44;
}

void interceptors::bogey::death(){
	using interceptors::bogey;
	//TODO
	//despawn();
	//sf::Texture explosion;
	//explosion.loadFromFile("explosion.png");
	//enemySprite.setTexture(explosion);
	//window.draw(enemySprite);
}

//void interceptors::bogey::despawn(){
//	using interceptors::bogey;
//	//TODO
//	//bogey.erase();
//}

sf::Vector2f interceptors::bogey::getPosition(){
	using interceptors::bogey;
	//TODO
	return position;
}

void interceptors::bogey::setPosition(float a, float b){
	using interceptors::bogey;
	//TODO
	position = sf::Vector2f(a, b);
}

void interceptors::bogey::shoot(){
	using interceptors::bogey;
	//TODO
	bullet shot;
	for (int i = 0; i < 5; i++) {
	    if (pathPosition = fireSteps[i]) {
	        shot.fire();
	    }
	}
}

void interceptors::bogey::takeHit(){
	using interceptors::bogey;
	//TODO
	health -= 1;
}

int interceptors::bogey::getHealth(){
	using interceptors::bogey;
	//TODO
	return health;
}

sf::Vector2f interceptors::bogey::getNextMovement(){
	using interceptors::bogey;
	//TODO
	return path[pathPosition + 1];
}

void interceptors::bogey::move(){
	using interceptors::bogey;
	//TODO
	position = path[pathPosition + 1];
}
