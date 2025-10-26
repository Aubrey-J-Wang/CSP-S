//ABC 157 E - Simple String Queries    leaf1415
//https://atcoder.jp/contests/abc157/tasks/abc157_e
//https://www.luogu.com.cn/problem/AT5323 
#include <iostream>
#include <set>
#include <map>
#include <vector>
#define llint long long
using namespace std;

struct BIT{
	int size;
	vector<llint> bit;
	
	BIT(){
	    size = 0;
	}
	
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	
	void init(){
		for(int i = 1; i <= size; i++) 
		   bit[i] = 0;
	}
	
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n, Q;
string s;
BIT bit[26];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	s = "#" + s;
	
	for(int i = 0; i< 26; i++) 
	    bit[i] = BIT(500005);
	
	for(int i = 1; i <= n; i++){
		bit[s[i]-'a'].add(i, 1);
	}
	
	llint t, l, r; 
	char c;
	
	cin >> Q;
	for(int q = 1; q <= Q; q++){
		cin >> t;
		if(t == 1){
			cin >> l >> c;
			bit[s[l]-'a'].add(l, -1);
			s[l] = c;
			bit[s[l]-'a'].add(l, 1);
		}
		
		if(t == 2){
			cin >> l >> r;
			llint ans = 0;
			for(int i = 0; i < 26; i++){
				if(bit[i].query(r) - bit[i].query(l-1) > 0) 
				   ans++;
			}
			cout << ans << endl;
		}
	}
	
	return 0;
}


