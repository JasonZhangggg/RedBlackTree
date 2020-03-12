#include <iostream>
#include "Node.h"

using namespace std;

void addNode(Node*&, int);
void traverse(Node*, int);
bool search(Node*, int);
void commands(Node*&);
int main(){
	Node* head = NULL;
	while(true){
		cout<<"Type ADD to add, PRINT to print, SEARCH to search for a value, QUIT to quit, and DELETE to delete a node"<<endl;
		char* input = new char();
		cin.getline(input, sizeof(input));
		for(int i = 0; i<sizeof(input); i++){
			input[i] = toupper(input[i]);
		}
		if(strcmp(input, "ADD") == 0){
			int val;
			cout<<"Enter the val you want to add: ";
			cin>>val;
			cin.ignore();
			addNode(head, val);
		}	
		else if(strcmp(input, "PRINT") == 0){
			traverse(head, 0);
		}
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
		else if(strcmp(input, "QUIT") == 0){
			return 0;
		}
	}
}
void addNode(Node* &head, int val){
	if(head == NULL){
		head = new Node(val);
		return;
	}
	if(head->getVal()>val){
		if(head->getRight() == NULL){
			head->setRight(new Node (val));
			return;
		}
		else{
			Node* right = head->getRight();
			addNode(right, val);
		}	
	}
	else{
		if(head->getLeft() == NULL){
			head->setLeft(new Node(val));
			return;
		}
		else{
			Node* left = head->getLeft();
			addNode(left, val);
		}
	}
}

bool search(Node* head, int val){
	cout<<val<<" "<<head->getVal()<<endl;
	if(head == NULL) return false;
	if(val == head->getVal()) return true;
	if(head->getVal()>val) return search(head->getRight(), val);
	else if(val<= head->getVal()) return search(head->getLeft(), val);
}

void traverse(Node* head, int depth){
	//recursivly go to the left branch
	if(head == NULL)return;
	if(head->getLeft() != NULL) traverse(head->getLeft(), depth+1);
	//print out spaces for formating depth number of times
	for (int i = 0; i < depth; i++) cout << "      ";
	//print out the actual value
	cout <<head->getVal()<< endl;
	//recursivly go to the right branch
	if(head->getRight() != NULL) traverse(head->getRight(), depth+1);
}
