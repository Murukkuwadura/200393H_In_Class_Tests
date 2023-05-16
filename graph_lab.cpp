#include <iostream>
#include <vector>

struct Node {
    int label;
    std::vector<int> neighbours;
};

class Graph {
    int n;
    std::vector<Node> nodes;

public:
    Graph(int numNodes) : n(numNodes), nodes(numNodes) {}

    void initializeNodes() {
        for (int i = 0; i < n; i++) {
            nodes[i].label = i;
        }
    }

    void addEdge(int u, int v) {
        nodes[u].neighbours.push_back(v);
        nodes[v].neighbours.push_back(u);
    }

    void print() {
        for (int i = 0; i < n; i++) {
            std::cout << "Node " << i << " -> ";
            for (int neighbour : nodes[i].neighbours) {
                std::cout << neighbour << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g(9);
    g.initializeNodes();

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 6);
    g.addEdge(4, 6);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(5, 8);

    g.print();

    return 0;
}
