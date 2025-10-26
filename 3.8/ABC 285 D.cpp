#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

string s[200010], t[200010];
map<string, string> father;

string find(string x){
	if(x == father[x]) return x;
	else father[x] = find(father[x])
}

bool join(string x, string y){
	x = find(x);
	y = find(y);
	
	if(x == y) return false;
	else{
		f[y] = x;
		return true;
	}
}

long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main() {
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> s[i] >> t[i];
    
    for(int i = 1; i <= n; i++){
    	father[s[i]] = s[i];
    	father[t[i]] = t[i];
	}
	
	for(int i = 1; i <= n; i++){
		if(!join(s[i], t[i])){
			cout << "No";
			return 0;
		}
	}
	
	cout << "Yes";
	return 0;
}
