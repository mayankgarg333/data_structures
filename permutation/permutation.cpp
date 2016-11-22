#include<iostream>
#include<string>

using namespace std;

void swap(char *a, char *b){
	char tmp = *a;
	*a=*b;
	*b=tmp;
	return;
}

// if there is any duplicate element, more care is required
void get_permutation_dup(string str, int s, int e){
	
	if(s==e){
		cout << str << endl;
		return; 
	}
	
	for (int i=s; i<=e;i++){
		if(i==s){
			get_permutation_dup(str,s+1,e); // one branch will continue
			continue;
		}
		if(str[s]!=str[i]){					// if char are same, it will not create new permuation, so create branch only if charcaters are different
			swap(&str[s],&str[i]);
			get_permutation_dup(str,s+1,e);
			swap(&str[i],&str[s]);
		}
	}
	
	return;
}


// if there is no duplicate charcater,
void get_permutation(string str, int s, int e){
	
	if(s==e){
		cout << str << endl;
		return; 
	}
	
	for (int i=s; i<=e;i++){
		swap(&str[s],&str[i]);
		get_permutation(str,s+1,e);
		swap(&str[i],&str[s]);
	}
	
	return;
}


int main()
{
	string str="are";
	get_permutation_dup(str,0,str.size()-1);
	return 	0;
}
