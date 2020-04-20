/*
 * Jason Zhang
 * Binary Search Tree
 * 3/19/2020
 */

#include <iostream>
#include "Node.h"
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;
void rotateLeft(Node*&, Node*&);
void rotateRight(Node*&, Node*&);
void addNode(Node*&, int);
Node* minVal(Node*);
int main(){
	//declare head
	Node* head = NULL;
	char inType;
	char input[100];
	//ask for input type
	/*
	cout<<"Type 1 for file input and 2 for manual input"<<endl;
	cin>>inType;
	cin.ignore();
	//if file input
	if(inType == '1'){
		//read from file
		cout<<"Input the file name"<<endl;
		char fileName[100];
		cin.getline(fileName, sizeof(fileName));
		ifstream fileStream;
		fileStream.open(fileName);
		if(fileStream){
			fileStream.getline(input, sizeof(input));
		}
		//if file not found
		else{
			cout<<"File does not exist"<<endl;
		}
	}
	//manual input	
	else if(inType == '2'){
		cout<<"Enter the array split by spaces"<<endl;
		cin.getline(input, 100);
	}
	//split by space
	char* list = strtok(input, " ");
	while(list){
		//add node
		addNode(head, atoi(list));
		list = strtok(NULL, " ");
	}*/
	while(true){
		cout<<"Type ADD to add, PRINT to print, SEARCH to search for a value, QUIT to quit, and DELETE to delete a node"<<endl;
		char* input = new char();
		cin.getline(input, sizeof(input));
		for(int i = 0; i<sizeof(input); i++){
			input[i] = toupper(input[i]);
		}
		//Add a node
		if(strcmp(input, "ADD") == 0){
			int val;
			cout<<"Enter the val you want to add: ";
			cin>>val;
			cin.ignore();
			addNode(head, val);
		}	
		//display tree
		else if(strcmp(input, "QUIT") == 0){
			return 0;
		}
		cout<<endl<<"__________________________________________________________________________________________________"<<endl;
	}
}
void addNode(Node* &head, int val){
	//if head is NULL declare it
	if(head == NULL){
		head = new Node(val);
		return;
	}
	//the input val is larger then head
	if(head->getVal()<val){
		//if we are at the base of the tree, add the node to the right of the current node
		if(head->getRight() == NULL){
			head->setRight(new Node (val));
			head->getRight()->setParent(head);
			return;
		}
		//else recursivly traverse right
		else{
			Node* right = head->getRight();
			addNode(right, val);
		}	
	}
	//if input val is smaller then head
	else{
		//if we are at the end of the tree, add the node to the left of the current node
		if(head->getLeft() == NULL){
			head->setLeft(new Node(val));
			head->getLeft()->setParent(head);
			return;
		}
		//otherwise traverse left
		else{
			Node* left = head->getLeft();
			addNode(left, val);
		}
	}
}
void rotateLeft(Node* &head, Node* &parent){
	Node* pt_right = parent->getRight();
	parent->setRight(pt_right->getLeft());
	if(parent->getRight()!=NULL){
		parent->getRight()->setParent(parent);
	}
	pt_right->setParent(parent->getParent());
	if(parent->getParent() == NULL){
		head=pt_right;
	}
	else if(parent == parent->getParent()->getLeft()){
		parent->getParent()->setLeft(pt_right);
	}
	else{
		parent->getParent()->setRight(pt_right);
	}
	pt_right->setLeft(parent);
	parent->setParent(pt_right);
}
void rotateRight(Node* &root, Node* &parent){
	Node *pt_left = parent->getLeft();
	parent->setLeft(pt_left->getRight());
	if(parent->getLeft() != NULL){
		parent->getLeft()->setParent(parent);
	}
	pt_left->setParent(parent->getParent());
	if(parent->getParent() == NULL){
		root = pt_left;
	}
	else if(parent == parent->getParent()->getLeft()){
		parent->getParent()->setLeft(pt_left);
	}
	else{
		parent->getParent()->setRight(pt_left);
	}
	pt_left->setRight(parent);
	parent->setParent(pt_left);
}
