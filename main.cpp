// Implement main program.
#include "AdjListGraph.cpp"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

AdjListGraph* g = new AdjListGraph(6, Graph::DIRECTED);

void dijkstra(Graph* graph, int n){
    // 1. Cast the base pointer to our concrete derived class
    AdjListGraph* g = dynamic_cast<AdjListGraph*>(graph);
    if (!g) {
        cout << "Invalid graph type provided to Dijkstra." << endl;
        return;
    }

    int V = g->numVertices();
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    // Min-priority queue storing pairs of {distance, vertex_id}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize Source
    dist[n] = 0;
    pq.push({0, n});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        // Loop through all neighbors using our getter
        for (const auto& edge : g->getNeighbors(u)) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print out the results for the lab assignment
    cout << "Shortest distances from source node " << n << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "  To Node " << i << ": ";
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    cout << "------------------------------------\n";
}
  

int main(){

    AdjListGraph* g = new AdjListGraph(6, Graph::DIRECTED);

    g->addEdge(0, 1, 4);
    g->addEdge(0, 2, 9);
    g->addEdge(0, 4, 2);
    
    g->addEdge(1, 2, 2);
    g->addEdge(1, 3, 1);
    
    g->addEdge(2, 3, 7);
    g->addEdge(2, 5, 4);
    
    g->addEdge(3, 5, 1);
    
    g->addEdge(4, 2, 3);
    g->addEdge(4, 5, 8);

    cout << *g << endl;

    dijkstra(g, 0);

    dijkstra(g, 1);

    delete g;
    return 0;

}


void createGraph(Graph*& gPtr) {
    bool b    = false;
    int  numV = 0;

    do {
        cout << "Enter how many vertices are in the graph: ";
        cin  >> numV;
    } while (numV <= 0);

    cout << "Enter 0 for undirected or 1 for directed: ";
    cin  >> b;

    delete gPtr;
    gPtr = new AdjListGraph(numV, static_cast<Graph::GType>(b));
}

void checkGraphType(Graph* gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
    }
    else if (gPtr->getGraphType() == Graph::UNDIRECTED) {
        cout << "The graph is undirected\n";
    }
    else if (gPtr->getGraphType() == Graph::DIRECTED) {
        cout << "The graph is directed\n";
    }
    else {
        cout << "The graph is unknown :(\n";
    }
}

void displayNumV(Graph* gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
    }
    else {
        cout << "Number of vertices: ";
        cout << gPtr->numVertices() << endl;
    }
}

void displayNumE(Graph* gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
    }
    else {
        cout << "Number of edges: ";
        cout << gPtr->numEdges() << endl;
    }
}

void checkEdge(Graph* gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
        return;
    }

    int v1 = 0, v2 = 0;

    cout << "Enter the first vertex: ";
    cin  >> v1;

    cout << "Enter the second vertex: ";
    cin  >> v2;

    if (gPtr->isEdge(v1, v2)) {
        cout << "The edge from " << v1
             << " to " << v2 << " exists!\n";
    }
    else {
        cout << "The edge from " << v1
             << " to " << v2 << " does not exist.\n";
    }
}

void toggleEdge(Graph*& gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
        return;
    }

    int v1 = 0, v2 = 0;

    cout << "Enter the first vertex: ";
    cin  >> v1;

    cout << "Enter the second vertex: ";
    cin  >> v2;

    gPtr->toggleEdge(v1, v2);
}

void printGraph(Graph* gPtr) {
    if (gPtr == nullptr) {
        cout << "You must create a graph first!\n";
    }
    else {
        cout << *gPtr;
    }
}
