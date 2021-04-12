//this is the main bullet file

#include <bullet.hpp>

//dummy constructor to make the compiler happy
interceptors::bullet::bullet(){}

//main constructor. Sets up a bullet with a pointer to the texture (to avoid constantly
//reloading from file), its desired speed, and its desired position
interceptors::bullet::bullet(sf::Texture* bulletTex, int speed, sf::Vector2f position){
	using interceptors::bullet;
	//set the texture
	b_sprite.setTexture(*bulletTex);
	
	//set the position
	b_position.x = position.x;
	b_position.y = position.y;
	b_sprite.setPosition(position);
	
	//set the origin
	b_sprite.setOrigin(bulletTex->getSize().x/2.5, bulletTex->getSize().y);
	
	//set direction and speed
	b_direction = 0;
	b_speed = speed;
}

//set the position of the bullet
void interceptors::bullet::setPosition(float start_x, float start_y){
	using interceptors::bullet;
	b_position.x = start_x;
	b_position.y = start_y;
}

//set the position of the bullet
sf::Vector2f interceptors::bullet::getPosition(){
	using interceptors::bullet;
	return b_position;
}

//set the direction in which the bullet should fire
void interceptors::bullet::setDirection(float angle){
	using interceptors::bullet;
	b_direction = angle;
	b_sprite.setRotation(angle);
}

//spawn and fire the bullet
void interceptors::bullet::move(){
	using interceptors::bullet;
	// move bullet up
	b_position.y -= b_speed;
	//b_position.x += b_speed;

	b_sprite.setPosition(b_position);
}

//get the hitbox of the bullet
sf::FloatRect interceptors::bullet::getBulletHitbox(){
	using interceptors::bullet;
	return b_sprite.getGlobalBounds();
}

