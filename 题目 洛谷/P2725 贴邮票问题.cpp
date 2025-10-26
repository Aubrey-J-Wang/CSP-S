//贴邮票问题，洛谷P2725，https://www.luogu.com.cn/problem/P2725
//题解：https://www.luogu.com.cn/problem/solution/P2725

#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
    int a[51]={},dp[2000001]={};;
    int i,j,k,n,m;

	while(scanf("%d%d",&k,&n)!=EOF){
        for(i=0;i<n;i++)
		   scanf("%d",&a[i]);

		sort(a,a+n);

		dp[0]=0;
        i=0;

		while(dp[i]<=k){
            i++;
            dp[i]=999999;
            for(j=0;j<n&&a[j]<=i;j++)
              if(dp[i-a[j]]+1<dp[i])
                dp[i]=dp[i-a[j]]+1;
        }

        printf("%d\n",i-1);
    }

    return 0;
}

