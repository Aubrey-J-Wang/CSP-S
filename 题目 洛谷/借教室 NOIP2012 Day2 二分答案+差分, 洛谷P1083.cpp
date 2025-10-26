//借教室 NOIP2012 Day2 二分答案+差分
//洛谷P1083
//https://www.luogu.com.cn/problem/list?keyword=1083
#include<iostream>
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#define N 1001000 
using namespace std; 

struct node {
   int x, y, z; 
} q[N]; 

int n, m, ans=0, a[N], b[N]; 

int in(){
   int x=0;
   char ch = getchar(); 

   while (ch<'0' || ch>'9') 
      ch = getchar( ); 
   
   while (ch>='0' && ch<='9')  
      x=x*10+ch-'0', ch = getchar( ); 
   return x; 
} 

bool judge(int x){ 
   memset( b, 0, sizeof(b) ); 
   int s=0; 
   bool f=true;

   for (int i=1; i<=x; i++) 
      b[q[i].x]+=q[i].z,b[q[i].y+1]-=q[i].z; 
   
   for (int i=1; i<=n; i++){ 
      s += b[i]; 
      if (s>a[i]){ 
        f = false; 
        break; 
      } 
   } 

   return f; 
} 

int main() { 
   n = in(), m = in(); 

   for (int i=1; i<=n; i++)  
      a[i] = in(); 

   for (int i=1; i<=m; i++) 
      q[i].z = in(), q[i].x = in(), q[i].y = in(); 

   int l = 1, r = m; 
   while (l<=r){ 
      int mid = (l+r)>>1; 
      if ( !judge(mid) ) 
         ans =mid, r = mid-1; 
      else 
         l=mid+1;
   } 

   if ( !ans ) 
      printf("0\n"); 
   else
      printf("-1\n%d\n", ans); 

   return 0;
}
 
 
