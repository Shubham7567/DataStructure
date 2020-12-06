#include<iostream>
#include<string.h>

using namespace std;

int insert_list(int integerList[],int size);

void display_list(int integerList[],int size);

int find(int integerList[],int position);

int delete_kth_element(int integerList[], int position,int size);

int main(){
	int integerList[10]={0};//integerList of size 10
	int size=0;
	string choice="";
	int position;
	cout<<"1.Enter insert to insert element\n2.Enter display to display elements\n3.Enter delete to delete element\n4.Enter find to find element at any position\n5.Enter exit to quit";
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
	}while(choice != "exit");
}

int insert_list(int integerList[],int size){
	cout<<"Enter element:";
	cin>>integerList[size];
	size++;
	return size;
}

void display_list(int integerList[],int size){
	if(size == 0){
		cout<<"List is empty";
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

int find(int integerList[],int position){
	return integerList[position-1];
}

int delete_kth_element(int integerList[],int position,int size){
	for(int index=position-1;index<size;index++){
		integerList[index] = integerList[index+1];
	}
	size--;
	return size;
}
