#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node *next;

	Node(){
	data = 0;
	next = NULL;
    }
};
class LinkedList{
public:
	int length;
	Node *head;
	Node *tail;

	LinkedList(){
	head = NULL;
	tail = NULL;
	length = 0;
	}

void insertAtHead(int value){
	//Create pointer helper
	Node *helper;
	//Create new node
	helper = new Node;
	//Set data of head to value
	helper->data = value;
	//If there is nothing
	if (length == 0){
		head = helper;	
	}
	else{
	//Let helper point to head
	helper->next = head;
	//Let head point to helper
	head = helper;
	cout<<"Adding at head: "<<value<<endl;
	}
	length++;
}
void insertAtPosition(int position, int value){
	//Check if position is valid
	if (position >= 1 && position <= length + 1){
		//If it is at the head
		if (position == 1)
			insertAtHead(value);		
		else{
			Node *temp;
			Node *helper = new Node;
			helper->data = value;
			//Set temp to point to head
			temp = head;
			//Iterate until you get temp pointer to the position
			for (int i = 0; i < position - 1; i++){
				temp = temp->next;
			}
			//Bring helper to point to the same thing as temp
			helper->next = temp->next;	
			temp->next = helper;
			//Don't forget to increment length of list!!!!
			length++;	
		}
	}
    else
		cout<<"Position is invalid"<<endl;
	}
void removeFromPosition(int position){

	//Is position valid?
	if (position >= 1 && position <= length){
	
		//Removing from first node		
		if (position == 1){
			Node* helper;
			head = head->next;
			delete helper;
			length--;
		}
		//Removing from end
		else if (position == length){

			//Create temp pointer and have it look at head
			Node* temp;
			temp = head;

			while (temp->next != tail){
			temp = temp->next;
			}
			temp->next = NULL;
			delete temp->next;	
			tail = temp;
			length--;	
		}
		//Removing from middle
		else{
		Node *helper, *temp = head;
		//Move the pointer forward until you get to the position you are looking for
		for (int i = 1; i < position; i++){
			temp = helper;
			helper = helper->next;	
		}
		temp->next = helper->next;
		delete helper;
		length--;			
		}	
	}
	else {
	cout<<"This position does not exist. Please try again."<<endl;	
	}

}

void displayContents(){
	if (head == NULL){
	cout<<"Your List is Empty"<<endl;	
	}
	else{
	Node* temp;
	temp = head;
	while (temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	   }
	cout<<endl;	
	}

}
};


//Keep going until you get to the position
	//while (int i = 0 < position){
		//helper = head->next;
		//head->next = head->next;
		//if (head == NULL){
		//break;
	      //}
		//i++;
	//}

int main(){

 LinkedList L;
 int choice;
 int value;
 int position;
 while(1){
 cout<<"Welcome to Linked Lists. Please choose from the menu options: "<<endl;
 cout<<"1. Add at head \n"; 
 cout<<"2. Insert at position \n";
 cout<<"3. Remove at position \n";
 cout<<"4. Display contents \n";
 cin>>choice;
 switch(choice){
	 case (1):
		 cout<<"Enter value: "<<endl;
		 cin>>value;
		 L.insertAtHead(value);
		 break;
	 case (2):
		 cout<<"Insert at position: "<<endl;
		 cin>>position;
		 cout<<"Insert value: "<<endl;
		 cin>>value;
		 L.insertAtPosition(position, value);
		 break;
	case (3):
		cout<<"Remove at position: "<<endl;
		cin>>position;
		L.removeFromPosition(position);
		break;
	case (4):
		cout<<"Display contents: " <<endl;
		L.displayContents();
		break;
 }
}
 return 0;   
}



