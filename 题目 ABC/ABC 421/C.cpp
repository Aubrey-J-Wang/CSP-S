#include <iostream>
#include <vector>
using namespace std;
int read();
void write(int x);

	int numa[1000005] = {}, numb[1000005] = {};

int main(){
	int n = read();
	string s;
	cin >> s;
	string case1 = "A", case2 = "B";
	for(int i = 1; i <= n*2-2; i++){
		if(case1[i-1] == 'A') case1 += "B";
		else case1 += "A";
		if(case2[i-1] == 'A') case2 += "B";
		else case2 += "A";
	}

	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'A') numa[i+1]++;
		else numb[i+1]++;
		numa[i+2] = numa[i+1], numb[i+2] = numb[i+1];
	}
	
	int res1 = 0, res2 = 0;
	vector<int> casea, caseb;
	for(int i = 0; i < n*2; i++){
		if(s[i] != case1[i]) casea.emplace_back(i);
		else caseb.emplace_back(i);
	}
	
	for(int i = 1; i < casea.size(); i += 2){
		int j = i;
		while(s[casea[i]] == s[casea[j-1]] && i < casea.size() && numa[i+1]-numa[j-1] != numb[i+1]-numb[j-1]) i++;
		res1 += casea[i]-casea[j-1];
	}
	
	for(int i = 1; i < caseb.size(); i += 2){
		int j = i;
		while(s[caseb[i]] == s[caseb[j-1]] && i < caseb.size() && numa[i+1]-numa[j-1] != numb[i+1]-numb[j-1]) i++;
		res2 += caseb[i]-caseb[j-1];
	}
	
	write(min(res1, res2));
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

//- ------ -----         -- ------
//BABABABABABABABABABABABABABABABABA
//AAABABABBBABABBABABABABBAAABABABBA
//ABABABABABABABABABABABABABABABABAB
// -      -     ---------  -      --
// 2      9     567890123  6      34
