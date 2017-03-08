#include <vector>
#include <iostream> 



/*
	choose a pivot, randomly or mid point,
	
	divide the array in a way that all element small than pivot are one side, 	
	and all elemesnt greater than pivot on the other side. 

*/




void quicksort(std::vector<int> &v, int start, int end);
void swap(int &i, int &j);
void print_array(std::vector<int> v);

int main()
{

	std::vector<int>  v={2,4,6,7,9,12,34,65, 1,3,5,2,34,56,87,3,22};
	print_array(v);
	quicksort(v,0,v.size()-1);
	print_array(v);
	return 0;

}


void quicksort(std::vector<int> &v, int start, int end){
	
	if(start>=end)
		return;

	int mid= (start+ end) /2;
	int i = start;
	int j = end;
	print_array(v);
	int pivot=v[mid];
	std::cout << "pivot : "	<< pivot << std::endl;
	while(i<=j){
		while(v[i]<pivot)
			i++;
		while(v[j]>pivot)
			j--;
		
		//swap v[i] and v[j]
 		if (i <= j) {
			swap(v[i],v[j]);
			i++;
			j--;
		}
	
	}
	
	quicksort(v,start, j);
	quicksort(v,i, end);
		
	
	
}

void swap(int &i, int &j){
	int tmp;
	tmp=i;
	i=j;
	j=tmp;
	return;

}









void print_array(std::vector<int> v){
	
	for(int i=0; i< v.size(); i++)
		std::cout << v[i] << " ";
	std:: cout<< std::endl;
}

