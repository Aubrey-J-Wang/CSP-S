#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
    	if(s[i] == '(' or s[i] == '<' or s[i] == '[') st.push(s[i]);
    	else{
    		if(st.empty()){
    			cout << "No";
    			return 0;
			}
    		char t = st.top();
    		if((t == '(' and s[i] != ')') or (t == '<' and s[i] != '>') or (t == '[' and s[i] != ']')){
    			cout << "No";
    			return 0;
			}else st.pop();
		}
	}
	if(st.empty()) cout << "Yes";
	else cout << "No";
	return 0;
}
