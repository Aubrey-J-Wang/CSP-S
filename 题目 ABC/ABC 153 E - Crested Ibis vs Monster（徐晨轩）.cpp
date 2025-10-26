//ABC 153 E - Crested Ibis vs Monster

#include <bits/stdc++.h>
using namespace std;

const int N=20001;
int h,n,a,b,f[N];

int main(){
	memset(f,0x3f,sizeof f);
	f[0]=0;
	cin >> h >> n;
	
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		for(int j=0;j+a<=20000;j++)
			f[j+a]=min(f[j+a],f[j]+b);
    }
    
	cout << *min_element(&f[h],&f[20000]+1);
	return 0;
}



