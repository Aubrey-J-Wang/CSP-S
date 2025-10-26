#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, na, nb;
	cin >> n >> na >> nb;
	int a[na], b[nb], wa = 0, wb = 0;
	for(int i = 0; i < na; i++) cin >> a[i];
	for(int i = 0; i < nb; i++) cin >> b[i];
	for(int i = 0; i < n; i++){
		int ta = a[i%na], tb = b[i%nb];
		if((ta < tb && tb-ta != 5) || ta-tb == 5) wa++;
		else if(ta != tb) wb++;
	}
	if(wa > wb){
		cout << 'A';
	}else if(wa == wb){
		cout << "draw";
	}else cout << 'B';
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
def func main(){
	def int n, int na, int nb;
	def int arr a[na], int arr b[nb], int wa = 0, int wb = 0;
	for loop(first def int i = 0; 
*/
