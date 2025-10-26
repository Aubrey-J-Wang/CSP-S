#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 2147483647;
char c;
string s, f;
map<string, string> re;

int main() {
	while (cin >> c) {
		if (c == '$')
			break;
		else if (c == '#') {
			cin >> f;
		} else if (c == '+') {
			cin >> s;
			re[s] = f;
		} else if (c == '?') {
			cin >> s;
			cout << s << " ";
			string ss = s;
			while (re.count(ss))
				ss = re[ss];

			cout << ss << endl;
		}
	}

	return 0;
}

