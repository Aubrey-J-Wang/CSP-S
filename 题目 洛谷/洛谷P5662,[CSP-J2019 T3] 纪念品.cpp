//洛谷P5662,[CSP-J2019 T3] 纪念品 
//https://www.luogu.com.cn/problem/P5662
//https://www.luogu.com.cn/problem/solution/P5662 第一篇 泥土笨笨 

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 105;

int dp[10005];
//dp[k]表示手里剩 k 元现金的时候，明天早上都卖了以后的钱数

int price[MAXN][MAXN];
//price[i][j]表示第 i 天第 j 件物品的价格

int main() {
    int t, n, m, ans;
    scanf("%d%d%d", &t, &n, &m);
    
	for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &price[i][j]);
        }
    }
    
	ans = m;  //第一天早上手里有 m 元
	
    for (int i = 1; i < t; ++i) {
        //先把数组赋值为负无穷
        memset(dp, ~0x3f, sizeof(dp));
        //什么都不买，今天早上有ans元，明天早上也是ans元
        dp[ans] = ans;
        //枚举第j个物品
        for (int j = 1; j <= n; ++j) {
            //手里有k元的时候，去推明天早上的钱
            for (int k = ans; k >= price[i][j]; --k) {
                //买一件物品，现金减少，赚一份差价，完全背包倒着循环
                dp[k - price[i][j]] = max(dp[k - price[i][j]], dp[k] + price[i + 1][j] - price[i][j]);
            }
        }
        
        //找一下明天早上收益最大
        int ma = 0;
        for (int j = 0; j <= ans; ++j) {
            ma = max(ma, dp[j]);
        }
        
        //明天早上就有这么多钱了，继续赚钱
        ans = ma;
    }
    
    cout << ans << endl;
    return 0;
}


