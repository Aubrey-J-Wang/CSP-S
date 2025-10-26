//洛谷P7912, [CSP-J 2021 T4] 小熊的果篮 
//https://www.luogu.com.cn/problem/P7912
//https://www.luogu.com.cn/problem/solution/P7912 第一篇 vegetable_king 
//方法：模拟
//复杂度： O(n*sqrt(n)) 
 
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct kuai{ // 块
	int st, ed, th;
}f, x, ad;

int n, cnt, t[200002];
queue<kuai> q, q2;
bool used[200001]; // 记录是否被取出

int main(){
	scanf("%d", &n);
	for (int i = 1;i <= n;i ++) 
	   scanf("%d", &t[i]);
	
	t[n + 1] = !t[n];
	
	for (int i = 2, si = 1;i <= n + 1;i++){
		if (t[i] != t[i - 1]) 
		   q.push((kuai){si, i - 1, t[i - 1]}), si = i; 
		   // 把连续一段相同的元素合成一个块
	}
	
	cnt = n;
	while (cnt){
		while (q.size()){
			f = q.front();
			q.pop();
			while (used[f.st] && f.st <= f.ed) f.st++; 
			// 如果已经被取了
			if (f.st > f.ed) continue;
			printf("%d ", f.st), cnt--;
			used[f.st] = 1; // 将块的开头元素去掉并输出
			if (f.ed == f.st) continue; // 如果这个块被取完了
			f.st++;
			q2.push(f); // 先临时存到 q2 里进行合并
		}
		putchar('\n');
		
		while (q2.size()){
			ad = q2.front();
			q2.pop();
			while (q2.size()){
				x = q2.front();
				if (x.th == ad.th){ // 能合并就合并
					ad.ed = x.ed;
					q2.pop();
				}
				else break;
			}
			q.push(ad); // 丢回 q 里
		}
	}
}


