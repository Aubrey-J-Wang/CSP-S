#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, rating[15000], sum[15000][2]; //sum[x][1]: Total rating when x attends or: sum[x][1]: When x does not attend.
bool vi[15000]; //v[i]: Whether i has a father.
vector<vector<int> > son(15000); //Every son of x.

void dp(int x){
	sum[x][0] = 0; //If x does not attend.
	sum[x][1] = rating[x]; //If he does, then at least we can get his rating.
	
	for(int i = 0; i < son[x].size(); i++){
		int y = son[x][i]; //We look at every son of x.
		dp(y);
		sum[x][0] += max(sum[y][0], sum[y][1]);
//		If x does not attend, his son(s) can attend or not attend. So find the maximum rating of the two to add.
		sum[x][1] += sum[y][0]; //If he does, his son(s) must not attend. So add the rating we get when they do not attend.
	}
}

int main() {
    ios::sync_with_stdio(false);
    
    int l, k, root = 0;
    
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> rating[i];
    
    for(int i = 1; i < n; i++){
    	cin >> l >> k; //Son & Father
    	vi[l] = true; //Of course, every son has a father.
    	son[k].push_back(l);
	}
	
	for(int i = 1; i <= n; i++){
		if(not vi[i]){
//			But if one does not have a father, he is surely the root of the tree (i.e. The president of the university).
			root = i;
			break;
		}
	}
	
	dp(root);
	
	cout << max(sum[root][0], sum[root][1]); //We finally determine whether the president should attend.
	return 0;
}
