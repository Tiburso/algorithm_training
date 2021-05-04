#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Graph {
private:
    int V;
    list<int>* adj;
    list<int> sources;

public:
    Graph(int _V);

    void push_node(int origin, int dest);
    void push_source(int src);
    pair<int, int> find_edge(int src);
};

Graph::Graph(int _V) {
    V = _V;
    adj = new list<int>[_V];
}

void Graph::push_node(int origin, int dest) {
    adj[origin].push_back(dest);
    adj[dest].push_back(origin);
}

void Graph::push_source(int src) {
    sources.push_back(src);
}

pair<int,int> Graph::find_edge(int src) {
    vector<bool> vis(V, false);
    queue<int> path;

    vis[src] = true;
    path.push(src);

    while ( !path.empty() ) {
        int u = path.front();
        path.pop();

        for (int &n : adj[u]) {
            if ( !vis[n] ) {
                vis[n] = true;
                path.push(n);

                if ( find(sources.begin(), sources.end(), n) != sources.end() )
                    return {u, n};
            }
        }
    }   

    
    return {0,0};
}

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();

    Graph graph(N);
    
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        
        graph.push_node(N1,N2);
    }

    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();

        graph.push_source(EI);
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        pair<int,int> obj = graph.find_edge(SI);

        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        cout << obj.first << " " << obj.second << endl;
    }
}