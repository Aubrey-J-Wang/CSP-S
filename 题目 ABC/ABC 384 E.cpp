//ABC 384 E - Takahashi is Slime 2
//https://atcoder.jp/contests/abc384/tasks/abc384_e
//https://atcoder.jp/contests/abc384/editorial/11608

#include <iostream>
#include <queue>
#include <ranges>
#include <vector>
#include <limits>

int main() {
	using namespace std;
	unsigned H, W;
	cin >> H >> W;

	unsigned long X;
	unsigned x, y;
	cin >> X >> x >> y;

	// Surround the grid with sentinel slimes whose strengths are too large to absorb
	// 500 ¡Á 500 ¡Á 10^12 = 2.5 ¡Á 10^19 is enough.
	vector slime_size(H + 2, vector(W + 2, 250000000000000000UL));
	// Read only the central H x W part
	for (auto &&row : slime_size | views::drop(1) | views::take(H))
		for (auto &&S : row | views::drop(1) | views::take(W))
			cin >> S;

	unsigned long now_size{slime_size[x][y]};

	vector visited(H + 2, vector(W + 2, false));

	priority_queue<tuple<unsigned long, unsigned, unsigned>, vector<tuple<unsigned long, unsigned, unsigned>>, greater<>>
	pq;
	pq.emplace(0, x, y);
	visited[x][y] = true;

	while (!pq.empty()) {
		const auto [size, x, y] = pq.top();
		pq.pop();

		// If the adjacent slime with the minimum strength is not absorbable, quit
		if (size >= (now_size + X - 1) / X)
			break;

		// Absorb the slime
		now_size += size;

		// Put slimes that are newly adjacent into the priority queue
		for (const auto &[dx, dy] : vector<pair<int, int>> {{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
		if (!visited[x + dx][y + dy]) {
			visited[x + dx][y + dy] = true;
			pq.emplace(slime_size[x + dx][y + dy], x + dx, y + dy);
		}
	}

	cout << now_size << endl;

	return 0;
}