//2024 ��Ϣ��δ��ʡ�� T4��ͼ���걸 
//https://www.luogu.com.cn/problem/B3981

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    if(n==0)  
	    cout<<"+[]";
    else{
    	int w=0,a[15];
    	while(n!=0){
    		a[++w] = n%10;
    		n/=10;
		}
		for(int i = w;i >= 1;i--){
			if(a[i]==0) cout<<"+[+[]]";
			else{
				cout<<"+[";
				for(int j = 1;j <= a[i];j++){
					cout<<"+!![]";
				}
				cout<<"]";
			}
			
		}
	}
	
	return 0;
}


