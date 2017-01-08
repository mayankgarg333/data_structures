#include<iostream>
#include<string>


using namespace std;

struct Node{
	int number;
	struct 	Node* next;
	
	Node(int x=0): number(x), next(NULL){}
};

class Queue{
	public:
		Node* start,*end;		
		int size;
		Queue(){
			start=NULL;
			end=NULL;
			size=0;
		}
		
		void Add(int data){
			if(size==0){
				start=new Node;
				start->number=data;
				end=start;
				size++;
			}
			else{
				Node* tmp=new Node;
				tmp->number=data;
				end->next=tmp;
				end=end->next;
				size++;
			}
		}

		int Remove(){
			if(size==0)
				return -1;
			else {
				int tmpData=start->number;
				start=start->next;
				size--;
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
	Queue firstQueue;
	while(true){
	
		cout << "Press 1 to Add, 2 to Remove, 3 to top and 4 to show the Queue" << endl;	
		cin >> input;
		if(input==1){
			cout << "Enter the number to Add" << endl;
			cin >> data;
			firstQueue.Add(data);
		}
		if(input==2){
			data=firstQueue.Remove();
			cout << "Removeed number is " << data << endl;
		}
		if(input==3){
			data=firstQueue.top();
			cout << "Top number is " << data << endl;
		}
		if(input==4){
			cout << "Whole Queue is :" << endl;
			firstQueue.show();
		}
		
	}


	return 0;
}
