#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>


using namespace std;

struct Edge {
    string destination;
    int weight;
};

struct Node {
    string vertex;
    int cost;
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

pair<int, vector<string>> dijkstra(const unordered_map<string, vector<Edge>> &graph, const string &start, const string &end) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    unordered_map<string, int> distances;
    unordered_map<string, string> previous;

    for (const auto &pair : graph) {
        distances[pair.first] = numeric_limits<int>::max();
    }

    distances[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.vertex == end) {
            vector<string> path;
            string step = end;
            while (!step.empty()) {
                path.push_back(step);
                step = previous[step];
            }
            reverse(path.begin(), path.end());
            return {distances[end], path};
        }

        for (const Edge &neighbor : graph.at(current.vertex)) {
            int new_cost = distances[current.vertex] + neighbor.weight;

            if (new_cost < distances[neighbor.destination]) {
                distances[neighbor.destination] = new_cost;
                previous[neighbor.destination] = current.vertex;
                pq.push({neighbor.destination, new_cost});
            }
        }
    }

    return {-1, {}}; 
}

int main() {
    unordered_map<string, vector<Edge>> graph = {
        {"A", {{"B", 1}, {"C", 4}}},
        {"B", {{"A", 1}, {"C", 2}, {"D", 5}}},
        {"C", {{"A", 4}, {"B", 2}, {"D", 1}}},
        {"D", {{"B", 5}, {"C", 1}}}
    };

    string initial_node, final_node;
    cout << "Enter the starting node: ";
    cin >> initial_node;
    cout << "Enter the ending node: ";
    cin >> final_node;

    auto result = dijkstra(graph, initial_node, final_node);

    if (result.first != -1) {
        cout << "The shortest path from " << initial_node << " to " << final_node << " and the cost is " << result.first << ".\n";
        cout << "The path is: ";
        for (size_t i = 0; i < result.second.size(); i++) {
            cout << result.second[i];
            if (i < result.second.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "There is no path from " << initial_node << " to " << final_node << "." << endl;
    }

    return 0;
}
