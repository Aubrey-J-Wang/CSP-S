#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool a[10][7] = {{1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1}, {0,1,1,0,0,1,1}, {1,0,1,1,0,1,1},
				 {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0}, {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}};

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    int state[7] = {0}, f = 0;
    while(n--){
    	string s;
    	cin >> s;
    	int num = s[0]-'0', light[7] = {0};
    	if(state[num] != 0) continue;
    	for(int i = 1; i < s.length(); i++) light[s[i]-'A'] = 1;
    	for(int i = 0; i < 7; i++){
//    		cout << light[i];
    		if(a[num][i] && !light[i]) state[i] = -1;
			else if(!a[num][i] && light[i]) state[i] = 1; 
		}
//		cout << endl;
		
	}
	
	for(int i : state){
		if(i == -1) cout << 'x';
		else if(i == 1) cout << 'X';
		else cout << '-';
	}
	return 0;
}
