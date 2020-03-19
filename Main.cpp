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

void addNode(Node*&, int, Node*);
void traverse(Node*, int);
bool search(Node*, int);
void deleteNode(Node*&, int, Node*&, int);
Node* minVal(Node*);
int main(){
	//declare head
	Node* head = NULL;
	char inType;
	char input[100];
	//ask for input type
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
		addNode(head, atoi(list), NULL);
		list = strtok(NULL, " ");
	}
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
			addNode(head, val, NULL);
		}	
		//display tree
		else if(strcmp(input, "PRINT") == 0){
			traverse(head, 0);
		}
		//search for a node
		else if(strcmp(input, "SEARCH") == 0){
			int val;
			cout<<"Enter the value you want to search for: ";	
			cin>>val;
			cin.ignore();
			if(search(head, val) == 1){
				cout<<"The node was found"<<endl;
			}
			else{
				cout<<"The node was not found"<<endl;
			}
		}
		//delete a node
		else if(strcmp(input, "DELETE") == 0){
			int val;
			cout<<"Enter the value you want to delete: ";
			cin>>val;
			cin.ignore();
			deleteNode(head, val, head, -1);
		}
		else if(strcmp(input, "QUIT") == 0){
			return 0;
		}
		cout<<endl<<"__________________________________________________________________________________________________"<<endl;
	}
}
void addNode(Node* &head, int val, Node* parent){
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
			return;
		}
		//else recursivly traverse right
		else{
			Node* right = head->getRight();
			addNode(right, val, head);
		}	
	}
	//if input val is smaller then head
	else{
		//if we are at the end of the tree, add the node to the left of the current node
		if(head->getLeft() == NULL){
			head->setLeft(new Node(val));
			return;
		}
		//otherwise traverse left
		else{
			Node* left = head->getLeft();
			addNode(left, val, head);
		}
	}
}
//search for a node
bool search(Node* head, int val){
	//if tree is empty or we reached the end, return false
	if(head == NULL) return false;
	//if we found the value return true
	if(head->getVal() == val) return true;
	//if the input value is less then the current value, recursivly traverse right
	if(head->getVal()<val) return search(head->getRight(), val);
	//if the input value is greater then the current value, recursivly traverse left
	else if(val< head->getVal()) return search(head->getLeft(), val);
}

void traverse(Node* head, int depth){
	//recursivly go to the left branch
	if(head == NULL)return;
	if(head->getRight() != NULL) traverse(head->getRight(), depth+1);
	//print out spaces for formating depth number of times
	for (int i = 0; i < depth; i++) cout << "      ";
	//print out the actual value
	cout <<head->getVal()<< endl;
	//recursivly go to the right branch
	if(head->getLeft() != NULL) traverse(head->getLeft(), depth+1);
}
//dir = 0: right
//dir = 1: left
void deleteNode(Node*&head, int val, Node*& parent, int dir){
	//if tree is empty return
	if(head == NULL) return;
	//recursivly traverse until we find the node we are looking for
	if(val>head->getVal()){
		Node* right = head->getRight();
		deleteNode(right, val, head, 0);
	}
	else if(val<head->getVal()){
		Node* left = head->getLeft();
		deleteNode(left, val, head, 1);
	}
	else{
		//if the node has no children
		if(head->getLeft() == NULL && head->getRight() == NULL){
			//not the root node
			if(parent != head){
				//set the parent node's value to NULL
				if(dir == 1){
					parent->setLeft(NULL);
				}
				else{
					parent->setRight(NULL);
				}
			}
			//delete
			delete head;
			head = NULL;
			return;

		}
		//if there is one child
		else if(head->getLeft() == NULL){
			Node* temp = head->getRight();
			//check if the node has a parent
			if(parent != head){
				//if so, set the parent node's value to NULL
				if(dir == 0){
					parent->setRight(temp);
				}
				else{
					parent->setLeft(temp);
				}
			}
			//delete
			delete head;
			head = temp;
			return;
		}
		//same thing but for the right branch
		else if(head->getRight() == NULL){
			Node* temp = head->getLeft();
			if(parent != head){
				if(dir == 1){
					parent->setLeft(temp);
				}
				else{
					parent->setRight(temp);
				}
			}

			delete head;
			head = temp;
			return;
		}
		//the node has 2 children
		else{
			//get the inorder sucsesor
			Node* right = head->getRight();
			Node* suc = minVal(right);
			//swap the value of the inorder sucsesor and the value we are deleting
			head->setVal(suc->getVal());
			//delete the inorder sucsesor
			deleteNode(right, suc->getVal(), head, 0);
		}
	}
	return;
}
Node* minVal(Node* head){
	//recursivly loop thourgh until we reach the left most part of the tree(smallest val)
	if(head->getLeft() == NULL){
		return head;
	}
	minVal(head->getLeft());
}
