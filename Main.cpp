#include <iostream>
#include "Node.h"

using namespace std;

void addNode(Node*&, char*);
int main(){
	

}
void addNode(Node* &head, int val){
	if(head == NULL){
		head = new Node(Val);
		return;
	}
	if(head->getRight() == NULL){
		head->setRight(new Node (val));
		return;
	}
	else{
		Node* right = head->getRight();
		addNode(right, val);
	}	
	else if(head->getLeft() == NULL){
		head->setLeft(new Node(val));
		return;
	}
	else{
		Node* left = head->getLeft();
		addNode(left, val);
	}
}
