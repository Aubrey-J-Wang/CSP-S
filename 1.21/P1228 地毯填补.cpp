#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int board[64+1][64+1];
int tile;

void chessboard(int tr, int tc, int dr, int dc, int size){
	int t, s;
	
	if(size == 1) return;
	t = tile, tile++;
	s = size/2;
	
	if(dr < tr+s and dc < tc+s) chessboard(tr, tc, dr, dc, s);
	else{
		board[tr+s-1][tc+s-1] = t;
		chessboard(tr, tc, tr+s-1, tc+s-1, s);
	}
	
	if(dr < tr+s and dc >= tc+s) chessboard(tr, tc+s, dr, dc, s);
	else{
		board[tr+s-1][tc+s] = t;
		chessboard(tr, tc+s, tr+s-1, tc+s, s);
	}
	
	if(dr >= tr+s and dc < tc+s) chessboard(tr+s, tc, dr, dc, s);
	else{
		board[tr+s][tc+s-1] = t;
		chessboard(tr+s, tc, tr+s, tc+s-1, s);
	}
	
	if(dr >= tr+s and dc >= tc+s) chessboard(tr+s, tc+s, dr, dc, s);
	else{
		board[tr+s][tc+s] = t;
		chessboard(tr+s, tc+s, tr+s, tc+s, s);
	}
}

int main() {
	int size, dr, dc;
	
	cout << "Input size(4/8/16/32/64):\n";
    cin >> size;
    cout << "Input the position if the special block(x, y):\n";
    cin >> dr >> dc;
    
    board[dr][dc] = 0;
    tile = 1;
    
    chessboard(1, 1, dr, dc, size);
    
    for(int i = 1; i <= size; i++){
    	for(int j = 1; j <= size; j++) printf("%4X", board[i][j]);
    	cout << endl;
	}
	return 0;
}
