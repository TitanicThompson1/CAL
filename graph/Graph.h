/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <fstream>
#include "MutablePriorityQueue.h"
#include "VerticeNotFound.h"

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

template <class T>
class Vertex {
	T info;                // contents
	vector<Edge<T> > adj;  // outgoing edges
	bool visited;          // auxiliary field
	double dist = 0;
	Vertex<T> *path = nullptr;
	double x, y;
	int queueIndex = 0; 		// required by MutablePriorityQueue
	int heuristic = 0;          //Used in A* algorithm
    double gValue = 0;

    void addEdge(Vertex<T> *dest, double w);

public:


	Vertex(T in);
	Vertex(T in, double x, double y);
	bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
	T getInfo() const;
	double getDist() const;
	Vertex *getPath() const;
	friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>>;

    const vector<Edge<T>> &getAdj() const;

    double getX() const;

    double getY() const;

};


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template <class T>
Vertex<T>::Vertex(T in, double x, double y): info(in), x(x), y(y) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
	adj.push_back(Edge<T>(this, d, w));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
	return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
	return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
	return this->path;
}

template<class T>
double Vertex<T>::getX() const {
    return x;
}

template<class T>
double Vertex<T>::getY() const {
    return y;
}

template<class T>
const vector<Edge<T>> &Vertex<T>::getAdj() const {
    return adj;
}

/********************** Edge  ****************************/

template <class T>
class Edge {
	Vertex<T> *orig; 	// Fp07
	Vertex<T> * dest;      // destination vertex
	double weight;         // edge weight

	bool selected; // Fp07
public:
    Vertex<T> *getOrig() const;

    Vertex<T> *getDest() const;

public:
	Edge(Vertex<T> *o, Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;

	// Fp07
	double getWeight() const;
};

template <class T>
Edge<T>::Edge(Vertex<T> *o, Vertex<T> *d, double w): orig(o), dest(d), weight(w) {}

template <class T>
double Edge<T>::getWeight() const {
	return weight;
}

template<class T>
Vertex<T> *Edge<T>::getOrig() const {
    return orig;
}

template<class T>
Vertex<T> *Edge<T>::getDest() const {
    return dest;
}


/*************************** Graph  **************************/

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set


	Vertex<T> * initSingleSource(const T &orig);
	bool relax(Vertex<T> *v, Vertex<T> *w, double weight);
	double ** W = nullptr;   // dist
	int **P = nullptr;   // path
	int findVertexIdx(const T &in) const;


public:
	Vertex<T> *findVertex(const T &in) const;
	bool addVertex(const T &in);
	bool addVertex(const T &in, double x, double y);
	bool addEdge(const T &sourc, const T &dest, double w);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;

    vector<T> getPath(const T &origin, const T &dest) const;

    ~Graph();

    //Done by us
	int calculateWeight(Vertex<T> *src, Vertex<T> *dest);
    void calculateHeuristics(T dest);
	void aStarAlgorithmGraph(T src, T dest);
	int calculatePathsize(T src, T dest);
	int euclidianDistance(Vertex<T> *src, Vertex<T> *dest);
	void exportResultsToFile(const string &filename, T src, T dest);
    void dfsRemoveUnvisited(T source) ;
    void dfsVisit(Vertex<T> *v) const;
};


template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
template <class T>
int Graph<T>::findVertexIdx(const T &in) const {
	for (unsigned i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == in)
			return i;
	return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
	if (findVertex(in) != nullptr)
		return false;
	vertexSet.push_back(new Vertex<T>(in));
	return true;
}

//Added by us
template <class T>
bool Graph<T>::addVertex(const T &in, double x, double y) {
    if (findVertex(in) != nullptr)
        return false;
    vertexSet.push_back(new Vertex<T>(in,x,y));
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == nullptr || v2 == nullptr)
		return false;
	if( w == -1)
        w = calculateWeight(v1, v2);
	v1->addEdge(v2, w);
	return true;
}


/**************** Single Source Shortest Path algorithms ************/

/**
 * Initializes single source shortest path data (path, dist).
 * Receives the content of the source vertex and returns a pointer to the source vertex.
 * Used by all single-source shortest path algorithms.
 */
template<class T>
Vertex<T> * Graph<T>::initSingleSource(const T &origin) {
	for(Vertex<T> * v : vertexSet) {
		v->dist = INF;
		v->gValue = INF;
		v->heuristic = 0;
		v->visited = false;
		v->path = nullptr;
	}
	auto s = findVertex(origin);
	if(s == NULL)
	    throw VerticeNotFound<T>(origin);
	s->dist = 0;
	s->gValue = 0;
	return s;
}

/**
 * Analyzes an edge in single source shortest path algorithm.
 * Returns true if the target vertex was relaxed (dist, path).
 * Used by all single-source shortest path algorithms.
 */
