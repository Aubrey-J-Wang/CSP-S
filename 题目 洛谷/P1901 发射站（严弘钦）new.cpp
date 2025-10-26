#include <bits/stdc++.h>
using namespace std;

const int N=1000010;
int n,ans,h[N],v[N],x[N],pos[N],top;
stack<int> s, t;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++)
    	cin >> h[i] >> v[i];
    
	for(int i=1; i<=n; i++) {
		while(!s.empty() && h[s.top()]<=h[i]) 
			s.pop();
			
		if (!s.empty()) x[s.top()]+=v[i];
	    
		s.push(i); 
	} 
	
    for(int i=n; i>=1; i--) {
		while(!s.empty() && h[s.top()]<=h[i]) 
			s.pop();
		x[pos[s.size()]]+=v[i];
	    s.push(h[i]); 
		pos[s.size()]=i;
	}
	
    for(int i=1; i<=n; i++) 
		ans=max(ans,x[i]);
    
	cout << ans << endl;
    return 0;
}
