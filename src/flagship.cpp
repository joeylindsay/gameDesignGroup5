//main file for the flagship enemy
#include <flagship.hpp>
#include <cstdlib>
#include <ctime>

interceptors::flagship::flagship(){
	using interceptors::flagship;
	//TODO
    health = 100;
    position = sf::Vector2f(50.0f, 0.0f);
    sf::Texture flagship;
    //flagship.loadFromFile("flagship.png");
    //enemySprite.setTexture(flagship);

//    path[0] = sf::Vector2f(position.x + 1, position.y);
//    path[1] = sf::Vector2f(position.x + 1, position.y);
//    path[2] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[3] = sf::Vector2f(position.x + 1, position.y);
//    path[4] = sf::Vector2f(position.x + 1, position.y);
//    path[5] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[6] = sf::Vector2f(position.x + 1, position.y);
//    path[7] = sf::Vector2f(position.x + 1, position.y);
//    path[8] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[9] = sf::Vector2f(position.x + 1, position.y);
//
//    path[10] = sf::Vector2f(position.x + 1, position.y);
//    path[11] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[12] = sf::Vector2f(position.x + 1, position.y);
//    path[13] = sf::Vector2f(position.x + 1, position.y);
//    path[14] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[15] = sf::Vector2f(position.x + 1, position.y);
//    path[16] = sf::Vector2f(position.x + 1, position.y);
//    path[17] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[18] = sf::Vector2f(position.x + 1, position.y);
//    path[19] = sf::Vector2f(position.x + 1, position.y);
//
//    path[20] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[21] = sf::Vector2f(position.x + 1, position.y);
//    path[22] = sf::Vector2f(position.x + 1, position.y);
//    path[23] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[24] = sf::Vector2f(position.x + 1, position.y);
//
//    path[25] = sf::Vector2f(position.x - 1, position.y);
//    path[26] = sf::Vector2f(position.x - 1, position.y - 1);
//    path[27] = sf::Vector2f(position.x - 1, position.y);
//    path[28] = sf::Vector2f(position.x - 1, position.y);
//    path[29] = sf::Vector2f(position.x - 1, position.y - 1);
//
//    path[30] = sf::Vector2f(position.x - 1, position.y);
//    path[31] = sf::Vector2f(position.x - 1, position.y);
//    path[32] = sf::Vector2f(position.x - 1, position.y - 1);
//    path[33] = sf::Vector2f(position.x - 1, position.y);
//    path[34] = sf::Vector2f(position.x - 1, position.y);
//    path[35] = sf::Vector2f(position.x - 1, position.y - 1);
//    path[36] = sf::Vector2f(position.x - 1, position.y);
//    path[37] = sf::Vector2f(position.x - 1, position.y);
//    path[38] = sf::Vector2f(position.x - 1, position.y - 1);
//    path[39] = sf::Vector2f(position.x - 1, position.y);
//
//    path[40] = sf::Vector2f(position.x - 1, position.y);
//    path[41] = sf::Vector2f(position.x - 1, position.y - 1);
//    path[42] = sf::Vector2f(position.x - 1, position.y);
//    path[43] = sf::Vector2f(position.x - 1, position.y);
//    path[44] = sf::Vector2f(position.x - 1, position.y - 1);
//    path[45] = sf::Vector2f(position.x - 1, position.y);
//    path[46] = sf::Vector2f(position.x - 1, position.y);
//    path[47] = sf::Vector2f(position.x - 1, position.y - 1);
//    path[48] = sf::Vector2f(position.x - 1, position.y);
//    path[49] = sf::Vector2f(position.x - 1, position.y);

    fireSteps[0] = 4;
    fireSteps[1] = 14;
    fireSteps[2] = 24;
    fireSteps[3] = 34;
    fireSteps[4] = 44;
}

void interceptors::flagship::death(){
	using interceptors::flagship;
	//TODO
    //despawn();
    //sf::Texture explosion;
    //explosion.loadFromFile("explosion.png");
    //enemySprite.setTexture(explosion);
    //window.draw(enemySprite);
}

//void interceptors::flagship::despawn(){
//	using interceptors::flagship;
//	//TODO
//	//bogey_array.erase(i);
//}

sf::Vector2f interceptors::flagship::getPosition(){
	using interceptors::flagship;
	//TODO
    return position;
}

void interceptors::flagship::setPosition(float a, float b){
	using interceptors::flagship;
	//TODO
    position = sf::Vector2f(a, b);
}

void interceptors::flagship::shoot(){
	using interceptors::flagship;
	//TODO
    bullet shot;
    for (int i = 0; i < 5; i++) {
        if (pathPosition = fireSteps[i]) {
            shot.fire();
        }
    }
}

void interceptors::flagship::takeHit(){
	using interceptors::flagship;
	//TODO
    health--;
}

int interceptors::flagship::getHealth(){
	using interceptors::flagship;
	//TODO
    return health;
}

//function for retrieving the current path step of the enemy
sf::Vector2f interceptors::flagship::getNextMovement(){
	using interceptors::flagship;
	//TODO
    return path[pathPosition + 1];
}
		
void interceptors::flagship::move(){
	using interceptors::flagship;
	//TODO
    position = path[pathPosition + 1];
}
