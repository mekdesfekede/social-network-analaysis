#include <iostream>
#include "graph.h"

int main() {
    Graph g;

    // Adding nodes
    g.addNode(1);
    g.addNode(2);
    g.addNode(3);
    g.addNode(4);

    // Adding edges
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 1);

    std::cout << "DFS Traversal starting from node 1: ";
    g.DFS(1);
    std::cout << std::endl;

    std::cout << "BFS Traversal starting from node 1: ";
    g.BFS(1);
    std::cout << std::endl;

    std::cout << "Shortest path from node 1: " << std::endl;
    g.shortestPath(1);

    return 0;
}


///#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <list>
#include <queue>
#include <limits>
#include <iostream>

class Graph {
public:
    // Adjacency list representation
    std::unordered_map<int, std::list<std::pair<int, int>>> adjList;

    // Add a node
    void addNode(int node);

    // Delete a node
    void deleteNode(int node);

    // Add an edge with weight
    void addEdge(int u, int v, int weight);

    // Update weight of an edge
    void updateWeight(int u, int v, int newWeight);

    // Depth First Search (DFS)
    void DFS(int start);

    // Breadth First Search (BFS)
    void BFS(int start);

    // Shortest Path using Dijkstra's Algorithm
    void shortestPath(int start);

private:
    void DFSUtil(int node, std::unordered_map<int, bool>& visited);
};

#endif // GRAPH_H
///#include "graph.h"

// Add a node
void Graph::addNode(int node) {
    adjList[node]; // Creates an empty list for the node
}

// Delete a node
void Graph::deleteNode(int node) {
    adjList.erase(node);
    for (auto& pair : adjList) {
        pair.second.remove_if([node](const std::pair<int, int>& edge) { return edge.first == node; });
    }
}

// Add an edge with weight
void Graph::addEdge(int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight}); // For undirected graph
}

// Update weight of an edge
void Graph::updateWeight(int u, int v, int newWeight) {
    for (auto& edge : adjList[u]) {
        if (edge.first == v) {
            edge.second = newWeight;
        }
    }
    for (auto& edge : adjList[v]) {
        if (edge.first == u) {
            edge.second = newWeight;
        }
    }
}

// Depth First Search (DFS)
void Graph::DFS(int start) {
    std::unordered_map<int, bool> visited;
    DFSUtil(start, visited);
}

void Graph::DFSUtil(int node, std::unordered_map<int, bool>& visited) {
    visited[node] = true;
    std::cout << node << " ";

    for (auto& edge : adjList[node]) {
        if (!visited[edge.first]) {
            DFSUtil(edge.first, visited);
        }
    }
}

// Breadth First Search (BFS)
void Graph::BFS(int start) {
    std::unordered_map<int, bool> visited;
    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";

        for (auto& edge : adjList[node]) {
            if (!visited[edge.first]) {
                visited[edge.first] = true;
                q.push(edge.first);
            }
        }
    }
}

// Shortest Path using Dijkstra's Algorithm
void Graph::shortestPath
