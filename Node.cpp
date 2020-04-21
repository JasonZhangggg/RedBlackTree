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
	parent = NULL;
	color = 1;
}

//get val of node
int Node:: getVal(){
	return val;
}
void Node:: setVal(int newVal){
	val = newVal;
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
void Node::setParent(Node* newParent){
	parent = newParent;
}
//get left
Node* Node::getLeft(){
	return left;
}

Node* Node::getParent(){
	return parent;
}
void Node::setColor(int newColor){
	color = newColor;
}
int Node::getColor(){
	return color;
}
Node* Node::getGp(){
	return parent->getParent();
}
Node* Node::getSibling(){
	if(parent == NULL){
		return NULL;
	}
	if(this == parent->getLeft()){
		return parent->getRight();
	}
	else{
		return parent->getLeft();
	}
}
Node* Node::getUncle(){
	if(parent == NULL) return NULL;
	return parent->getSibling();
}
void Node::rotateLeft(){
	Node* r = right;
	Node* p = parent;
	if(r = NULL) return;
	right = r->getLeft();
	r->setLeft(this);
	parent = r;
	if(right != NULL){
		right->setParent(this);
	}
	if (p != NULL) {
		if (this == p->getLeft()) {
			p->setLeft(r);
		} else if (this == p->getRight()) {
			p->setRight(r);
		}
	}
	r->setParent(p);
}
void Node::rotateRight() {
	Node* l = left;
	Node* p = parent;
	if(l == NULL) return;
	left = l->getRight();
	l->setRight(this);
	parent = l;

	if (left != NULL) {
		left->setParent(this);
	}

	if (p != NULL) {
		if (this == p->getLeft()) {
			p->setLeft(l);
		} else if (this == p->getRight()) {
			p->setRight(l);
		}
	}
	l->setParent(p);
}

//deconstructor
Node::~Node(){
	//val = 0;
	//right = NULL;
	//left = NULL;
}
