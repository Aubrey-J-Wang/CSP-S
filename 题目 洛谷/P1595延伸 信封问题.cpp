#include<bits/stdc++.h>//在输入超过12时会TLE 
using namespace std;
int n, s;
int main(){
	cin >> n;
	int a[n];
	for(int i = 1; i <= n; i++) a[i-1] = i;
	do{
		bool f = true;
		for(int i = 0; i < n; i++){
			if(a[i] == i+1){
				f = false;
				break;
			}	
		}
		if(f){
			s++;
			for(int i = 0; i < n; i++) cout << a[i] << ' ';
			cout << endl;
		}
	}while( next_permutation(a, a+n) );
	cout << s;
	return 0;
}

