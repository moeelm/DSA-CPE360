#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;
	//My constructor
	Node(){
		data = 0;
		next = NULL;
	}
};

class Queue{
private:
	Node *head;
public:
	Queue(){
		head = NULL;
	}
	void enqueue(int data){
		//If my queue is empty
		if (head == NULL){
			Node *helper;
			helper = new Node;
			helper->data = data;
		//Ground this new piece
			helper->next = NULL;
			head = helper;
			}
		else{
		//Add the new node, have it point to head, then have head point to helper (the new Node)
			Node *helper = new Node;
			helper->data = 	data;
			helper->next = head;
			head = helper;
		}
	}
	int dequeue(){
		Node *current = head;
		Node *prev = NULL;
		int value = current->data;
		//Check if there's nothing to pop
		if (head == NULL){
		cout<<"Nothing to pop!"<<endl;
		return 0;	
		}
		while(current->next != NULL){
			prev = current;
			current = current->next;		
		}
		if (prev == NULL){
			delete current;
			head = NULL;
			return value;
		}
		prev->next = NULL;
		delete current;
		return value;
	}

	void printContents(){
	Node *helper;
	helper = head;
	while(helper != NULL){
	cout<<helper->data<<" ";
	helper = helper->next;
	}
	cout<<endl;
	}
};


int main(){

Queue q;
int choice;
int value;
while(1){

cout<<"Welcome to the queue.\n";
cout<<"1. Add to the queue.\n";
cout<<"2. Remove from the queue.\n";
cout<<"3. Show me what's inside the queue.\n";
cin>>choice;


switch(choice){
case (1):
	cout<<"Add to the queue: "<<endl;
	cin>>value;
	q.enqueue(value);
	break;
case (2):
	cout<<"Remove from queue: "<<endl;
	q.dequeue();
	break;
case(3):
	cout<<"Display contents of queue: "<<endl;
	q.printContents();
	break;
}

}

return 0;
}
