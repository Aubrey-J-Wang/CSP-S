//GA + dfs +bfs
//https://www.luogu.com.cn/problem/P3916
#include <bits/stdc++.h>
using namespace std;

int n, e;
int ga[100][100];
bool visited[100];
bool inque[100];

void dfs(int x);
void bfs(int x);

int main(){
   int u, v;
   cin >> n >> e;
   
   while (e--){
      cin >> u >> v;
	  ga[u][v] = ga[v][u] = 1;
   }
   
   dfs(1);
   bfs(1);
   
   return 0;
}

void dfs(int x){
	cout << x << " ";
	visited[x] = true;
	
	for (int i=1; i<=n; i++){
		if (ga[x][i]==1 && !visited[i])
		   dfs(i);
	}
	cout<<endl; 
}

void bfs(int x){
	queue<int> q;
	q.push(x);
	inque[x]=true;
	
	while (!q.empty()){
		int k;
		k = q.front();
		for (int i=1; i<=n; i++){
			if (ga[k][i]==1 && !inque[i]){
				q.push(i);
				inque[i]=true; 
			}
		}
		cout << k << " ";
		q.pop(); 
	}
	cout << endl;
}
