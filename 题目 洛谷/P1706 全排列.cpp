#include<bits/stdc++.h>
using namespace std;
int a[10], n;
void gener(int k){ //This func does nearly everything!
	int i;
	if(k > n){ //If all elements are certain, print and return.
		for(i = 1; i <= n; i++) printf("%5d", a[i]);
		cout << endl;
	}else{
		for(i = 1; i <= n; i++){
			int f = false; //Find if the num is used.
			for(int j = 1; j < k; j++){
				if(a[j] == i) f = true ;
			}
			if(!f){
				a[k] = i; //If not (used), record into array a.
				gener(k+1); //Search for the other elements. When finally, the array is printed and
						    //the func returns, it will continue searching, just like the 'maze prob'.
			}
		}
	}
	return;
}
int main(){
	cin >> n;
	gener(1);
	return 0;
}
