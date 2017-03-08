#include <vector>
#include <iostream> 




/*
	a vector : split in half // get to sorted half // merge them
	
	two functions are required, One which will split the vector in halfs, and one which we stich it back
	merge sort require extra memory for merge operation. 
	
*/

void mergesort(std::vector<int> &v, int start, int end);
void merge(std::vector<int> &v, int start, int mid, int end);
void print_array(std::vector<int> v);

int main()
{

	std::vector<int>  v={2,4,6,7,9,12,34,65, 1,3,5,2,34,56,87,3,22};
	print_array(v);
	mergesort(v,0,v.size()-1);
	print_array(v);
	return 0;

}


void mergesort(std::vector<int> &v, int start, int end){
	
	if(start<end){
	
	int mid = (start+ end)/2;
	mergesort(v,start,mid);
	mergesort(v,mid+1,end);
	merge(v, start, mid, end);
	}

	return;

}

void merge(std::vector<int> &v, int start, int mid, int end){

	std::vector<int> tmp;
	
	int i= start;  // index for first half of the array
	int j= mid+1;  // index for second half of the array
	
	while(i<=mid && j<=end){
	
		if(v[i]<v[j]){
			tmp.push_back(v[i]);
			i++;
		}
		else{
			tmp.push_back(v[j]);
			j++;
		}
		
	}

	while(i<=mid){
			tmp.push_back(v[i]);
			i++;
	}

	while(j<=end){
			tmp.push_back(v[j]);
			j++;
	}
	
	for(int k=0; k<tmp.size(); k++){
		v[start+k]=tmp[k];
	}
	
	return;

}



void print_array(std::vector<int> v){
	
	for(int i=0; i< v.size(); i++)
		std::cout << v[i] << " ";
	std:: cout<< std::endl;
}





