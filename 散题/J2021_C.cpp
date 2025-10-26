#include<iostream>
#include<cctype>
#include<cstring>
#include<map>
using namespace std;
const int ERR = -1, FAIL = -2, OK = 0;
struct net{
	string type;
	string address;
	bool input(){
		cin >> type >> address;
		int numtemp = -1, p = 0;
		string rec = "";
		for(int i = 0; i < address.length(); i++){
			if(isdigit(address[i])){
				if(numtemp < 0) numtemp = 0;
				numtemp *= 10;
				numtemp += address[i]-'0';
				if(address[i]-'0' == 0 && i == p && isdigit(address[i+1])){
//					cout << "EXTRA 0!\n";
					return false;
				}
			}else{
				if(address[i] == address[i-1]){
//					cout << "EXTRA'.'OR':'!\n";
					return false;
				}
				if(numtemp > 255 || numtemp < 0){
//					cout << "IP OUT OF RANGE!" << numtemp << "\n";
					return false;
				}
				p = i+1;
				numtemp = -1;
				rec += address[i];
			}
		}
		if(rec != "...:"){
//			cout << "SIGN ERR!\n";
			return false;
		}
		if(numtemp > 65535 || numtemp < 0){
//			cout << "DETAIL OUT OF RANGE!";
			return false;
		}
		return true;
	}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//  freopen("network.in", "r", stdin);
//  freopen("network.out", "w", stdout);
//	net a;
//	cout << a.input();
	int n;
	cin >> n;
	net a[n+1];
	int ans[n+1];
	memset(ans, 0x3f, sizeof(ans));
	map<string, int> m;
	for(int i = 1; i <= n; i++){
		if(!a[i].input()){
			ans[i] = ERR;
			continue;
		}
		if(a[i].type == "Server"){
			if(m[a[i].address] == 0) m[a[i].address] = i, ans[i] = OK;
			else ans[i] = FAIL;
		}
		if(a[i].type == "Client"){
			if(m[a[i].address] != 0) ans[i] = m[a[i].address];
			else ans[i] = FAIL;
		}
	}
	for(int i = 1; i <= n; i++){
		if(ans[i] == FAIL) cout << "FAIL";
		else if(ans[i] == OK) cout << "OK";
		else if(ans[i] == ERR) cout << "ERR";
		else cout << ans[i];
		cout << endl;
	}
	return 0;
}