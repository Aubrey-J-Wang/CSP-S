#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
void answer(bool out, int v) {
	if(out) cout << "Yes" << endl;
	else cout << "No" << endl;
	cout << v;
	return;
}
int d[14][300001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, s, t;
//	freopen(��escape.in��, ��r��, stdin);
//	freopen(��escape.out��, ��w��, stdout);
	cin >> m >> s >> t;
	int ti = 0, dist = 0; //ti: ���õ�ʱ��; dist: ���߹��ľ���
//  �Ⱦ���ʹ��ħ��ֵ
	while (m >= 10) {
		m = m - 10;
		dist = dist + 60;
		if (dist >= s) { //ֻ��ħ��ֵ�Ϳ������룬��������õ�ʱ��
			answer(true, ti + 1);
			return 0;
		}
		if ((++ti) == t) {
// 		ħ��ֵ��δ���꼴�Ѵ�ʱ�����ޣ�����������������
			answer(false, dist);
			return 0;
		}
	}
	memset(d, 0, sizeof(d));
	int i, j;
// 	��ʼ�� d[j][ti]Ϊһ������
	for (j = 0; j <= 13; j++) d[j][ti] = -(1 << 30);
	d[m][ti] = dist;
	for (i = ti; i < t; i++) {
//		��ʱ�仮�ֽ׶�, �����ǵ���û��ʱ��
		for (j = 0; j <= 13; j++)
			d[j][i + 1] = -(1 << 30);
		for (j = 0; j <= 13; j++) {
			if (d[j][i] >= s) { //�߹��ľ����������ڵľ��룬 �������ǰ����ʱ��
				answer(true, i);
				return 0;
			}
// ״̬ת�Ʒ���
			d[j][i + 1] = max(d[j][i] + 17, d[j][i + 1]);
			if (j >= 4) d[j][i + 1] = max(d[j - 4][i], d[j][i + 1]);
			if (j < 4) d[j][i + 1] = max(d[j + 10][i] + 60, d[j][i + 1]);
		}
	}
// �ҵ����ʱ������״̬��֮���������
	int maxv = 0;
	for (j = 0; j <= 13; j++)
		if (d[j][t] >= maxv) {
			maxv = d[j][t];
			if (maxv >= s) {
				answer(true, i);
				return 0;
			}
		}
	answer(false, maxv); // �����޷����룬����ܹ��ﵽ��������
	return 0;
}
/*
//̰��
#include <iostream>
using namespace std;
int m, s, t, min, max, k, temp, m1, t1, i;
bool flag;

int main() {
	ios::sync_with_stdio(false);
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
	cin >> m >> s >> t;
	max = 0; //��������ĵ�ʱ����Զ����
	min = 0x3f3f3f3f; //����������ʱ��
	flag = false; //�Ƿ��ܹ�����ı��
	for (int i = t; i >= 0; i--) { //ö�ٻָ�ħ����ʱ�䣬����Ϊ 0
		m1 = m + 4 * i; //��ħ��ֵ
		t1 = m1 / 10; //����ʹ����˸�Ĵ��������� 1s һ����˸�� t1 Ҳ������˸����ʱ��
		if (t1 > t)
			t1 = t; //���˵��˸��ʱ������ʱ�䣬��ôû���ô������ǽ���˸ʱ�丳Ϊ��ʱ��
		if (t - t1 - i < 0)
			continue; //���˵��˸ʱ����ָ�ħ����ʱ�������ʱ�䣬��ô������
		temp = t1 * 60 + (t - t1 - i) * 17; //(��������ʱ���) ��·��=��˸+�ܲ�
		if(temp > s){ //��������ӳ���
		//���ž���ʹ����˸��ԭ�򣬼����ܲ�ʱ�䣬ʹ��ʵ��ʱ�価���١�
			flag = true;
			k = t - t1 - i;
			while(k > 0 and temp - 17 > s) k--, temp -= 17;
			if(k + i + t1 < min) min = k + i + t1; //��Сʱ��
			if(temp > max) max = temp; //�����
			if(flag){
				cout << "Yes" << endl;
				cout << min;
			}else{
				cout << "No" << endl;
				cout << max;
			}
		}
	}
	return 0;
}
*/