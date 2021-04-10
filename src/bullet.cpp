//this is the main bullet file

#include <bullet.hpp>

interceptors::bullet::bullet(){
	using interceptors::bullet;
	b_texture.loadFromFile("../assets/bulletsprite.png");
	b_sprite.setTexture(b_texture);
}

//set the position of the bullet
void interceptors::bullet::setStartPosition(float start_x, float start_y){
	using interceptors::bullet;
	b_position.x = start_x;
	b_position.y = start_y;
}

//set the direction in which the bullet should fire
void interceptors::bullet::setFireDirection(int direction){
	using interceptors::bullet;
	b_direction = direction;
}

//get the direction the bullet is facing
sf::Vector2f interceptors::bullet::getFireDirection(){
	using interceptors::bullet;
	return b_position;
}

//spawn and fire the bullet
void interceptors::bullet::fire(float deltaMS){
	using interceptors::bullet;
	// move bullet up
	if (b_direction = 0) {
		b_position.y -= deltaMS * b_speed;
	}

	// move bullet down
	if (b_direction = 1) {
		b_position.y += deltaMS * b_speed;
	}

	b_sprite.setPosition(b_position);
}

//despawn the bullet (on edge of screen or on hit)
void interceptors::bullet::despawn(){
	using interceptors::bullet;
}

//set the bullet speed (for the machine gun power-up)
void interceptors::bullet::setSpeed(float speed){
	using interceptors::bullet;
	b_speed = speed;
}

//get the hitbox of the bullet
sf::FloatRect interceptors::bullet::getBulletHitbox(){
	using interceptors::bullet;
	return b_sprite.getGlobalBounds();
}