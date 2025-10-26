//���P7912, [CSP-J 2021 T4] С�ܵĹ��� 
//https://www.luogu.com.cn/problem/P7912
//https://www.luogu.com.cn/problem/solution/P7912 �ڶ�ƪ _StarBird_ 
//���������ƺϲ����� 
//���Ӷȣ� O(nlogn) 

#include<bits/stdc++.h>
#define INF 200010
using namespace std;

int n;
set<int> s1,s2;//���±���������set�� 

int main(){
	scanf("%d",&n);
	s1.clear();
	s2.clear();
	int q;
	
	for(int i=1;i<=n;++i){
		scanf("%d",&q);
		if(q) s1.insert(i);  //���ˣ� 
		else s2.insert(i);
	}
	
	s1.insert(INF);//������INF��ԭ���Ƿ�ֹset�պ�ĳ��� 
	s2.insert(INF);
	
	int nw=0;
	bool p=*s1.begin()<*s2.begin() ? 0:1;
	//�����������ֶ�����С�±��Сֵ��p�ǵ�ǰɾ�Ķ��� �������ˣ� 
	
	while(!p && s1.size()>1 || p && s2.size()>1)
	    //��Ϊ�и�INF������sizeҪ>1 
		if (!p){
			nw=*s1.upper_bound(nw);//upper_bound����һ�� 
			if (nw==INF)//�Ҳ����˾ʹ�ͷ��ʼ 
			{
				nw=0;
				p=*s1.begin()<*s2.begin()?0:1;//pҪ����ѡ 
				puts("");
				continue;
			}
			printf("%d ",nw);//ȡ�ˣ������ɾ�� 
			s1.erase(nw);
			p=!p;//ȡ����һ�� 
		}
		else//ͬ�� 
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
		
	puts("");//���һ��������û���е� 
	
	while(s1.size()>1) 
	   printf("%d\n",*s1.begin()),s1.erase(*s1.begin());
	   //һ��ȡ���Ժ�����һ����һ�����䣬һ��һ����� 
	
	while(s2.size()>1) 
	   printf("%d\n",*s2.begin()),s2.erase(*s2.begin());
	   //ͬ�� 
	
	return 0;
}

