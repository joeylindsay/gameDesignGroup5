//the main bullet list file

#include <bulletList.hpp>
#include <iostream>

//the main constructor. Instantiate an empty list with head and tail nodes
interceptors::bulletList::bulletList(){
	using interceptors::bulletList;
	//start the tail node of the bullet list
	tail = new bulletNode();
	tail->next = NULL;
		
	//start the head node of the bullet
	head = new bulletNode();
	head->next  = tail;
	head->previous = NULL;
	tail->previous = head;
	
	//initialize the length
	length = 0;
}

//push a new bullet to the start of the list
void interceptors::bulletList::pushNode(sf::Texture* bulletTex, int speed, sf::Vector2f position){
	using interceptors::bulletList;
	
	//initialize the new node
	bulletNode* newNode = new bulletNode();
	newNode->m_bullet = bullet(bulletTex, speed, position);
	
	//add the node onto the list
	newNode->next = head->next;
	newNode->previous = head;
	head->next->previous = newNode;
	head->next = newNode;
	
	//increment the length
	length += 1;
}

//pop a node from a specific position in the list
void interceptors::bulletList::popNode(int pos){
	using interceptors::bulletList;
	
	//walk backward until we're standing on the node we want to remove
	bulletNode* currentNode = tail;
	for (int i=length; i>pos; i--){
		currentNode = currentNode->previous;
	}
	
	//remove the node
	bulletNode* tmpNext = currentNode->next;
	bulletNode* tmpPrev  = currentNode->previous;
	
	currentNode->previous->next = tmpNext;
	currentNode->next->previous = tmpPrev;
	currentNode->~bulletNode();
	//decrement the length
	length -= 1;
}

void interceptors::bulletList::toConsole(){
	bulletNode* currentNode = head->next;
	std::cout << "head -> ";
	while (currentNode->next != NULL){
		std::cout << "node -> ";
		currentNode = currentNode->next;
	}
	std::cout << "tail" << std::endl;
}
