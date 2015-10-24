#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
	vector<int> *_adjList;
	int _maxSize;
	int _size;

public:
	Graph(int N): _maxSize(N), _size(0) {
		_adjList = new vector<int>[N];
	}
	~Graph() {delete _adjList;}

	void addEdge(const int& u, const int& v) {
		_adjList[u].push_back(v);
	}

	void DFS() {

		bool *visited = new bool[_maxSize + 1];

		for(int i = 0; i < _maxSize; ++i) {
			visited[i] = false;
		}

		cout << "DFS: ";
		for(int i = 0; i < _maxSize; ++i) {

			if(!visited[i]) {

				DFShelper(visited,i);
			}
		}
		cout << endl;
	}

	void DFShelper(bool *visited, const int& node) {

		visited[node] = true;

		cout << node << ' ';

		for(vector<int>::const_iterator it = _adjList[node].begin();
			it != _adjList[node].end(); ++it ) {

			if(!visited[*it]) {
				DFShelper(visited, *it);
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	Graph *g = new Graph(7);

	g->addEdge(0, 1);
	g->addEdge(0, 2);
	g->addEdge(0, 3);


	g->addEdge(1, 5);
	g->addEdge(1, 6);


	g->addEdge(2, 4);


	g->addEdge(3, 2);
	g->addEdge(3, 4);

	g->addEdge(4, 1);


	g->addEdge(6, 4);


	g->DFS();


	return 0;
}