#include <iostream>
#include <vector>
using namespace std;

class Graph {
	vector<int> head;
	struct Edge{
		int to;
		int next;
		int weight;
	};
	vector<Edge> edge;
	int num_edge = 1;
public:
	Graph(int num_vertex){
		head.resize(num_vertex, -1);
		edge.push_back(Edge(0, 0, 0));
	}
	Graph(){
		head.resize(10005, -1);
		edge.push_back(Edge(0, 0, 0));
	}
	void add_edge(int u, int v) {
		edge.push_back(Edge(v, head[u], 0));
		head[u] = edge.size()+1;
	}
	void add_edge(int u, int v, int w) {
		edge.push_back(Edge(v, head[u], w));
		head[u] = edge.size()+1;
	}
};

int main(){
	
	return 0;
}
