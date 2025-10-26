//Âå¹ÈP2061£¬poj 3277  
#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

#define int long long

struct node{
	char type;
	int pos;
	int high;
	int id;
	bool operator < (node x)const{
		return pos<x.pos;
	}
}a[80010];

struct hig{
	int high;
	int id;
	bool operator < (hig x)const{
		return high<x.high;
	}
}tmp;

priority_queue<hig> q;
int n;
set<int> popid;

main(){
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=1;i<=n;++i){
		a[i*2-1].type='A';
		cin>>a[i*2-1].pos;
		a[i*2].type='B';
		cin>>a[i*2].pos;
		cin>>a[i*2-1].high;
		a[i*2].high=a[i*2-1].high;
		a[i*2].id=a[i*2-1].id=i;
	}

	n*=2;
	a[0].high=0;
	a[0].pos=0;

	tmp.high=0;
	tmp.id=0;
	q.push(tmp);
	
	int ans=0;

	sort(a+1,a+n+1);

	for(int i=1;i<=n;++i){
		if(a[i].type=='A'){
			int maxhigh=q.top().high;
			int dis=a[i].pos-a[i-1].pos;
			ans+=maxhigh*dis;
			tmp.high=a[i].high;
			tmp.id=a[i].id;
			q.push(tmp);
		}
		else{
			int maxhigh=q.top().high;
			int dis=a[i].pos-a[i-1].pos;
			ans+=maxhigh*dis;
			popid.insert(a[i].id);
			while(popid.count(q.top().id)){
				popid.erase(q.top().id);
				q.pop();
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}
