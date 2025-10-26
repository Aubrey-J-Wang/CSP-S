#include <iostream>
#include <vector>
using namespace std;
int read();
void write(int x);

int main(){
	int T = read();
	while(T--){
		int len = read();
		string s;
		cin >> s;
		int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0;
		for(int i = 0, j = s.length()-1; i <= j; i++, j--){
			while(s[i] == '0' && i < j) cnt1++, i++;
			while(s[j] == '0' && i < j) cnt2++, j--;
			while(s[i] == '1' && i < j){
				num1 += 2*i+1;
				cnt1 = 0;
				i++;
			}
			
			while(s[j] == '1' && i < j){
				num1 += 2*(s.length()-j-1)+1;
				cnt2 = 0;
				j--;
			}
		}
		
		cnt1 = cnt2 = 0;
		for(int i = 0, j = s.length()-1; i <= j; i++, j--){
			while(s[i] == '1' && i < j) cnt1++, i++;
			while(s[j] == '1' && i < j) cnt2++, j--;
			while(s[i] == '0' && i < j){
				num2 += 2*i+1;
				cnt1 = 0;
				i++;
			}
			
			while(s[j] == '0' && i < j){
				num2 += 2*(s.length()-j-1)+1;
				cnt2 = 0;
				j--;
			}
		}
		cout << min(num1, num2) << endl;
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
