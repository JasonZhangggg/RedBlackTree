#include <iostream>
#include "Node.h"

using namespace std;

void addNode(Node*&, int);
void traverseTree(Node*);

int main(){
	Node* head;
	addNode(head, 5);
	addNode(head, 10);
	addNode(head, 3);
	traverseTree(head);

}
void addNode(Node* &head, int val){
	if(head == NULL){
		head = new Node(val);
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
	if(head->getLeft() == NULL){
		head->setLeft(new Node(val));
		return;
	}
	else{
		Node* left = head->getLeft();
		addNode(left, val);
	}
}
void traverseTree(Node* head){
	if(head == NULL){
		return;
	}
	traverseTree(head->getLeft());
	cout<<head->getVal()<<" ";
	traverseTree(head->getRight());
}
