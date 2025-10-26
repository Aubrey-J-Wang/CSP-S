#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int read();
void write(int x);

bool check(string s){
	char ss[s.length()+10] = "";
	for(int i = 0; i < s.length(); i++) ss[i] = s[i];
	int a, b, c, d, e;
	if(sscanf(ss, "%d.%d.%d.%d:%d", &a, &b, &c, &d, &e) != 5) return false;
	string sss = to_string(a)+to_string(b)+to_string(c)+to_string(d)+to_string(e);
	if(sss.length() != s.length()-4) return false;
	if(a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255 || e < 0 || e > 65535) return false;
	return true;
}

int main(){
	int n = read();
	set<string> server_list;
	map<string, int> mp;
	for(int i = 1; i <= n; i++){
		string op, ad;
		cin >> op >> ad;
		if(!check(ad)){
			puts("ERR");
			continue;
		}
		if(op == "Server"){
			if(server_list.contains(ad)) puts("FAIL");
			else server_list.insert(ad), mp[ad] = i, puts("OK");
		}else if(op == "Client"){
			if(server_list.contains(ad)) write(mp[ad]), putchar('\n');
			else puts("FAIL");
		}
	}
	return 0;
}

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * f;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
