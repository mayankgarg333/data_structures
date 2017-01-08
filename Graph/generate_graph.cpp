#include<iostream>
#include<string>

using namespace std;

struct list{
	int nodeNumber;
	struct list* next;
	list(int x=-1): nodeNumber(x), next(NULL){}
};

struct Node{
	string color;	
	int distance;								// 1000 means infinity
	int prevNode;								// -1 means NIL
	struct list* adjlist;		
	Node(string c="White", int x=1000, int p=-1):
		color(c), distance(x), prevNode(p), adjlist(NULL) {}
};

void add_edge(Node* array,int start, int end)
{

	if(array[start].adjlist==NULL){
		array[start].adjlist = new list(end);
		return;
	}
	list *tmp=array[start].adjlist;
	while(tmp->next)						// Important: LOOP on tmp->next, not on tmp
		tmp=tmp->next;
	tmp->next=new list(end);
	return;
	
}

void node_display(Node* n)
{	
	list* tmp = n->adjlist;
	while(tmp){
		cout<< tmp->nodeNumber << " ";
		tmp=tmp->next;
	}
}

void graph_display(Node* array, int num)
{
	for(int i=0; i<num;i++)	{
		cout << "Node " <<i << " : ";
		node_display(&array[i]) ;
		cout << endl;
	}
}

int main()
{
	int num =8;	
	Node* array = new Node[num];
	int edge1[]={0,0,1,1,2,2,2,3,3,3,4,5,5,5,6,6,6,6,7,7};		//start nodes of the edge
	int edge2[]={4,1,0,5,3,5,6,2,6,7,0,1,2,6,5,2,3,7,3,6};		//end node of the edge
	int numEdge=sizeof(edge1)/sizeof(edge1[0]);	

	for(int i=0; i<numEdge;i++)
		add_edge(array,edge1[i],edge2[i]);
	
	graph_display(array,num);
	


	return 0;
}
