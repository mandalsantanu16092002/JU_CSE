#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<map>

using namespace std;

// Class to represent a node in the graph
class Node {
    public:
        int id;
        vector<pair<Node*, int>> adjList;

        Node(int id) {
            this->id = id;
        }

        void addNeighbor(Node* neighbor, int weight) {
            adjList.push_back(make_pair(neighbor, weight));
        }
};

// Class to represent the graph
class Graph {
    public:
        vector<Node*> nodes;

        // Add a new node to the graph
        void addNode(int id) {
            nodes.push_back(new Node(id));
        }

        // Add an undirected edge between two nodes
        void addEdge(int id1, int id2, int weight) {
            Node* node1 = getNode(id1);
            Node* node2 = getNode(id2);

            node1->addNeighbor(node2, weight);
            node2->addNeighbor(node1, weight);
        }

        // Get a node by its id
        Node* getNode(int id) {
            for (Node* node : nodes) {
                if (node->id == id) {
                    return node;
                }
            }
            return nullptr;
        }

        // Get the heuristic value of a node using the manhattan distance
        int heuristic(Node* node, Node* goalNode) {
            return abs(node->id / 3 - goalNode->id / 3) + abs(node->id % 3 - goalNode->id % 3);
        }

        // Perform Uniform Cost Search algorithm
        void ucs(Node* startNode, vector<Node*> goalNodes) {
            priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
            unordered_map<Node*, int> visited;
            unordered_map<Node*, Node*> parent;

            pq.push(make_pair(0, startNode));

            while (!pq.empty()) {
                Node* node = pq.top().second;
                pq.pop();

                if (visited.find(node) != visited.end()) {
                    continue;
                }

                visited[node] = 1;

                if (find(goalNodes.begin(), goalNodes.end(), node) != goalNodes.end()) {
                    printPath(startNode, node, parent);
                    return;
                }

                for (pair<Node*, int> neighbor : node->adjList) {
                    if (visited.find(neighbor.first) == visited.end()) {
                        int cost = neighbor.second;
                        pq.push(make_pair(cost, neighbor.first));
                        if (parent.find(neighbor.first) == parent.end()) {
                            parent[neighbor.first] = node;
                        }
                        else if (cost < neighbor.first) {
                            parent[neighbor.first] = node;
                        }
                    }
                }
            }
        }

        // Perform Best-First Greedy Search algorithm
        void bestFirstGreedy(Node* startNode, vector<Node*> goalNodes) {
            priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
            unordered_map<Node*, int> visited;
            unordered_map<Node*, Node*> parent;

            pq.push(make_pair(heuristic(startNode, goalNodes[0]), startNode));

            while (!pq.empty()) {
                Node* node = pq.top().second;
                // pq.pop;
            if (visited.find(node) != visited.end()) {
                continue;
            }

            visited[node] = 1;

            if (find(goalNodes.begin(), goalNodes.end(), node) != goalNodes.end()) {
                printPath(startNode, node, parent);
                return;
            }

            for (pair<Node*, int> neighbor : node->adjList) {
                if (visited.find(neighbor.first) == visited.end()) {
                    pq.push(make_pair(heuristic(neighbor.first, goalNodes[0]), neighbor.first));
                    if (parent.find(neighbor.first) == parent.end()) {
                        parent[neighbor.first] = node;
                    }
                }
            }
        }
    }

    // Perform A* Search algorithm
    void aStar(Node* startNode, vector<Node*> goalNodes) {
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
        unordered_map<Node*, int> visited;
        unordered_map<Node*, int> costSoFar;
        unordered_map<Node*, Node*> parent;

        pq.push(make_pair(heuristic(startNode, goalNodes[0]), startNode));
        costSoFar[startNode] = 0;

        while (!pq.empty()) {
            Node* node = pq.top().second;
            pq.pop();

            if (visited.find(node) != visited.end()) {
                continue;
            }

            visited[node] = 1;

            if (find(goalNodes.begin(), goalNodes.end(), node) != goalNodes.end()) {
                printPath(startNode, node, parent);
                return;
            }

            for (pair<Node*, int> neighbor : node->adjList) {
                if (visited.find(neighbor.first) == visited.end()) {
                    int newCost = costSoFar[node] + neighbor.second;
                    if (costSoFar.find(neighbor.first) == costSoFar.end() || newCost < costSoFar[neighbor.first]) {
                        costSoFar[neighbor.first] = newCost;
                        int priority = newCost + heuristic(neighbor.first, goalNodes[0]);
                        pq.push(make_pair(priority, neighbor.first));
                        parent[neighbor.first] = node;
                    }
                }
            }
        }
    }

    // Print the path from the start node to the end node
    void printPath(Node* startNode, Node* endNode, unordered_map<Node*, Node*> parent) {
        vector<Node*> path;
        Node* node = endNode;

        while (node != startNode) {
            path.push_back(node);
            node = parent[node];
        }

        path.push_back(startNode);
        reverse(path.begin(), path.end());

        cout << "Order of nodes visited: ";
        for (auto visited : parent) {
            cout << visited.first->id << " ";
        }
        cout << endl;

        cout << "Solution path: ";
        for (Node* node : path) {
            cout << node->id << " ";
        }
        cout << endl;
    }
};

int main() {
Graph graph;
// Add nodes to the graph
for (int i = 0; i < 9; i++) {
    graph.addNode(i);
}

// Add edges to the graph
graph.addEdge(0, 1, 1);
graph.addEdge(0, 3, 1);
graph.addEdge(1, 2, 1);
graph.addEdge(1, 4, 2);
graph.addEdge(2, 5, 3);
graph.addEdge(3, 4, 3);
graph.addEdge(3, 6, 1);
graph.addEdge(4, 5, 3);
graph.addEdge(4, 7, 3);
graph.addEdge(5, 8, 1);
graph.addEdge(6, 7, 1);
graph.addEdge(7, 8, 2);

Node* startNode = graph.getNode(0);
vector<Node*> goalNodes = { graph.getNode(8), graph.getNode(6) };

// Run UCS search algorithm
cout << "Running UCS search algorithm..." << endl;
graph.ucs(startNode, goalNodes);

// Run Best First Greedy search algorithm
cout << "Running Best First Greedy search algorithm..." << endl;
graph.bestFirstGreedy(startNode, goalNodes);

// Run A* search algorithm
cout << "Running A* search algorithm..." << endl;
graph.aStar(startNode, goalNodes);

return 0;
}
