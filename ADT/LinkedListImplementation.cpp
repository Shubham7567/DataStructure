/*
This one is the program of implementing List by Linked List.
In this we created this to insert at top in linked list.
Just insert and display all elements.
*/
#include<iostream>
#include<conio.h>

using namespace std;
//class no for storing data of elements of linked list
class node
{
	//data of node
	int data;
	string name;
public:
	//this will point to next node
	node* next;
	//function to set data as it is private
	void set_data(int value){
		this->data = value;
	}
	//function to set name as it is private
	void set_name(string name){
		this->name = name;
	}
	
	//function to get data as it is private
	int get_data(){
		return this->data;
	}
	
	//function to get name as it is private
	string get_name(){
		return this->name;
	}
};

//function to insert new node in list
void insert(node** top){
	node* n1 = new node();//new node
	int data;
	string name;
	cout<<"Enter data:";
	cin>>data;
	n1->set_data(data);
	
	cout<<"Enter name:";
	cin>>name;
	n1->set_name(name);
	//to set newnode at top
	n1->next = *top;
	*top = n1;
}
//function to display all the elements of linked list start from top which is the last added
void display(node** top){
	int count=1;
	node* current;
	current = *top;
	while(current != NULL){
		cout<<count<<". node data"<<endl;
		cout<<"data : "<<current->get_data()<<endl;
		cout<<"name : "<<current->get_name()<<endl;
		cout<<"\n\n";
		current = current->next;
		count++;
	}
}

int main(){
	node* top = NULL;//to start the linked list
	//calling the insert function
	insert(&top);
	insert(&top);
	insert(&top);
	insert(&top);
	
	display(&top);
	return 0;	
}
