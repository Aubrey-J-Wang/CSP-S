//��Ŀ��Դ��CEOI2015 Day2 ������������
//��Ŀ��ַ��https://www.luogu.com.cn/problem/P4799
//��ⲩ�ͣ�https://www.cnblogs.com/ACMSN/p/10752201.html 

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

void dfs1(int step, int now){    //�������� 
    if (now>m) return;           //��֦ 
    
    if (step>mid) {              //����������ǰһ�뼴ͣ���� 
	   a.push_back(now); 
	   return;
	}
    
	dfs1(step+1, now+c[step]);   //ѡ 
    dfs1(step+1, now);           //��ѡ 
}

void dfs2(int step, int now){    //������һ�룬��ʵ������˫�򡪡�����������  
    if (now>m) return;           //��֦ 
    
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
    
	dfs1(1, 0);     //����ǰһ�룬���״̬�� a ������ 
	dfs2(mid+1, 0); //������һ�룬���״̬�� b ������ 
    
	sort(b.begin(), b.end());    //��״̬���򣨶��֣���״ѹ����ϣ��ʾ�� 
    
	for (int i:a) //for each  1 000 000
	   ans+=upper_bound(b.begin(), b.end(), m-i)-b.begin();
       //�� b �������ֲ���  20 ��
	    
	printf("%lld\n", ans);
    return 0;
}


