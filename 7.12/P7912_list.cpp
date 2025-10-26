#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 2e5+10;

struct Node {
	int prev;
	int value;
	int next;
} headList[MAXN], fruitList[MAXN];

int fruit[MAXN], num_max;

void take(int pos) {
	int prev = fruitList[pos].prev;
	int next = fruitList[pos].next;
	fruitList[prev].next = next;
	fruitList[next].prev = prev;
	cout << pos << ' ';
}

void delete_node(int pos) {
	int prev = headList[pos].prev;
	int next = headList[pos].next;
	headList[prev].next = next;
	headList[next].prev = prev;
}

void pile() {
	int stray = headList[0].next;
	int current = fruit[headList[stray].value]; // Current type.
	
	while(stray != num_max + 1) { // num_max: The number of the biggest pile.
		if(fruit[headList[stray].value] != current) {
			delete_node(stray);
			stray = headList[stray].next;
			continue;
		}
		
		take(headList[stray].value);
		headList[stray].value = fruitList[headList[stray].value].next;
		
		if(fruit[headList[stray].value] != current) delete_node(stray);
		stray = headList[stray].next, current = !current;
	}
	
	putchar('\n');
}

int main() {
	int n;
	cin >> n;
	fruitList[0].next = 1;
	
	for(int i = 1; i <= n; i++) {
		cin >> fruit[i];
		fruitList[i].prev = i - 1;
		fruitList[i].next = i + 1;
	}
	
	fruit[0] = fruit[n + 1] = 2;
	headList[0].next = 1;
	
	for(int i = 1; i <= n; i++) { // Double list in piles.
		if(fruit[i] != fruit[i - 1]) {
			num_max++;
			headList[num_max].prev = num_max - 1;
			headList[num_max].next = num_max + 1;
			headList[num_max].value = i;
		}
	}
	
	while(fruitList[0].next != n + 1)
		pile();
		
	return 0;
}


