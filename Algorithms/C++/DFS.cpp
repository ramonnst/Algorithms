#include <iostream> // cout
#include <vector>  // vector
#include <cstdio> // fprintf
#include <cstdlib> // exit()
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

	bool usingFiles = false;

	if(usingFiles == false) {


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
	}
	else {

		FILE *fIN;

		if(argc != 2) {
			fprintf(stderr, "Usage: ./DFS <fileName> \n");
			exit(0);
		}


		if((fIN = fopen(argv[1],"r")) == NULL) {
			fprintf(stderr, "Can't open file %s\n", argv[1]);
			exit(0);
		}

		int N, M, x, y;
		fscanf(fIN, "%d %d", &N, &M);


		Graph *gp = new Graph(N);

		for(int i = 0; i < M; ++i) {

			fscanf(fIN, "%d %d", &x, &y);
			gp->addEdge(x, y);
		}

		gp->DFS();
	}
	return 0;
}