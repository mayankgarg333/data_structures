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
	int distance;								// 1000 means infinity
	int prevNode;								// -1 means NIL
	struct list* adjlist;		
	Node(string c="White", int x=1000, int p=-1):
		color(c), distance(x), prevNode(p), adjlist(NULL) {}
};

class Graph {

	public:
	Node* array;
	int num;
	Graph(int num1, int* edge1, int* edge2, int numEdge)
	{
		num=num1;
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

	void BFS(int nodeNum)
	{
		queue <int> myqueue; 			//Queue to keep nodes to be visited
		array[nodeNum].color="Grey";
		array[nodeNum].distance=0;
		myqueue.push(nodeNum);
		while(!myqueue.empty())
		{
			int u=myqueue.front();
			// look at the adjlist of u 
			list* tmp=array[u].adjlist;
			while(tmp){
				if (array[tmp->nodeNumber].color=="White"){
					//make color grey
					array[tmp->nodeNumber].color="Grey";
					array[tmp->nodeNumber].distance=array[u].distance+1;
					array[tmp->nodeNumber].prevNode=u;
					myqueue.push(tmp->nodeNumber);
				}
				tmp=tmp->next;
			}
			myqueue.pop();
			array[u].color="Black";
		}
	}

	void distance_display()
	{	
		cout << endl;
		cout << "Distance of different nodes from given node : " << endl;
		for(int i=0; i<num;i++)	{
			cout << "Node " <<i << " : " << array[i].distance << endl;
		}
	}

	void prevNode_display()
	{	
		cout << endl;
		cout << "Previous Node of different nodes, Given node is -1; : " << endl;
		for(int i=0; i<num;i++)	{
			cout << "Node " <<i << " : " << array[i].prevNode << endl;
		}
	}

};

int main()
{
	int num =8;	
	int edge1[]={0,0,1,1,2,2,2,3,3,3,4,5,5,5,6,6,6,6,7,7};		//start nodes of the edge
	int edge2[]={4,1,0,5,3,5,6,2,6,7,0,1,2,6,5,2,3,7,3,6};		//end node of the edge
	Graph mygraph(num,edge1,edge2,sizeof(edge1)/sizeof(edge1[0])); // Create graph

	mygraph.BFS(1);		// Run BFS, input: node number to start
	mygraph.distance_display();//Display distance
	mygraph.prevNode_display();//Display Predecessor


	return 0;
}
