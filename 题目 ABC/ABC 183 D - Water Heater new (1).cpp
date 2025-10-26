//ABC 183 D - Water Heater, 差分 
//题目地址：https://atcoder.jp/contests/abc183/tasks/abc183_d
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll c[200010];

int main(){
	int n,w;
	cin >> n >> w;
	
	for(int i=0;i<n;i++){
		int s,t,p;
		cin >> s >> t >> p;    //3 11 x
		c[s] += p;             //5 21 y
		c[t] -= p;
	}
	
	for(int i=0;i<200005;i++){
		c[i+1] += c[i];
		if(c[i]>w){
			cout << "No";
			return 0;
		}
	}
	
	cout << "Yes";
	return 0;
}


