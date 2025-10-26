# 自然数的拆分问题

## 题目描述

任何一个大于 $1$ 的自然数 $n$，总可以拆分成若干个小于 $n$ 的自然数之和。现在给你一个自然数 $n$，要求你求出 $n$ 的拆分成一些数字的和。每个拆分后的序列中的数字从小到大排序。然后你需要输出这些序列，其中字典序小的序列需要优先输出。

## 输入格式

待拆分的自然数 $n$。

## 输出格式

若干数的加法式子。

## 样例 #1

### 样例输入 #1

```
7
```

### 样例输出 #1

```
1+1+1+1+1+1+1
1+1+1+1+1+2
1+1+1+1+3
1+1+1+2+2
1+1+1+4
1+1+2+3
1+1+5
1+2+2+2
1+2+4
1+3+3
1+6
2+2+3
2+5
3+4
```

## 提示

数据保证，$2\leq n\le 8$。

## 参考程序A (C++版, 递归)
```cpp
#include <bits/stdc++.h>
using namespace std;
int a[1000];
void dfs(int m, int start, int k) { //Depth First Search
	int remain;						//We start from 'start'.
	for (int i = start; i <= m/2; i++) {
		remain = m-i;
		a[k] = i ;
		dfs(remain, i, k + 1);      //Recursion edition.
		for (int j = 1; j <= k; j++) cout << a[j] << '+';
		cout << remain << endl;
	}
}
int main() {
	int n;
	cin >> n;
	dfs(n, 1, 1);
	return 0;
}
```
## 参考程序B (C++版, 非递归, 详细注释)
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, total = 0;
	cin >> n;
	int a[n + 1];
	for(int i = 0; i <= n; i++) a[i] = 0;
	int p = 1, i = 0, s = 0;
	do{ 	 //Consider it a maze.
		i++; //Consider this a direction, consider p a step recorder.
		s += i;
		if (s <= n){  //If still needs nums or already needs printing.
			a[p] = i; //The num, or 'direction' is recorded.
			if(s == n){
				total++;
				if(p != 1){ //Print.
					cout << n << " = ";
					for(int i = 1; i <= p; i++){
						if(i != 1) cout << '+';
						cout << a[i];
					}
					cout << endl;
				}
				s -= a[p--] + a[p]; //Remove 2 nums. e.g. a[1, 1, 1, 1] -> a[1, 1], so we can add 2 : a[1, 1, 2].
				i = a[p];
			}else{
				i = a[p]-1; //We subtract by 1 to ensure that when i increases, it will be a[p] so we do not miss a case.
				p++;
			}
		}else{
			s -= i; //If not legitamate, we undo this step.
			s -= a[--p];
			i = a[p];
		}
	}while(p != 0); //Do while p not_eq to 0, i.e. we can still find other cases.
//	cout << "Total:" << endl << total;
	return 0;
}
```