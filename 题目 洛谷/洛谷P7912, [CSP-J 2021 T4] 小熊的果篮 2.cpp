//洛谷P7912, [CSP-J 2021 T4] 小熊的果篮 
//https://www.luogu.com.cn/problem/P7912
//https://www.luogu.com.cn/problem/solution/P7912 第二篇 _StarBird_ 
//方法：类似合并排序 
//复杂度： O(nlogn) 

#include<bits/stdc++.h>
#define INF 200010
using namespace std;

int n;
set<int> s1,s2;//把下标扔在两个set里 

int main(){
	scanf("%d",&n);
	s1.clear();
	s2.clear();
	int q;
	
	for(int i=1;i<=n;++i){
		scanf("%d",&q);
		if(q) s1.insert(i);  //反了？ 
		else s2.insert(i);
	}
	
	s1.insert(INF);//这里塞INF的原因是防止set空后的出错 
	s2.insert(INF);
	
	int nw=0;
	bool p=*s1.begin()<*s2.begin() ? 0:1;
	//这里是找两种东西最小下标的小值，p是当前删的东西 ——反了？ 
	
	while(!p && s1.size()>1 || p && s2.size()>1)
	    //因为有个INF，所以size要>1 
		if (!p){
			nw=*s1.upper_bound(nw);//upper_bound找下一个 
			if (nw==INF)//找不完了就从头开始 
			{
				nw=0;
				p=*s1.begin()<*s2.begin()?0:1;//p要重新选 
				puts("");
				continue;
			}
			printf("%d ",nw);//取了，输出，删除 
			s1.erase(nw);
			p=!p;//取另外一坨 
		}
		else//同上 
		{
			nw=*s2.upper_bound(nw);
			if (nw==INF)
			{
				nw=0;
				p=*s1.begin()<*s2.begin()?0:1;
				puts("");
				continue;
			}
			printf("%d ",nw);
			s2.erase(nw);
			p=!p;
		}
		
	puts("");//最后一个果篮是没换行的 
	
	while(s1.size()>1) 
	   printf("%d\n",*s1.begin()),s1.erase(*s1.begin());
	   //一坨取完以后，另外一堆是一个区间，一行一行输出 
	
	while(s2.size()>1) 
	   printf("%d\n",*s2.begin()),s2.erase(*s2.begin());
	   //同上 
	
	return 0;
}

