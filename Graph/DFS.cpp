#include<iostream>
#include<string>
#include<queue>


using namespace std;

struct list{
	int nodeNumber;
	struct list* next;
	list(int x=-1): nodeNumber(x), next(NULL){}
};

struct Node{
	string color;	
	int discover;								// -1000 means never
	int finish;
	int prevNode;								// -1 means NIL
	struct list* adjlist;		
	Node(string c="White", int x=-1000, int y=-1000, int p=-1):
		color(c), discover(x), finish(y), prevNode(p), adjlist(NULL) {}
};

class Graph {

	public:
	Node* array;
	int num;
	int time;
	Graph(int num1, int* edge1, int* edge2, int numEdge)
	{
		num=num1;
		time=0;
		array = new Node[num];
		for(int i=0; i<numEdge;i++)
			add_edge(edge1[i],edge2[i]);
		cout << "Graph is created, Graph : " <<endl;
		graph_display();
	}
	
	void add_edge(int start, int end)
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

	void graph_display()
	{
		for(int i=0; i<num;i++)	{
			cout << "Node " <<i << " : ";
			node_display(&array[i]) ;
			cout << endl;
		}
	}

	
	void DFS()
	{
		for(int i=0;i<num;i++){
			if(array[i].color=="White"){
				DFS_visit(i);
			}
		}
	}

	void DFS_visit(int u)
	{
		time=time+1;
		array[u].discover=time;
		cout<< "discover time of node " << u << " is " << time << endl;
		array[u].color="Grey";
		list* tmp=array[u].adjlist;
		while(tmp){
			if (array[tmp->nodeNumber].color=="White"){
				array[tmp->nodeNumber].prevNode=u;
				DFS_visit(tmp->nodeNumber);
			}
			tmp=tmp->next;
		}
		time=time+1;
		array[u].finish=time;
		cout<< "Finish time of node " << u << " is " << time << endl;
		array[u].color="Black";
	
	}	
	
	void prevNode_display()
	{	
		cout << endl;
		cout << "Previous Node of different nodes, Given node is -1; : " << endl;
		for(int i=0; i<num;i++)	{
			cout << "Node " <<i << " : " << array[i].prevNode << endl;
		}
	}

	void discover_display()
	{	
		cout << endl;
		cout << "Discover time of different nodes : " << endl;
		for(int i=0; i<num;i++)	{
			cout << "Node " <<i << " : " << array[i].discover << endl;
		}
	}

	void finish_display()
	{	
		cout << endl;
		cout << "Finish time of different nodes : " << endl;
		for(int i=0; i<num;i++)	{
			cout << "Node " <<i << " : " << array[i].finish << endl;
		}
	}

};

int main()
{
	int num =8;	
	int edge1[]={0,0,1,1,2,2,2,3,3,3,4,5,5,5,6,6,6,6,7,7};		//start nodes of the edge
	int edge2[]={4,1,0,5,3,5,6,2,6,7,0,1,2,6,5,2,3,7,3,6};		//end node of the edge
	Graph mygraph(num,edge1,edge2,sizeof(edge1)/sizeof(edge1[0])); // Create graph
	
	mygraph.DFS(); // Run DFS, no input
	mygraph.prevNode_display();//Display Predecessor
	mygraph.discover_display();//Display discover time
	mygraph.finish_display();//Display finish time

	return 0;
}
