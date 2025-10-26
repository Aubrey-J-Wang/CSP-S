/*
  Problem : openjudge 2.1节T1813
  Algorithm : 
  Status :
*/
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 10;
const int N = 5;
const int M = 6;

int a[MAXN][MAXN],tmp[MAXN][MAXN],ans[MAXN][MAXN];

void turn(int i,int j){
	tmp[i][j] ^= 1;
	tmp[i - 1][j] ^= 1;
	tmp[i + 1][j] ^= 1;
	tmp[i][j - 1] ^= 1;
	tmp[i][j + 1] ^= 1;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);

	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= M;j++)
		    scanf("%d",&a[i][j]);
	}
	
	for(int i = 0;i < (1 << M);i++){
		memcpy(tmp,a,sizeof(a));
		memset(ans,0,sizeof(ans));
		for(int j = 1;j <= M;j++){
			if((i >> (j - 1)) & 1){
			    turn(1,j);
			    ans[1][j] = 1;
			}
		}
		
		for(int j = 2;j <= N;j++){
			for(int k = 1;k <= M;k++){
				if(tmp[j - 1][k] == 1){
					turn(j,k);
					ans[j][k] = 1;
				}
			}
		}
		
		bool f = true;   //做一行看一行，或只看最后一行即可 
		for(int j = 1;j <= N && f;j++){
			for(int k = 1;k <= M;k++){
				if(tmp[j][k]){
					f = false;
					break;
				}
			}
		}
		
		if(f){
			for(int j = 1;j <= N;j++){
				for(int k = 1;k <= M;k++)
				    printf("%d ",ans[j][k]);
				printf("\n");
			}
		}
	}
	
	return 0;
}

