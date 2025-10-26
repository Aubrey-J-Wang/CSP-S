//���P7912, [CSP-J 2021 T4] С�ܵĹ��� 
//https://www.luogu.com.cn/problem/P7912
//https://www.luogu.com.cn/problem/solution/P7912 ��һƪ vegetable_king 
//������ģ��
//���Ӷȣ� O(n*sqrt(n)) 
 
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct kuai{ // ��
	int st, ed, th;
}f, x, ad;

int n, cnt, t[200002];
queue<kuai> q, q2;
bool used[200001]; // ��¼�Ƿ�ȡ��

int main(){
	scanf("%d", &n);
	for (int i = 1;i <= n;i ++) 
	   scanf("%d", &t[i]);
	
	t[n + 1] = !t[n];
	
	for (int i = 2, si = 1;i <= n + 1;i++){
		if (t[i] != t[i - 1]) 
		   q.push((kuai){si, i - 1, t[i - 1]}), si = i; 
		   // ������һ����ͬ��Ԫ�غϳ�һ����
	}
	
	cnt = n;
	while (cnt){
		while (q.size()){
			f = q.front();
			q.pop();
			while (used[f.st] && f.st <= f.ed) f.st++; 
			// ����Ѿ���ȡ��
			if (f.st > f.ed) continue;
			printf("%d ", f.st), cnt--;
			used[f.st] = 1; // ����Ŀ�ͷԪ��ȥ�������
			if (f.ed == f.st) continue; // �������鱻ȡ����
			f.st++;
			q2.push(f); // ����ʱ�浽 q2 ����кϲ�
		}
		putchar('\n');
		
		while (q2.size()){
			ad = q2.front();
			q2.pop();
			while (q2.size()){
				x = q2.front();
				if (x.th == ad.th){ // �ܺϲ��ͺϲ�
					ad.ed = x.ed;
					q2.pop();
				}
				else break;
			}
			q.push(ad); // ���� q ��
		}
	}
}


