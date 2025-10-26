#include<bits/stdc++.h> //80% AC
using namespace std;

string to_hw(string s){
	for(int j = s.length()-1; j >= 0; j--){
		s += s[j];
	}
	return s;
}
bool ripe(int n){
	if(n%4 == 0 && n%100 != 0) return true;
	else if(n%400 == 0) return true;
	return false;
}
int addd(int m, int y){
	if((m < 8 && m%2 == 1) || (m > 8 && m < 13 && m%2 == 0)) return 3;
	if(m == 2){
		if(ripe(y)) return 1;
		else return 0;
	}
	return 2;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string start, end;
	int sum = 0;
	cin >> start >> end;
	int is = stoi(start.substr(0, 4)), ie = stoi(end.substr(0, 4));
	
	for(int i = is; i <= ie; i++){
		string temp = to_hw(to_string(i));
		int yr = stoi(temp.substr(0, 4)), mth = stoi(temp.substr(4, 2)), day = stoi(temp.substr(6, 2));
		if(day > addd(mth, yr)+28 || mth > 12 || mth < 1 || day < 1){
			continue;
		}
//		cout << temp << endl;
		sum++;
	}
	
	cout << sum;
	return 0;
}