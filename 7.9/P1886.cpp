#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
using namespace std;

#define MAXN 1000001

int n, k;
int a[MAXN], q[MAXN];

template <typename Op>
void deque() {
  Op o;
  memset(q, 0, sizeof(q));
  int h = 1, t = 0;
  for (int i = 1; i <= n; i++) {
    while (h <= t && q[h] + k <= i) h++;
    while (h <= t && o(a[i], a[q[t]])) t--;
    q[++t] = i;
    if (i >= k) cout << a[q[h]] << ' ';
  }
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  deque<less<int> >();
  cout << endl;
  deque<greater<int> >();
  return 0;
}