template<class T>
inline bool Graph<T>::relax(Vertex<T> *v, Vertex<T> *w, double weight) {
	if (v->dist + weight < w->dist) {
		w->dist = v->dist + weight;
		w->path = v;
		return true;
	}
	else
		return false;
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) const{
	vector<T> res;
	auto v = findVertex(dest);
	if (v == nullptr) // missing or disconnected
		return res;
	for ( ; v != nullptr; v = v->path)
		res.push_back(v->info);
	reverse(res.begin(), res.end());
	return res;
}


/**************** All Pairs Shortest Path  ***************/

template <class T>
void deleteMatrix(T **m, int n) {
	if (m != nullptr) {
		for (int i = 0; i < n; i++)
			if (m[i] != nullptr)
				delete [] m[i];
		delete [] m;
	}
}



template <class T>
Graph<T>::~Graph() {
	deleteMatrix(W, vertexSet.size());
	deleteMatrix(P, vertexSet.size());
}

/*********DONE BY US*****/

template<class T>
int Graph<T>::calculateWeight(Vertex<T> *src, Vertex<T> *dest) {
    return euclidianDistance(src,dest);
}



template<class T>
void Graph<T>::calculateHeuristics(T dest) {
    Vertex<T> *VDest = findVertex(dest);
    if(VDest == NULL)
        throw VerticeNotFound<T>(dest);

    for (auto v : vertexSet)
        v->heuristic = euclidianDistance(v, VDest);

}

template<class T>
void Graph<T>::aStarAlgorithmGraph(T src, T dest) {
    Vertex<T> * VSrc = initSingleSource(src);
    calculateHeuristics(dest);

    MutablePriorityQueue<Vertex<T>> q;
    q.insert(VSrc);

    T res;

    while( !q.empty() ) {
        auto v = q.extractMin();

        if(v->info == dest){
            break;
        }
        v->visited = true;

        for(Edge<T> e : v->adj) {
            Vertex<T> * current = e.getDest();
            double newGValue = v->gValue + e.getWeight();

            if(current->visited) continue;

            if (newGValue < current->gValue) {
                current->path = v;
                current->gValue = newGValue;
                if (current->dist == INF){
                    current->dist = current->gValue + current->heuristic;
                    q.insert(current);
                }
                else{
                    current->dist = current->gValue + current->heuristic;
                    q.decreaseKey(current);
                }
            }
        }

    }
    //cout << "Res:" << res << endl;

}

template <class T>
int Graph<T>::calculatePathsize(T src, T dest) {
    // Returns the size of a Path previously stored
    double sum = 0;
    vector<T> result = getPath(src, dest); // Gets stored path
    for(int i = 0; i < result.size() - 1; i++) {
        sum += euclidianDistance(findVertex(result.at(i)), findVertex(result.at(i+1)));
    }
    cout << result.back() << endl;

    return sum;
}

template<class T>
int Graph<T>::euclidianDistance(Vertex<T> *src, Vertex<T> *dest) {
    return sqrt(pow(dest->y - src->y, 2) + pow(dest->x - src->x, 2));
}

template<class T>
void Graph<T>::exportResultsToFile(const string &filename, T src, T dest) {
    ofstream outfile;
    outfile.open(filename, ios::app);

    vector<T> result = getPath(src, dest);

    for (auto v : result){
        outfile << v << endl;
    }
    outfile << "------------------------------" << endl;
    outfile.close();
}

/*
Function that executes a Depth-First Search in order to find all vertexes that are strongly connected to the farm (source vertex)
All unvisited vertexes are removed from the graph
*/
template<class T>
void Graph<T>::dfsRemoveUnvisited(T source) {

    // O(|V|)
    Vertex<T> * srcVertex = initSingleSource(source);

    //O(|V|)
    for (Vertex<T> * v : vertexSet)
        v->visited = false;

    //O(|E|)
    dfsVisit(srcVertex);

    //O(|V|)
    for (auto it = vertexSet.begin();  it != vertexSet.end(); it++) {
        if(!(*it)->visited) {
            it = vertexSet.erase(it);
            it--;
        }
    }

    // Total: O(|V|*|E|)
    //O(|V|)
    for (auto it = vertexSet.begin();  it != vertexSet.end(); it++) {
        vector<Edge<T>> edges = (*it)->adj;
        //O(|E|)
        for (auto itE = edges.begin(); itE != edges.end(); itE++) {
            if (!((itE)->dest->visited)) {
                edges.erase(itE);
            }
        }
    }
}
/*
 * Auxiliary function that visits a vertex (v) and its adjacent not yet visited, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v) const {
    v->visited=true;

    //O(|E|)
    for(Edge<T> e : v->adj){
        if(!e.dest->visited)
            dfsVisit(e.dest);
    }
}


#endif /* GRAPH_H_ */
