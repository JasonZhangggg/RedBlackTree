/*
   Jason Zhang
   Shunting Yard
   2/20/2020
   */

#include <iostream>
#include <cstring>

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node{
	public:
		//constructor
		Node(int);
		//get the val
		int getVal();
		//get the node to the right
		Node* getRight();
		//get the node to the left
		Node* getLeft();
		//set the node to the right
		void setRight(Node*);
		//set the node to the left
		void setLeft(Node*);
		//deconstructor
		~Node();
	private:
		//right and left node
		Node* right;
		Node* left;
		//val of node
		int val;	
};
#endif
