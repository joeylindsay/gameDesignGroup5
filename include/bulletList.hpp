/* A very simple doubly linked list used to keep track of 
all of the bulelts on screen. Stores the head node,
and implements push and pop functions
*/
#ifndef BULLETLIST_HPP
#define BULLETLIST_HPP

#include <bullet.hpp>
#include <bulletNode.hpp>
#include <SFML/Graphics.hpp>

namespace interceptors
{
class bulletList{
	public:
		//base constructor
		bulletList();
		//add a new node
		void pushNode(sf::Texture* bulletTex, int speed, sf::Vector2f position);
		//remove a node
		void popNode(int pos);
		//the head node
		bulletNode* head;
		//the tail node
		bulletNode* tail;
		//the length of the list
		int length;
		//debug function for printing
		void toConsole();
	};
}

#endif
		
