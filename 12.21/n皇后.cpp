//N�ʺ�����
#include <bits/stdc++.h>
using namespace std;

int n;
int x[10];

bool is_ok(int k) {
	int i = 1;
	while (i < k) {
		if (x[i] == x[k] || fabs(x[i] - x[k]) == fabs(i - k))
			return false;
		i++;
	}

	return true;
}

int main() {
	//t=1;
	cin >> n;   //n=4
	x[1] = 0;
	p = 1;

	while (p > 0)  {    // �ӵ�һ�п�ʼ����
		x[p]++;
		while (x[p] <= n && !is_ok(p))
			x[p]++;
		if (x[p] <= n)
			if (p == n) {
				//��ӡ, ������+1;
			} else {
				p++;
				x[p] = 0;
			} else
			p--;    //���ݣ��˻ص���һ��λ��
	}

	return 0;
}

