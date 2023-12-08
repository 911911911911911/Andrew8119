#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;

    // Рекурсивна функція для знаходження всіх шляхів між вершинами
    void findAllPathsUtil(int u, int d, bool visited[], int path[], int &pathIndex) {
        // Позначаємо поточну вершину як відвідану і додаємо її до шляху
        visited[u] = true;
        path[pathIndex] = u;
        pathIndex++;

        // Якщо ми досягли кінцевої вершини, виводимо знайдений шлях
        if (u == d) {
            for (int i = 0; i < pathIndex; i++) {
                cout << path[i] << " ";
            }
            cout << endl;
        } else {
            // Рекурсивно викликаємо функцію для сусідніх невідвіданих вершин
            for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
                if (!visited[*it]) {
                    findAllPathsUtil(*it, d, visited, path, pathIndex);
                }
            }
        }

        // Зменшуємо індекс шляху, розмічаємо вершину як невідвідану
        pathIndex--;
        visited[u] = false;
    }

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<int>[V];
    }

    // Додаємо ребро до графа
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Функція для знаходження всіх шляхів між двома вершинами
    void findAllPaths(int s, int d) {
        // Масив для відстеження відвіданих вершин
        bool *visited = new bool[V];
        // Масив для зберігання поточного шляху
        int *path = new int[V];
        // Індекс поточного шляху
        int pathIndex = 0;

        // Ініціалізуємо масив відвіданих вершин
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        // Викликаємо рекурсивну функцію для знаходження шляхів
        findAllPathsUtil(s, d, visited, path, pathIndex);
    }
};

int main() {
    // Створюємо граф та додаємо ребра
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    int s = 2, d = 3;
    cout << "Following are all different paths from " << s << " to " << d << endl;

    // Викликаємо функцію для знаходження шляхів та виводимо їх
    g.findAllPaths(s, d);

    return 0;
}
