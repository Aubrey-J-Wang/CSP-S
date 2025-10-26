//ABC 319 D - Minimum Width
//https://atcoder.jp/contests/abc319/tasks/abc319_d

#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<long> L(N);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
        ++L[i]; // Prepend a space
    }
    
    long lower = ranges::max(L) - 1; // The answer is at least max L[i]
    long upper = reduce(begin(L), end(L)); // The answer is at most ¡Æ L[i]
    // Binary search
    while (lower + 1 < upper) {
        long middle = (lower + upper) / 2;
        int rows = 1; // Index of current line
        long length = 0; // Position in the line
        for (int i = 0; i < N; ++i) {
            length += L[i]; // Try to append to the end of the line
            if (length > middle) { // If it sticks out
                ++rows; // add a newline
                length = L[i]; // and append to the beginning
            }
        }
        if (rows > M) // If the height is large enough
    		lower = middle; // then the answer is strictly greater than middle;
        else
			upper = middle; // otherwise, the answer is less than or equal to middle
    }
    
    // Print the answer subtracted by one
    cout << upper-1;
    return 0;
}