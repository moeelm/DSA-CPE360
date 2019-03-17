#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
	Node(){
		next = NULL;
		data = 0;
	}
};

class Stack{
private:
	Node *head;
public:
	Stack(){
	head = NULL;	
	}

	void push (int data){
	Node *add = new Node;
	add->data = data;
	add->next = head;
	head = add;
	}

	int pop(){
		//If stack is empty
		if (head == NULL){
			cout<<"Nothing to pop"<<endl;
			return 0;
		}
		else{
			//We pop from the top in a stack
			int value = head->data;
			//Create a delete pointer
			Node *del = head;	
			head = head->next;
			delete del;
			return value;
		}
	}

	void displayContents(){
	Node *helper = head;
	while (helper != NULL){
	cout<<helper->data<<" ";
	helper = helper->next;
	}
	cout<<endl;

}
};


int main(){
	Stack s;
	int choice;
	int value;
	while(1){
	cout<<"Welcome to the stack!\n";
	cout<<"1. Push to the stack\n";
	cout<<"2. Pop from the stack\n";
	cout<<"3. Display what's in the stack\n";
	cin>>choice;
	switch(choice){

	case (1):
		cout<<"Enter value: "<<endl;
		cin>>value;
		s.push(value);
		break;
	case (2):
		s.pop();
		cout<<"Popping is done"<<endl;
		break;
	case (3):
		cout<<"What's in the stack"<<endl;
		s.displayContents();
		break;
}
	
	
}


return 0;
}
