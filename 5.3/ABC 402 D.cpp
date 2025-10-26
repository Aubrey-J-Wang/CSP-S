#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	
    int n, m;
    cin >> n >> m;
    vector<ll> cnt(n);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cnt[(a + b) % n]++;
//		Let AB be a straight line which goes through points a and b, then we can easily get that when AB is translated, the
//		resulting straight line is parallel to AB, to put it practically, this is to say, if k is an integer (which != 0), let CD
//		be a straight line which goes through points (a+k) and (b-k) which means that point a moves k segments clockwise and b k
//		segments counterclockwise, there exists AB // CD. Moreover, (a+k)+(b-k) = a+b. Hence we can get if 2 points on the circle
//		on a line has the same sum as another point-pair of a line, they are parallel.
//		To avoid overflow of sum numbers, we restore the remainder of (a+b) to n in cnt[], the value of cnt[k] is the number of
//		lines which satisfy: The sum number of the two points on it has the same remainder to n as each other and as k. That is to
//		say, cnt[k] is the number of lines in a 'system' of lines in which all lines are parallel to each other. There are
//		different 'system's when k changes, naturally.
    }
    
    ll ans = (ll)m * (m - 1) / 2;
//	ans originally restores the number of every possible line in the circle, which is C(2, m) = m(m-1)/2.
    
    for (auto e : cnt) {
        ans -= e * (e - 1) / 2; // When we decrease the number of parallel lines in each system...
    }
    
    cout << ans << endl; // We get number of lines which intersect!
    return 0
}
