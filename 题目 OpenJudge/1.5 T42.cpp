#include<bits/stdc++.h>
using namespace std;
int main(){   
    int a, b, d; char c;           
    cin >> a >> b >> c >> d;
 	if(d){
        for(int j = 1; j <= a; j++){
		    for(int i = 1; i <= b; i++) cout << c;
	        printf("\n");
        }
    }else{
        for(int j = 1; j <= a; j++){	  
		    for(int i = 1; i <= b; i++){
                if(j==1 || j==a || i==1 || i==b) cout << c;
	            else printf(" ");
            }
            printf("\n");
         }
    }
    return 0;
}
