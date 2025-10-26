//ABC 403 D - Forbidden Difference
//https://atcoder.jp/contests/abc403/tasks/abc403_c 
//https://atcoder.jp/contests/abc403/editorial/12831
//https://atcoder.jp/contests/abc403/submissions/65083840

import sys
input = sys.stdin.readline

M = 10**6 + 1
N, D = map(int, input().split())
A = list(map(int, input().split()))
cnt = [0] * M
for x in A:
    cnt[x] += 1
if D == 0:
    print(sum(max(x - 1, 0) for x in cnt))
    exit()


def calc(x):
    if not x:
        return 0
    x = [0] + x
    dp = [0] * (len(x) + 1)
    for i in range(1, len(x)):
        dp[i + 1] = min(dp[i] + x[i], dp[i - 1] + x[i - 1])
    return dp[-1]


ans = 0
for i in range(D):
    ans += calc(cnt[i::D])
print(ans)



