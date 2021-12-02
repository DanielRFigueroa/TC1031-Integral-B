
#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

class Graph {
private:
    int edgesList;
    int edgesMat;
    int nodes;
    vector<int> *adjList;
    int *adjMatrix;

public:

    Graph();

    void loadGraphMat( string, int, int);
    void loadGraphList(const string&, int, int);
	void addEdgeAdjList(int, int);
    void addEdgeAdjMatrix(int, int);

    string printAdjMat();
	string printAdjMat_clean();
    string printAdjList();
    //bool BFS(int src, int dest, int v, int pred[], int dist[]);
    string BFS(int, int);
    void BFSHelper(int, int, queue<int> &, list<int> &, vector<vector<int> > &, stringstream &);
    //void printShortestDistance(int s, int dest, int v);
    static void printPath(vector<vector<int> > &, int, int, stringstream &);
    static void printVisited(list<int>, stringstream &);
    static bool contains(list<int>, int);
    void sortAdjList();

};

Graph::Graph() {
    edgesList = edgesMat = nodes = 0;
}

void Graph::loadGraphMat(string file_name, int a, int b) {
    adjMatrix = new int[a * b];
    nodes = a;
    for (int i = 0; i < a * b; i++)
        adjMatrix[i] = 0;
		string line;
		ifstream archivo(file_name);
		int u, v;
		if (archivo.is_open()) {
			while (getline(archivo, line)) {
				u = stoi(line.substr(1, 1));
				v = stoi(line.substr(4, 1));
				addEdgeAdjMatrix(u, v);
			}
			archivo.close(); 
		} else	cout << "Unable to open file";
}

void Graph::loadGraphList(const string &file_name, int a, int b) {
    nodes = a;
    adjList = new vector<int>[nodes];

    string line;
    ifstream archivo(file_name);
    int u, v;
    if (archivo.is_open()) {
        while (getline(archivo, line)) {
              u = stoi(line.substr(1, 1));
              v = stoi(line.substr(4, 1));
              addEdgeAdjList(u, v);
        }
        archivo.close();
    } else{
		cout << "Unable to open file";
	}
}

void Graph::addEdgeAdjList(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    edgesList++;
}

void Graph::addEdgeAdjMatrix(int u, int v) {
    adjMatrix[u * nodes + v] = 1;
    adjMatrix[v * nodes + u] = 1;
    edgesMat++;
}

string Graph::printAdjList(){
	sortAdjList();
	stringstream aux;
	for (int i = 0; i < nodes; i++){
		aux << "vertex "
				<< i << " :";
		for (int j = 0; j < adjList[i].size(); j ++){
							aux << " " << adjList[i][j];
				}
		aux << " ";
	}
	return aux.str();

}

string Graph::printAdjMat() {
    stringstream aux;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            aux << adjMatrix[i * nodes + j] << " ";
		}
	}
    return aux.str();
}

string Graph::printAdjMat_clean(){
	stringstream aux;
	aux << "\n nodes \t|";
	for (int i = 0; i < nodes; i++){
			aux << "\t" << i ;
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
			aux << "__________";
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
		 aux << i << "\t|";
	   for (int j = 0; j < nodes; j++){
			 aux << "\t" << adjMatrix[i*nodes+j];
		 }
	   aux << "\n";
  }
	return aux.str();
}


/*bool Graph::BFS(int src, int dest, int v, int pred[], int dist[])
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;
 
    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];
 
    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT8_MAX;
        pred[i] = -1;
    }
 
    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
 
    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adjList[u].size(); i++) {
            if (visited[adjList[u][i]] == false) {
                visited[adjList[u][i]] = true;
                dist[adjList[u][i]] = dist[u] + 1;
                pred[adjList[u][i]] = u;
                queue.push_back(adjList[u][i]);
 
                // We stop BFS when we find
                // destination.
                if (adjList[u][i] == dest)
                    return true;
            }
        }
    }
 
    return false;
}
 
// utility function to print the shortest distance
// between source vertex and destination vertex
void Graph::printShortestDistance(int s,
                           int dest, int v)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[v], dist[v];
 
    if (BFS(s, dest, v, pred, dist) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }
 
    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
 
    // distance from source is in distance array
    cout << "La Ruta que tomara el taxi es: "
         << dist[dest]<<" rutas";
 
    // printing path from source to destination
    cout << "\nLa Ruta es::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}*/


string Graph::BFS(int start, int target) {
    stringstream aux;

    queue<int> queue;
    list<int> visited;
    vector<vector<int> > paths(nodes, vector<int>(0));
    queue.push(start);

    BFSHelper(start, target, queue, visited, paths, aux);
    printPath(paths, start, target, aux);
 
    return aux.str();
}

void Graph::BFSHelper(int current, int target, queue<int> &queue, list<int> &visited, vector<vector<int> > &paths, stringstream &aux) {

    if (current == target){
		printVisited(visited, aux);
	} else if (queue.empty()){
		aux << "";
     } else {
        current = queue.front();
        queue.pop();
        visited.push_back(current);
        for (int i = 0; i < adjList[current].size(); i++) {
            if (!contains(visited, adjList[current][i])) {
                queue.push(adjList[current][i]);
                paths[adjList[current][i]].push_back(current);
            }
		}
        BFSHelper(current, target, queue, visited, paths, aux);
    }
}






void Graph::printVisited(list<int> visited, stringstream &aux) {
    aux << "visited: ";
    while (!visited.empty()) {
        aux << visited.front() << " ";
        visited.pop_front();
    }
}

void Graph::printPath(vector<vector<int> > &path, int start, int target, stringstream &aux) {
    aux << "path: ";
    int node = path[target][0];

    stack<int> reverse;
    reverse.push(target);

    while (node != start) {
        reverse.push(node);
        node = path[node][0];
    }

    reverse.push(start);
    while (!reverse.empty()) {
        aux << reverse.top();
        reverse.pop();
        if (!reverse.empty()){
			aux << " ";
		}
    }
}

void Graph::sortAdjList() {
    for (int i = 0; i < nodes; i++){
		sort(adjList[i].begin(), adjList[i].end());
	}
}

bool Graph::contains(list<int> lista, int node) {
    list<int>::iterator it;
    it = find(lista.begin(), lista.end(), node);

    if (it != lista.end()){
		return true;
	} else {
		return false;
	}
}
/*int citytonumber(string city) {

    int auxi;

    if (city=="ALAMEDA")
    {
        auxi=0;
        return auxi;
    }

    else if (city=="LOS ARCOS")
    {
        auxi=1;
        return auxi;
    }

    else if (city=="ANTEA")
    {
        auxi=2;
        return auxi;
    }

    else if (city=="EL REFUGIO")
    {
        auxi=3;
        return auxi;
    }

    else if (city=="JURIQUILLA")
    {
        auxi=4;
        return auxi;
    }
    else if (city=="TEC MTY")
    {
        auxi=5;
        return auxi;
    }
    else if (city=="ANAHUAC")
    {
        auxi=6;
        return auxi;
    }
    else if (city=="MILENIO")
    {
        auxi=7;
        return auxi;
    }
    else if (city=="PASEO QUERETARO")
    {
        auxi=8;
        return auxi;
    }
    else if (city=="PLAZA BOULEVARES")
    {
        auxi=9;
        return auxi;
    }

return 0;

} */

#endif