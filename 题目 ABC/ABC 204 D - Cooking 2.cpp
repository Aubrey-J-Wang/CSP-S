//ABC 204 D - Cooking
//https://atcoder.jp/contests/abc204/tasks/abc204_d

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e6 + 5;
int num[N];
int dp[N];

int main(){
    int n;
    scanf("%d", &n);
    
	int sum = 0;
    
	for (int i = 1; i <= n;i++)
        scanf("%d", &num[i]), sum += num[i];
    
	if(n==1){
        printf("%d\n", num[1]);
        return 0;
    }
    
	dp[0] = 1;
    int temp = sum;
    sum /= 2;
    
	for (int i = 1; i <= n;i++)
        for (int j = sum; j >= num[i];j--)
            if(dp[j-num[i]]) dp[j] = 1;
    
	for (int i = sum; i >= 1;i--)
        if(dp[i]){
            printf("%d\n", temp - i);
            return 0;
        }
        
}


