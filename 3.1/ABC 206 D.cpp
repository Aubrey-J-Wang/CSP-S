#include <iostream>
using namespace std;

int father[200005];

int find(int u){ //Disjoint Set
	if(u == father[u]) return u;
	else father[u] = find(father[u]);
}

bool join(int u, int v){
	u = find(u);
	v = find(v);
	if(u == v) return false; //Already in set
	father[u] = v;
	return true;
}

int main() {
    ios::sync_with_stdio(false);
    
    int n, ans = 0;
    cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= 200003; i++) father[i] = i; //Initialize.
    
    for(int i = 1; i <= n/2; i++){
    	int j = n-i+1;
    	if(a[i] == a[j]) continue;
    	else ans += join(a[i], a[j]); //If two numbers need to be changed, add together to the disjoint set.
//    	If not in set before, we consider this as ONE operation.
	}
	cout << ans;
	return 0;
}
