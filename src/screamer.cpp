//main file for the screamer enemy
#include <screamer.hpp>
#include <cstdlib>
#include <ctime>

interceptors::screamer::screamer(){
	using interceptors::screamer;
	//TODO
    health = 1;
    position = sf::Vector2f(0.0f, 100.0f);
    pathPosition = 0;
    sf::Texture screamer;
    //screamer.loadFromFile("screamer.png");
    //enemySprite.setTexture(screamer);

    //srand(time(NULL));

//    float spawn [3];
//    spawn[0] = 12.0f;
//    spawn[1] = 24.0f;
//    spawn[2] = 36.0f;
//    int start_point = rand() % 5;
//    for (int i = 0; i < 5; i++) {
//        if (start_point = i) {
//            position.y = spawn[i];
//        }
//    }

//    path[0] = sf::Vector2f(position.x + 1, position.y);
//    path[1] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[2] = sf::Vector2f(position.x, position.y + 1);
//    path[3] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[4] = sf::Vector2f(position.x, position.y + 1);
//    path[5] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[6] = sf::Vector2f(position.x, position.y + 1);
//    path[7] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[8] = sf::Vector2f(position.x, position.y + 1);
//    path[9] = sf::Vector2f(position.x - 1, position.y + 1);
//
//    path[10] = sf::Vector2f(position.x + 1, position.y);
//    path[11] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[12] = sf::Vector2f(position.x, position.y + 1);
//    path[3] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[14] = sf::Vector2f(position.x, position.y + 1);
//    path[15] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[16] = sf::Vector2f(position.x, position.y + 1);
//    path[17] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[18] = sf::Vector2f(position.x, position.y + 1);
//    path[19] = sf::Vector2f(position.x - 1, position.y + 1);
//
//    path[20] = sf::Vector2f(position.x + 1, position.y);
//    path[21] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[22] = sf::Vector2f(position.x, position.y + 1);
//    path[23] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[24] = sf::Vector2f(position.x, position.y + 1);
//    path[25] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[26] = sf::Vector2f(position.x, position.y + 1);
//    path[27] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[28] = sf::Vector2f(position.x, position.y + 1);
//    path[29] = sf::Vector2f(position.x - 1, position.y + 1);
//
//    path[30] = sf::Vector2f(position.x + 1, position.y);
//    path[31] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[32] = sf::Vector2f(position.x, position.y + 1);
//    path[33] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[34] = sf::Vector2f(position.x, position.y + 1);
//    path[35] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[36] = sf::Vector2f(position.x, position.y + 1);
//    path[37] = sf::Vector2f(position.x + 1, position.y + 1);
//    path[38] = sf::Vector2f(position.x, position.y + 1);
//    path[39] = sf::Vector2f(position.x - 1, position.y + 1);
//
//    path[40] = sf::Vector2f(position.x, position.y + 1);
//    path[41] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[42] = sf::Vector2f(position.x - 1, position.y);
//    path[43] = sf::Vector2f(position.x - 1, position.y - 1);
//    path[44] = sf::Vector2f(position.x, position.y - 1);
//    path[45] = sf::Vector2f(position.x - 1, position.y + 1);
//    path[46] = sf::Vector2f(position.x, position.y - 1);
//    path[47] = sf::Vector2f(position.x - 1, position.y - 1);
//    path[48] = sf::Vector2f(position.x - 1, position.y);
//    path[49] = sf::Vector2f(position.x - 1, position.y + 1);

    fireSteps[0] = 4;
    fireSteps[1] = 14;
    fireSteps[2] = 24;
    fireSteps[3] = 34;
    fireSteps[4] = 44;
}

void interceptors::screamer::death(){
	using interceptors::screamer;
	//TODO
    //despawn();
    //sf::Texture explosion;
    //explosion.loadFromFile("explosion.png");
    //enemySprite.setTexture(explosion);
    //window.draw(enemySprite);
}

//void interceptors::screamer::despawn(){
//	using interceptors::screamer;
//	//TODO
//}

sf::Vector2f interceptors::screamer::getPosition(){
	using interceptors::screamer;
	//TODO
    return position;
}

void interceptors::screamer::setPosition(float a, float b){
	using interceptors::screamer;
	//TODO
    position = sf::Vector2f(a, b);
}

void interceptors::screamer::shoot(){
	using interceptors::screamer;
	//TODO
    bullet shot;
    for (int i = 0; i < 5; i++) {
        if (pathPosition = fireSteps[i]) {
            shot.fire();
        }
    }
}

void interceptors::screamer::takeHit(){
	using interceptors::screamer;
	//TODO
    health -= 1;
}

int interceptors::screamer::getHealth(){
	using interceptors::screamer;
	//TODO
    return health;
}

sf::Vector2f interceptors::screamer::getNextMovement(){
	using interceptors::screamer;
	//TODO
    return path[pathPosition + 1];
}

void interceptors::screamer::move(){
	using interceptors::screamer;
	//TODO
    position = path[pathPosition + 1];
}
