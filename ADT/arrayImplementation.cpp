/*
A simple program to implement list type by using array in c++.
This is implementing all the functions of list:
insert
delete
find
display
*/
#include<iostream>
#include<string.h>//to use string type

using namespace std;//to use standard macros like "cin" and "cout"

//declaration of functions
int insert_list(int integerList[],int size);

void display_list(int integerList[],int size);

int find(int integerList[],int position);

int delete_kth_element(int integerList[], int position,int size);

//main function to call all functionalities
int main(){
	int integerList[10]={0};//integerList of size 10
	int size=0;//to make size dynamic and avoid reading or displaying unapplied index's values
	string choice="";//set for asking choice of operation
	int position;//to send the position to find or delete in integer_list
	cout<<"1.Enter insert to insert element\n2.Enter display to display elements\n3.Enter delete to delete element\n4.Enter find to find element at any position\n5.Enter exit to quit";
	//The above is to display menu
	do{
		cout<<"\n\nnsertnsEnter your choice:";
		cin>>choice;
		if(choice == "insert"){
			size = insert_list(integerList,size);
		}
		else if(choice == "delete"){
			cout<<"Enter position from where you want to delete value";
			cin>>position;
			size = delete_kth_element(integerList,position,size);
		}
		else if(choice == "display"){
			display_list(integerList,size);
		}
		else if(choice == "find"){
			cout<<"Enter value of which key you want to find:";
			cin>>position;
			cout<<find(integerList,position);
		}
	}while(choice != "exit");//loop choice so user doesn't need to run program again and again
}

//function to insert element int integer_list created in main
int insert_list(int integerList[],int size){
	cout<<"Enter element:";
	cin>>integerList[size];
	size++;
	return size;//returns the size to maintain how many are inserted
}

//function to diplay all the valued inserted in integer_list created in main
void display_list(int integerList[],int size){
	if(size == 0){//if list is empty
		cout<<"List is empty\n";
	}
	else
	{
		cout<<"Elements:"<<endl;
		for(int index=0;index<size;index++){
			cout<<integerList[index]<<" ";
		}
	}
	cout<<"\n\n";
}

//function return the value at position
int find(int integerList[],int position){
	return integerList[position-1];
}

//function to delete value of kth position
int delete_kth_element(int integerList[],int position,int size){
	if(size < position){//to check is it already deleted or not
		cout<<"Value is already deleted or not exist\n";
	}
	else 
	{
		//if position you want to delete is less than size-1 and size is less than last index means values are only inserted to maximum 8th index
		if(position<size-1 && size < 9){
			for(int index=position-1;index<size;index++){
				integerList[index] = integerList[index+1];
			}
		}
		//position you want to delete is less than size-1 and data inserted till last index
		else if(position<size-1 && size == 9){
			for(int index=position-1;index<size-1;index++){
				integerList[index] = integerList[index+1];
			}
			integerList[size]=0;
		}
		//if you want to delete the last index's value
		else{
			integerList[size] = 0;
		}
		size--;//as one element is deleted size will be decreased by 1
	}
	return size;//to return new size
}
