#include<iostream>
#include<string>


using namespace std;

struct Node{
	int number;
	struct 	Node* next;
	
	Node(int x=0): number(x), next(NULL){}
};

class Stack{
	public:
		Node* start;		
		int size;
		Stack(){
			start=NULL;
			size=0;
		}
		
		void push(int data){
			if(size==0){
				start=new Node;
				start->number=data;
				size++;
			}
			else{
				Node* tmp=new Node;
				tmp->next=start;
				tmp->number=data;
				start=tmp;
				size++;
			}
		}

		int pop(){
			if(size==0)
				return -1;
			else {
				int tmpData=start->number;
				Node* tmp;
				tmp=start;
				start=tmp->next;
				size--;
				delete tmp;
				return tmpData;
			}
		}

		int top(){
			if(size==0)
				return -1;
			else
				return start->number;
		}

		void show(){
			Node *tmp=start;
			for (int i=0; i<size;i++){
				cout<< " -> " << tmp->number ;
				tmp=tmp->next;
			}		
			cout << endl;

		}
	

		

};

int main()
{
	int input,data;		
	Stack firstStack;
	while(true){
	
		cout << "Press 1 to push, 2 to pop, 3 to top and 4 to show the Stack" << endl;	
		cin >> input;
		if(input==1){
			cout << "Enter the number to push" << endl;
			cin >> data;
			firstStack.push(data);
		}
		if(input==2){
			data=firstStack.pop();
			cout << "Poped number is " << data << endl;
		}
		if(input==3){
			data=firstStack.top();
			cout << "Top number is " << data << endl;
		}
		if(input==4){
			cout << "Whole stack is :" << endl;
			firstStack.show();
		}
		
	}


	return 0;
}
