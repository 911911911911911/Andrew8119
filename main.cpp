#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

unordered_map<char, unordered_map<char, int>> graph;

unordered_map<char, int> dijkstra(char start) {
    unordered_map<char, int> distances;
    for (const auto& pair : graph) {
        distances[pair.first] = INT_MAX;
    }
    distances[start] = 0;

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        char current = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (distance > distances[current]) {
            continue;
        }

        for (const auto& neighbor : graph[current]) {
            int new_distance = distance + neighbor.second;
            if (new_distance < distances[neighbor.first]) {
                distances[neighbor.first] = new_distance;
                pq.push({new_distance, neighbor.first});
            }
        }
    }

    return distances;
}

int main() {
    graph['A'] = {{'B', 10}, {'D', 2}};
    graph['B'] = {{'A', 10}, {'C', 3}, {'E', 7}};
    graph['C'] = {{'B', 3}, {'F', 1}};
    graph['D'] = {{'A', 2}, {'E', 7}};
    graph['E'] = {{'B', 7}, {'D', 7}, {'F', 1}};
    graph['F'] = {{'C', 1}, {'E', 1}};

    unordered_map<char, int> distances = dijkstra('A');

    for (const auto& pair : distances) {
        cout << "Distance to " << pair.first << " from A: " << pair.second << endl;
    }

    return 0;
}
