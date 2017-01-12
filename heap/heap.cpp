/*
	C++ MAX HEAP IMPLEMENTATION 
*/


#include<iostream>
#include<vector>
#include<cmath>

class BinaryHeap
{

	/*  What operations should be public
		User wants
			to insert an element to heap -- insert(int value)
			to extract max of the heap, which will be the root (first element) -- extract_max()
			to delete max value -- delete_max() will delete the root
			to know the size of heap (not necessary)
			to display the heap (will be displayed as vector)
	*/
	public:						
		BinaryHeap(){}
		void insert(int val);
		int extract_max();
		void delete_max();	
		int heap_size();
		void display_heap();		

	private:
		std::vector <int> heap_vec;
		int left(int);
		int right(int);
		int parent(int);
		
		/* two methods are required more internal heap operation
			first: max_heap_up(int i) - this method will take the index i and make sure that 
			value moves upward to its right place by compring to its parents.
			second: max_heap_down(int i) - same, value will move downwards to its right place	
			both function will be log(n)
		*/
		void max_heap_up(int i); 
		void max_heap_down(int i);

				
		
		

};


int BinaryHeap::heap_size(){
	return heap_vec.size();
}


void BinaryHeap::insert(int val)
{
	heap_vec.push_back(val);
	max_heap_up(heap_vec.size()-1);
}


int BinaryHeap:: extract_max()
{
	if(heap_vec.size()>0)
		return heap_vec[0];
	else	
	    std::cout << "Heap is empty" << std::endl;
	return -1;
}


void BinaryHeap:: delete_max()
{
	if(heap_vec.size()>0){
		heap_vec[0]=heap_vec[heap_vec.size()];
		heap_vec.pop_back();
		max_heap_down(0);
	}
}


void BinaryHeap:: display_heap()
{
	std::cout << "HEAP is : " << std::endl;
	for(int i=0; i<heap_vec.size(); i++)
	{
		std::cout << heap_vec[i] << " ";
	}
	std::cout << std::endl;	
}


int BinaryHeap:: left(int i)
{
	return 2*(i+1)-1;
}

int BinaryHeap:: right(int i)
{
	return 2*(i+1);
}

int BinaryHeap:: parent(int i)
{
	return floor((i-1)/2);
	
}


/*this method will take the index i and make sure that 
			value moves upward to its right place by compring to its parents.*/

void BinaryHeap:: max_heap_up(int i)
{
	if(i==0)
		return; // you have reached parent, no where to go
	int tmp;
	int p=parent(i);
	// if parent of i is less than i, then swap and change i to parent of i, else break,
	if(heap_vec[p]<heap_vec[i])
	{
		tmp = heap_vec[i];
		heap_vec[i]=heap_vec[p];
		heap_vec[p]=tmp;
		max_heap_up(p);
	}

}


void BinaryHeap:: max_heap_down(int i)
{
	
	if(heap_vec.size()<=left(i))
		return; 	// reached leaf
		
	// move down till reaches to the leaf or a right place in between 

	int tmp, p, m; // m holds the maximum element index in the children
	// get the maximum child
		if(heap_vec.size()>right(i)) // if right child exists
			m=heap_vec[left(i)]>heap_vec[right(i)]?left(i):right(i);
		else
			m=left(i);
	// check and replace if i is less than the maximum 
		if(heap_vec[i]<heap_vec[m])
		{
			tmp = heap_vec[i];
			heap_vec[i]=heap_vec[m];
			heap_vec[m]=tmp;	
			max_heap_down(m);
		}
}


int main()
{

	BinaryHeap heap;

	heap.display_heap();
	heap.insert(4);
	heap.insert(5);
	heap.insert(6);
	heap.display_heap();
	heap.insert(4);
	heap.insert(5);
	heap.insert(6);
	heap.insert(4);
	heap.insert(5);
	heap.insert(6);
	heap.display_heap();

	return 0;
}































































