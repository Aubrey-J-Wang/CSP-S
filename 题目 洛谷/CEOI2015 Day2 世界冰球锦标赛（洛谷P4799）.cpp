//题目来源：CEOI2015 Day2 世界冰球锦标赛
//题目地址：https://www.luogu.com.cn/problem/P4799
//题解博客：https://www.cnblogs.com/ACMSN/p/10752201.html 

#pragma GCC optimize (2)
#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
#define rep(i, a, b) for (register int i=(a); i<=(b); ++i)
#define per(i, a, b) for (register int i=(a); i>=(b); --i)
using namespace std;

const int N=45;
vector<int> a, b;
int c[N], m, ans, n, mid;

inline int read(){
    int x=0,f=1;char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
    return x*f;
}

void dfs1(int step, int now){    //正向搜索 
    if (now>m) return;           //剪枝 
    
    if (step>mid) {              //正向搜索到前一半即停下来 
	   a.push_back(now); 
	   return;
	}
    
	dfs1(step+1, now+c[step]);   //选 
    dfs1(step+1, now);           //不选 
}

void dfs2(int step, int now){    //搜索后一半，其实并不是双向——分两段搜索  
    if (now>m) return;           //剪枝 
    
    if (step>n) {
	   b.push_back(now); 
	   return;
	}
    
	dfs2(step+1, now+c[step]);
    dfs2(step+1, now);
}

signed main(){
    n=read(); m=read(); 
	mid=n+1>>1;
	
    rep(i, 1, n) c[i]=read();
    
	dfs1(1, 0);     //搜索前一半，结果状态在 a 数组里 
	dfs2(mid+1, 0); //搜索后一半，结果状态在 b 数组里 
    
	sort(b.begin(), b.end());    //将状态排序（二分）、状压、哈希表示等 
    
	for (int i:a) //for each  1 000 000
	   ans+=upper_bound(b.begin(), b.end(), m-i)-b.begin();
       //在 b 中最多二分查找  20 次
	    
	printf("%lld\n", ans);
    return 0;
}


