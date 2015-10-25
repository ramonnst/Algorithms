import java.util.ArrayList;

public class DFS{ 
	public static void main(String[] args) {
	
		Graph g = new Graph(7);

		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(0, 3);

		g.addEdge(1, 5);
		g.addEdge(1, 6);

		g.addEdge(2, 4);

		g.addEdge(3, 2);
		g.addEdge(3, 4);

		g.addEdge(4, 1);

		g.addEdge(6, 4);

		g.DFS();
	}
}

class Graph {
	
	private ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>();
	private int size;
	
	public Graph(int N) {
		this.size = N;
		
		for(int i = 0; i < N; ++i) {
			adjList.add(new ArrayList<Integer>());
		}
	}
	
	public void addEdge(final Integer u, final Integer v) {
		
		adjList.get(u).add(v);
	}
	
	public void DFS() {
		
		boolean visited[] = new boolean[this.size];
		
		for(int i = 0; i < this.size; ++i) {
			visited[i] = false;
		}
		
		System.out.println("DFS: ");
		
		for(int i = 0; i < this.size; ++i) {
			
			if(!visited[i]) {
				DFShelper(visited, i);
			}
		}
		System.out.println();
	}
	
	public void DFShelper(boolean visited[], final int node) {
		
		visited[node] = true;
		
		System.out.print(node + " ");
		
		for(Integer adjNode : adjList.get(node)) {
			
			if(!visited[adjNode]) {
				DFShelper(visited, adjNode);
			}
		}
	}
	
	
}