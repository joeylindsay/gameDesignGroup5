//the main file for the playerView class

#include<playerView.hpp>

interceptors::playerView::playerView(bullet* bullets, sf::RenderWindow* playerWindow, aiView* m_aiView){
	using interceptors::playerView;
	
	//save the window and bullet lists in their local containers
	playerWindowP = playerWindow;
	bulletsP = bullets;
}

void interceptors::playerView::updateHealth(){
	using interceptors::playerView;
	//TODO
}

void interceptors::playerView::getTimeStop(){
	using interceptors::playerView;
	//TODO
}

int* interceptors::playerView::detectCollisions(){
	using interceptors::playerView;
	//TODO
}

void interceptors::playerView::draw(){
	using interceptors::playerView;
	playerWindowP->clear(sf::Color::Black);
	playerWindowP->display();
}
