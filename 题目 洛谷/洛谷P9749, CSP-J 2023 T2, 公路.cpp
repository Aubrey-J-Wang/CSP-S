//���P9749, CSP-J 2023 T2, ��· 
//https://www.luogu.com.cn/problem/P9749
//https://www.luogu.com.cn/problem/solution/P9749   �ڶ�ƪ SJZ2010

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
		dis_sum[i] = dis_sum[i - 1] + dis[i - 1];// ����� 1 �� i �ľ���
	
	for (i = 1; i <= n; i++)
		scanf("%lld", &money[i]);
	
	last_m = money[1];
	last_i = 1;
	
	for (i = 2; i <= n - 1; i++){
		if (money[i] < last_m) {  // ��������һ������վ���˵�
			nxt[last_i] = i;// ����������ķ�ʽ�洢��һ������վ
			last_i = i;
			last_m = money[i];
		}
	}
	
	nxt[last_i] = n; // Ҫ�� n �ŵ㣬���԰� n �ŵ㿴����Ǯλ 0
	
	for (i = 1; i < n;){
		dist = dis_sum[nxt[i]] - dis_sum[i];
		ans += (dist - can_dis + d - 1) / d * money[i];// Ҫ���ǻ�ʣ������
        	// can_dis ��ʾ���ܿ����پ���
		can_dis += (dist - can_dis + d - 1) / d * d; // ע������Ҫ����ȡ��
		can_dis -= dist;
		i = nxt[i];// ����һ������վ��
	}
	
	printf("%lld\n", ans);
	return 0;
}


      

