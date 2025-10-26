//ABC 358 D - Souvenirs
//https://atcoder.jp/contests/abc358/tasks/abc358_d
//https://atcoder.jp/contests/abc358/submissions/54728498

#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    
	//freopen("input.txt", "r", stdin);
    
    int N,M;
    cin>>N>>M;
    int A[N];
    int B[M];
    
	for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
	for(int i=0;i<M;i++){
        cin>>B[i];
    }
    
	long long int ans = 0;
    
	sort(A,A+N);
    sort(B,B+M);
    
	int j=0;
    for(int i = 0; i<M; i++){
        while(B[i]>A[j] & j<N){
            j++;
        }
        ans += A[j];
        A[j] = -1;
        if(j==N){
            ans=-1;
            break;
        }
    }
    
	cout<<ans;
    return 0;
}


