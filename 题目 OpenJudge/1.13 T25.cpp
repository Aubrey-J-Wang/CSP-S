#include<bits/stdc++.h>
using namespace std;
int main(){
	int mo[] = {0, 31, 28, 31 ,30, 31, 30, 31, 31, 30, 31, 30, 31};
	int sty, stm, stD, eny, enm, enD, cnt = 0, extr = 0;
	cin >> sty >> stm >> stD >> eny >> enm >> enD;
	for(int i = sty; i < eny; i++){
		cnt += 365;
		if((i%4 == 0 && i%100) || i%400 == 0) cnt++;
	}
	for(int i = 1; i < enm; i++) cnt += mo[i];
	if(enm > 2){
		if((eny%4 == 0 && eny%100) || eny%400 == 0) cnt++;
	}
	cnt += enD;
	for(int i = 1; i < stm; i++) extr += mo[i];
	if(stm > 2){
		if((sty%4 == 0 && sty%100) || sty%400 == 0) extr++;
	}
	extr += stD;
	cnt -= extr;
	cout << cnt;
	return 0;
}