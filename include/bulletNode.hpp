/*The bullet node container. A very simple linked list node
that simply stores a single data member and a pointer to the
next node in the list
*/

#ifndef BULLETNODE_HPP
#define BULLETNODE_HPP

#include <bullet.hpp>

namespace interceptors
{
class bulletNode{
	public:
		//dummy constructor
		bulletNode();
		//destructor to prevent a memory leak
		~bulletNode();
		//store a single bullet data member
		bullet m_bullet;
		//a pointer to the next node
		bulletNode* next;
		//a pointer to the previous node
		bulletNode* previous;
};
}

#endif
