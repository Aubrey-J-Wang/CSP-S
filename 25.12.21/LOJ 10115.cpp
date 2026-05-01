//https://loj.ac/p/10115
//https://loj.ac/problem/10115

#include <bits/stdc++.h>
using namespace std;

int const N = 50000 + 10;
int c1[N],c2[N];
int n,m;

int lowbit(int x){
    return x & -x;
}

void add(int c[N],int i){
    while(i <= n){
        c[i]++;
        i += lowbit(i);
    }
}

int getsum(int c[N],int i){
    int s = 0;
    while(i > 0){
        s += c[i];
        i -= lowbit(i);
    }

    return s;
}

int main(){
    int k,x,y;
    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&k,&x,&y);	//3~7
        if(k == 1){
            add(c1,x), add(c2,y);
            //c1记录左括号的个数，c2记录右括号的个数
        }
        else{ //3~7
            printf("%d\n",getsum(c1,y) - getsum(c2,x-1));
        }

    }

    return 0;
}