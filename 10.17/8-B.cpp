#include <iostream>
#include <vector>
#define loop(i, n, m) for(int i = (n); (i) < (m); i++)
#define rev_loop(i, n, m) for(int i = (n); (i) >= (m); i--)
using namespace std;

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

int gcd(int a, int b){
	if(a%b == 0) return abs(b);
	else return abs(gcd(b, a%b));
}

pair<int, int> formalized_sqrt(int x){
	int coeff = 1;
	for(int i = 2; i*i <= x; i++){
		while(x%(i*i) == 0) x /= i*i, coeff *= i;
	}
	return {coeff, x};
}

void print_frac(int nomi, int denom){
//	if(nomi == 0) return;
	int g = gcd(nomi, denom);
	nomi /= g, denom /= g;
	if(denom == 1 || denom == -1){
		write(nomi*denom);
		return;
	}
	if(denom < 0) putchar('-'), denom = -denom;
	write(nomi), putchar('/'), write(denom);
}

int main(){
	int T = read(), M = read();
	while(T--){
		int a = read(), b = read(), c = read();
		if(a < 0) a = -a, b = -b, c = -c;
		int Delta = b*b-4*a*c;
		if(Delta < 0){
			puts("NO");
			continue;
		}
		auto [u, v] = formalized_sqrt(Delta);
		if(v == 1 or v == 0){
			print_frac(-b+u*v, 2*a);
			putchar('\n');
			continue;
		}
		
		if(b != 0) print_frac(-b, 2*a), putchar('+');
		int g = gcd(u, 2*a);
		if(u/g != 1) write(u/g), putchar('*');
		printf("sqrt(%d)", v);
		if(2*a/g != 1) putchar('/'), write(2*a/g);
		putchar('\n');
	}
	return 0;
}
