#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main(){
	string s;
	cin >> s;
	stack<int> num;
	int cur = 0;
	
	for(auto i : s){
		if(!isdigit(i)){
			if(i == '@'){
				cout << num.top();
				return 0;
			}else if(i == '.'){
				num.push(cur);
				cur = 0;
				continue;
			}
			auto x = num.top(); num.pop();
			auto y = num.top(); num.pop();
			switch(i){
				case '+':
					num.push(x+y);
					break;
				case '-':
					num.push(y-x);
					break;
				case '*':
					num.push(x*y);
					break;
				case '/':
					num.push(y/x);
					break;
			}
		}else cur = cur*10 + (i - '0');
	}
	return 0;
}
