//���P5662,[CSP-J2019 T3] ����Ʒ 
//https://www.luogu.com.cn/problem/P5662
//https://www.luogu.com.cn/problem/solution/P5662 ��һƪ �������� 

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 105;

int dp[10005];
//dp[k]��ʾ����ʣ k Ԫ�ֽ��ʱ���������϶������Ժ��Ǯ��

int price[MAXN][MAXN];
//price[i][j]��ʾ�� i ��� j ����Ʒ�ļ۸�

int main() {
    int t, n, m, ans;
    scanf("%d%d%d", &t, &n, &m);
    
	for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &price[i][j]);
        }
    }
    
	ans = m;  //��һ������������ m Ԫ
	
    for (int i = 1; i < t; ++i) {
        //�Ȱ����鸳ֵΪ������
        memset(dp, ~0x3f, sizeof(dp));
        //ʲô�����򣬽���������ansԪ����������Ҳ��ansԪ
        dp[ans] = ans;
        //ö�ٵ�j����Ʒ
        for (int j = 1; j <= n; ++j) {
            //������kԪ��ʱ��ȥ���������ϵ�Ǯ
            for (int k = ans; k >= price[i][j]; --k) {
                //��һ����Ʒ���ֽ���٣�׬һ�ݲ�ۣ���ȫ��������ѭ��
                dp[k - price[i][j]] = max(dp[k - price[i][j]], dp[k] + price[i + 1][j] - price[i][j]);
            }
        }
        
        //��һ�����������������
        int ma = 0;
        for (int j = 0; j <= ans; ++j) {
            ma = max(ma, dp[j]);
        }
        
        //�������Ͼ�����ô��Ǯ�ˣ�����׬Ǯ
        ans = ma;
    }
    
    cout << ans << endl;
    return 0;
}


