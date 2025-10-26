#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, total = 0;
	cin >> n;
	int a[n + 1];
	for(int i = 0; i <= n; i++) a[i] = 0;
	int p = 1, i = 0, s = 0;
	do{ 	 //Consider it a maze.
		i++; //Consider this a direction, consider p a step recorder.
		s += i;
		if (s <= n){  //If still needs nums or already needs printing.
			a[p] = i; //The num, or 'direction' is recorded.
			if(s == n){
				total++;
				if(p != 1){ //Print.
					cout << n << " = ";
					for(int i = 1; i <= p; i++){
						if(i != 1) cout << '+';
						cout << a[i];
					}
					cout << endl;
				}
				s -= a[p--] + a[p]; //Remove 2 nums. e.g. a[1, 1, 1, 1] -> a[1, 1], so we can add 2 : a[1, 1, 2].
				i = a[p];
			}else{
				i = a[p]-1; //We subtract by 1 to ensure that when i increases, it will be a[p] so we do not miss a case.
				p++;
			}
		}else{
			s -= i; //If not legitamate, we undo this step.
			s -= a[--p];
			i = a[p];
		}
	}while(p != 0); //Do while p not_eq to 0, i.e. we can still find other cases.
	cout << "Total:" << endl << total;
	return 0;
}