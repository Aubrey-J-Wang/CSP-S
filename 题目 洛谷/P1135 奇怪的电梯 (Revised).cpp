#include <iostream>
using namespace std;
struct q_node{
	int floor;
	int num; //Step counter.
} q[201];
int n, a, b, i, x;
int k[201]; //n is the total num of the floors, a is the beginning floor, b is the target.
bool visited[201];
int main(){
//	freopen("lift.in", "r", stdin); //We do not have to read and print from and to a file.
//	freopen("lift.out", "r", stdout);
	cin >> n >> a >> b; //Input.
	for (i = 1; i <= n; i++) cin >> k[i]; //The num on each floor.
	if (a == b){ //If target = beginning...
		cout << 0;
		return 0;
	}
	q[1].floor = a;
	q[1].num = 0;
	visited[a] = true; //Of course a is visited.(a is the begin floor)
	int f = 1, r = 1; // f: front, r: rear; Simulating a queue. r is also the step recorder (NOT counter).
	while (f <= r) {  //WFS, Width-first Search
		int temp = q[f].floor + k[q[f].floor]; //The floor if go up.
		if (temp <= n && not visited[temp]){ //If below the top lev & this lev is not visited.
			r++; //We consider this as a legitimate move, therefore adding an element into the queue by adding r.
			q[r].floor = temp; //Record.
			q[r].num = q[f].num + 1; //Add step.
			visited[temp] = true;
			if (temp == b) break; //If reached the target, break the loop.
		}
		temp = q[f].floor - k[q[f].floor]; //The floor if go down.
		if (temp > 0 && not visited[temp]){ //If above the bottom lev & this lev is not visited.
			r++; //Same as line 26.
			q[r].floor = temp; //Same.
			q[r].num = q[f].num + 1;
			visited[temp] = true;
			if (temp == b) break; //Same.
		}
		f++; //Push the 1st element out by adding f.
	}
	if (f <= r) cout << q[r].num << endl; //Print if the queue's length is still legitimate (f <= r)
	else cout << -1 << endl; //Else, no way to.
//	fclose(stdin); //Same as line 12.
//	fclose(stdout);
	return 0;
}