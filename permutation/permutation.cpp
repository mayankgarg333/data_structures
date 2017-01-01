#include<iostream>
#include<string>
#include <algorithm>    // std::sort

using namespace std;

void swap(char *a, char *b){
	char tmp = *a;
	*a=*b;
	*b=tmp;
	return;
}

// if there is any duplicate element, more care is required // Broken code
// need to stop all braches but one for common swap values
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

void get_permutation_dup2(string str, int s, int e){ // will take sorted string only, doesn't matter here as we are printing all permutations
	
	if(s==e){
		cout << str << endl;
		return; 
	}
	
	for (int i=s; i<=e;i++){
		if(i==s){
			get_permutation_dup2(str,s+1,e); // one branch will continue
			continue;
		}
		if(str[i-1]!=str[i]){					// if char are same, it will not create new permuation, so create branch only if charcaters are different
												// to remove the sorted input constrain we need save all string charcerters issued by this loop and copmare with them, using hash may be
												// bit can also be used for storage if possible char are limited. 
			swap(&str[s],&str[i]);
			get_permutation_dup2(str,s+1,e);
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
	string str="31233";
	string s2=str;
	sort(s2.begin(), s2.end());
	cout << "Original string: " << str <<endl;
	cout << "Permutations: " <<endl;
	get_permutation_dup2(s2,0,str.size()-1);
	cout << "Original string: " << str <<endl;
	return 	0;
}
