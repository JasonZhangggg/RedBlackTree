/*Jason Zhang
  Shunting Yard
  2/20/2020
  */

#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

//Constructor
Node::Node(int newVal) {
	val = newVal;
	right = NULL;
	left = NULL;
}

//get val of node
int Node:: getVal(){
	return val;
}
//set right. 
void Node::setRight(Node* newRight){
	right = newRight;
}
//get right
Node* Node::getRight(){
	return right;
}
//set left
void Node::setLeft(Node* newLeft){
	left = newLeft;
}
//get left
Node* Node::getLeft(){
	return left;
}

//deconstructor
Node::~Node(){
	val = 0;
	right = NULL;
	left = NULL;
}
