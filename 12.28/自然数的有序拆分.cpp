//自然数的有序拆分， 洛谷P2404
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, total = 0;

	cin >> n;     //n=4
	int a[n + 1];
	for (int i = 0; i <= n; i++)
		a[i] = 0;

	int p = 1, i = 0, s = 0;

	do {
		i++;       //i=1        3,
		s += i;    //s+=1+1+1+1      2+2
		if (s <= n) {
			a[p] = i;    //a=[,1,1,1,1]       2,]
			if (s == n) {
				total++;
				for (int i = 1; i <= p; i++) {
					cout << a[i] << " ";
				}
				cout << endl; //a[1,1,1]
				s -= a[p];    //p=3  s+=1+1
				p--;          //p=2
				s -= a[p];    //p=2  s+=1+
				i = a[p];     //i=1
			} else {
				i = a[p] - 1; //i=1
				p++;        //p=3
			}
		} else {      //s+=1+2+2  p=3  i=2
			s -= i;    //s+=1+2
			p--;       //p=2
			s -= a[p]; //s=1+
			i = a[p];  //i=2
		}
	} while (p != 0);

	cout << total;
	return 0;
}
、