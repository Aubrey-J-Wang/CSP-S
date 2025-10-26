#include <bits/stdc++.h>
using namespace std;

int father[100001];

int FindFather(int n){
    if(father[n] == n){
        return n;
    }
    
    int f = FindFather(father[n]);
    father[n] = f;
    return f;
}

void Union(int u, int v){
    int a = FindFather(u);
    int b = FindFather(v);
    
	if(a == b) return;
    
	father[a] = b;
}

int main(){
    int n, k;
    cin >> n >> k;

    for(int i = 1;i <= n;i++){
        father[i] = i;
    }

    for(int i = 0;i < k;i++){
        int a, b, c;
        cin >> a >> b >> c;
        Union(a, b);
    }

    set<int> s;
    
    for(int i = 1;i <= n;i++){
        s.insert(FindFather(i));
    }

    cout << s.size();
    return 0;
}
