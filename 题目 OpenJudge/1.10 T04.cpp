#include<bits/stdc++.h>
using namespace std;
int n;
struct score{
	int tot, cn, ma, en, num;
} stu[301];
bool cmp(score a, score b){
	if(a.tot != b.tot){
		return a.tot > b.tot;
	}else if(a.cn != b.cn){
		return a.cn > b.cn;
	}else return a.num < b.num;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		stu[i].num = i;
		cin >> stu[i].cn >> stu[i].ma >> stu[i].en;
		stu[i].tot = stu[i].cn + stu[i].ma + stu[i].en;
	}
	sort(stu+1, stu+n+1, cmp);
	for(int i = 1; i <= 5; i++) cout << stu[i].num << ' ' << stu[i].tot << endl;
	return 0;
}