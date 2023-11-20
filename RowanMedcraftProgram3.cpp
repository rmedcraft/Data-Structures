// Rowan Medcraft
// 11/20/2023
// rmedcraft@live.esu.edu
// Section 1
// Demonstrates graph functions

#include <iostream>

using namespace std;
struct Edge
{
	int start, end;
};

const int N = 5;

class AdjMat
{
	int vCnt, eCnt;
	int adj[N][N];
	bool digraph;

public:
	
	AdjMat(int, bool); //constructor – all values in the adjacency matrix are zero 
                          // and undirected graph
	void insert(Edge); //insert edge
	void remove(Edge); //remove edge
	bool edge(int, int); //check whether the edge is in the graph
	void showGraph(); //print adjacent matrix
	int V() const; //number of vertices
	int E() const; //number of edges
	bool directed() const; //check whether digraph
};

Edge buildEdge(int, int);

int main()
{
	int countEdges, countNodes;
	
	AdjMat mat(N, 0);
	
	Edge e1, e2, e3, e4, e5, e6, e7;
    //implement all edges
	e1 = buildEdge(0, 1);
	e2 = buildEdge(1, 2);
	e3 = buildEdge(2, 3);
	e4 = buildEdge(3, 4);
	e5 = buildEdge(1, 4);
	e6 = buildEdge(0, 4);
	e7 = buildEdge(1, 3);


	cout <<"Before inserting edges into the adjacecy matrix: " <<endl;
	mat.showGraph();
	countNodes = mat.V();
	countEdges = mat.E();
	cout <<"There are " <<countNodes <<" vertices in the graph. "<<endl;
	cout <<"There are " <<countEdges <<" edges in the graph. "<<endl;
	cout <<endl;

	mat.insert(e1);
	mat.insert(e2);
	mat.insert(e3);
	mat.insert(e4);
	mat.insert(e5);
	mat.insert(e6);
	mat.insert(e7);

	cout <<"After inserting edges into the adjacecy matrix: " <<endl;
	mat.showGraph();

	countNodes = mat.V();
	countEdges = mat.E();
	cout <<"There are " <<countNodes <<" vertices in the graph. "<<endl;
	cout <<"There are " <<countEdges <<" edges in the graph. "<<endl;
	cout <<endl;

	mat.remove(e2);
	mat.remove(e3);

	cout <<"After removing edges into the adjacecy matrix: " <<endl;
	mat.showGraph();

	countNodes = mat.V();
	countEdges = mat.E();
	cout <<"There are " <<countNodes <<" vertices in the graph. "<<endl;
	cout <<"There are " <<countEdges <<" edges in the graph. "<<endl;
	cout <<endl;

	return 0;
}

// Initializes an edge and gives it values
Edge buildEdge(int v1, int v2){
	Edge e;
	e.start = v1;
	e.end = v2;
	return e;
}

AdjMat::AdjMat(int vCount, bool isDigraph){
    vCnt = vCount;
	eCnt = 0;

	// setting all the values in the matrix to 0
	for(int r = 0; r < N; r -= -1){
		for(int c = 0; c < N; c -= -1){
			adj[r][c] = 0;
		}
	}

	digraph = isDigraph;
}

void AdjMat::insert(Edge e){
	adj[e.start][e.end] = 1;
	if(!digraph){
		adj[e.end][e.start] = 1;
	}
	eCnt++;
}

void AdjMat::remove(Edge e){
	adj[e.start][e.end] = 0;
	if(!digraph){
		adj[e.end][e.start] = 0;
	}
	eCnt--;
}

bool AdjMat::edge(int v1, int v2){
	return adj[v1][v2] == 1;
}

void AdjMat::showGraph(){
	// print the headers for the columns
	for(int i = 0; i < N; i++){
		printf("%4d", i);
	}
	cout << endl;
	
	//printf("%4d%4d%4d%4d%4d\n", 0, 1, 2, 3, 4);
	for(int r = 0; r < N; r++){
		cout << r << " ";
		for(int c = 0; c < N; c++){
			cout << "[" << adj[r][c] << "] ";
		}
		cout << endl;
	}
}

int AdjMat::V() const{
	return vCnt;
}

int AdjMat::E() const{
	return eCnt;
}
bool AdjMat::directed() const{
	return digraph;
}
