#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;


typedef pair<int, int> iPair;

void dijkstra(unordered_map<int, unordered_map<int, int>>& graph, int source, unordered_map<int, int>& distances) {
  
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    
    
    // Initialize distances of all vertices as infinite
    for (auto& node : graph) {
        distances[node.first] = INT_MAX;
    }
    
    
    distances[source] = 0;
    
    
    pq.push(make_pair(0, source));
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        
        for (auto& adj : graph[u]) {
            int v = adj.first;
            int weight = adj.second;
            
            
            if (distances[v] > distances[u] + weight) {
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    unordered_map<int, unordered_map<int, int>> graph = {
        {0, {{1, 4}, {2, 1}}},
        {1, {{3, 1}}},
        {2, {{1, 2}, {3, 5}}},
        {3, {}}
    };
    
    int source = 0;
    unordered_map<int, int> distances;
    
    dijkstra(graph, source, distances);
    
    // Print the shortest distances from source to all vertices
    for (auto& dist : distances) {
        cout << "Distance from source " << source << " to vertex " << dist.first << " is " << dist.second << endl;
    }
    
    return 0;
}
