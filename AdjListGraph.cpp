#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 1. Create a concrete class that inherits from Graph
class AdjListGraph : public Graph {
private:
    // Storing edges as pairs of {neighbor_node, weight}
    vector<vector<pair<int, int>>> adjList;

public:
    // Constructor initializes the base Graph class and sizes the vector
    AdjListGraph(int vertices, GType gt = DIRECTED) 
        : Graph(vertices, 0, gt) {
        adjList.resize(vertices);
    }

    // Implement the missing pure virtual functions
    bool isEdge(int u, int v) const override {
        for (const auto& edge : adjList[u]) {
            if (edge.first == v) return true;
        }
        return false;
    }

    void toggleEdge(int u, int v) override {
        // Basic toggle logic or leave empty if you prefer manual adds
    }

    // Helper function to easily add weighted edges
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        e++; // Increment edge count in base class
    }

    // Getter to access neighbors during Dijkstra
    const vector<pair<int, int>>& getNeighbors(int u) const {
        return adjList[u];
    }

protected:
    ostream& print(ostream& os) const override {
        for (int i = 0; i < v; ++i) {
            os << i << ": ";
            for (const auto& edge : adjList[i]) {
                os << "-> (" << edge.first << ", w:" << edge.second << ") ";
            }
            os << "\n";
        }
        return os;
    }
};