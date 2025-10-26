//ABC 271 C - Manga
//https://atcoder.jp/contests/abc271/tasks/abc271_c
//https://atcoder.jp/contests/abc271/editorial/4943

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin>>N;
	
	vector<bool> vol(N+2,false);
	vector<int> a(N);
	
	int sold = 0;
	
	for(int i=0;i<N;i++){
		cin>>a[i];                    //3
		if(a[i]>=vol.size())sold++;   //1 2
		else if(vol[a[i]])sold++;
		else vol[a[i]] = true;
	}
	
	int L = 1;
	int R = N+1;
	
	while(true){    
		while(vol[L])L++;  //L=3   
		//1,2,3, ,5,6,7,8,9, , 11,12,13,  15,  20,.....
		while(R!=0 && !vol[R]) R--; //R   //R  //R
		if(sold>=2){
			sold-=2;
			vol[L] = true;//1,2,3,4, ,
		}
		else{
			if(L>=R)break;
			vol[R] = false;
			sold++;
		}
	}
	
	cout<<L-1<<endl;
	return 0;
}



