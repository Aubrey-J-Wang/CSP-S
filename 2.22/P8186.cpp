#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int a[n+1][n+1], change[n+1][n+1] = {0};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j]; //Object j = 1 ... n : Most desirable ... Least desirable
		}
	}
	
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		change[i][a[i][j]] = true; //Mark a[i][j] as 'desirable for changing' to i.
    		if(a[i][j] == i) break; //Stop when coming across i itself as 'desirable' for everything after this is less desirable
//    		but still needs changing, therefore considered 'a waste of time'.
		}
	}
	
	for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		for(int k = 1; k <= n; k++){
				if(change[j][i] && change[i][k]) change[j][k] = 1; //If j wants to change for i and i wants to change for k, then
//				k will be appropriately changed for j. (Obviously as j desires)
//				i changes with k
//				j changes with k (Because i will already be in k's posession)
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(change[i][a[i][j]] && change[a[i][j]][i]){
//				When both parties desire to change the present for the one in another's posession, swap the presents.
				cout << a[i][j] << endl;
				break; //And stop searching less desirable presents.
			}
		}
	}
	return 0;
}