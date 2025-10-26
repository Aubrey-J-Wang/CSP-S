//洛谷P9749, CSP-J 2023 T2, 公路 
//https://www.luogu.com.cn/problem/P9749
//https://www.luogu.com.cn/problem/solution/P9749   第二篇 SJZ2010

#include <cstdio>

typedef long long ll;

const int N = 1e5 + 5;

ll n, d;
ll dis[N], money[N], nxt[N], dis_sum[N], can_dis, ans;

int main(){
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	
	scanf("%lld %lld", &n, &d);
	
	ll i, dist, last_m, last_i;
	
	for (i = 1; i < n; i++)
		scanf("%lld", &dis[i]);
	
	for (i = 2; i <= n; i++)
		dis_sum[i] = dis_sum[i - 1] + dis[i - 1];// 计算从 1 到 i 的距离
	
	for (i = 1; i <= n; i++)
		scanf("%lld", &money[i]);
	
	last_m = money[1];
	last_i = 1;
	
	for (i = 2; i <= n - 1; i++){
		if (money[i] < last_m) {  // 遇到比上一个加油站便宜的
			nxt[last_i] = i;// 类似与链表的方式存储下一个加油站
			last_i = i;
			last_m = money[i];
		}
	}
	
	nxt[last_i] = n; // 要到 n 号点，可以把 n 号点看作价钱位 0
	
	for (i = 1; i < n;){
		dist = dis_sum[nxt[i]] - dis_sum[i];
		ans += (dist - can_dis + d - 1) / d * money[i];// 要考虑还剩多少油
        	// can_dis 表示还能开多少距离
		can_dis += (dist - can_dis + d - 1) / d * d; // 注意油量要向上取整
		can_dis -= dist;
		i = nxt[i];// 向下一个加油站开
	}
	
	printf("%lld\n", ans);
	return 0;
}


      

