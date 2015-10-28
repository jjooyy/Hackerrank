#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

struct edge {
    int node;
    int d;
};

class Graph {
    int V;
    list<edge> *adj;
    vector<vector<int>> dis;
  public:
    Graph(int v) {
        this->V = v;
        adj = new list<edge>[V];
    };
    void addEgde(int u, int w, int dis){
        struct edge temp;
        temp.node = w;
        temp.d = dis;
        adj[u].push_back(temp);
        temp.node = u;
        adj[w].push_back(temp);
    }
    vector<int> dijkstra(int n) {
        int root = n;
        vector<int> distance(V, -1);
        list<int> nodelist;
        distance[root] = 0;
        nodelist.push_back(root);
        while(!nodelist.empty()) {
            int top = nodelist.front();
            nodelist.pop_front();
            for(auto it=adj[top].begin(); it!=adj[top].end(); it++) {
                if(distance[it->node]==-1||(distance[it->node]>distance[top]+ it->d)) {
                    distance[it->node] = distance[top]+it->d;
                    //cout << distance[it->node] << endl;
                    nodelist.push_back(it->node);
                }
            }
        }
        return distance;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--!=0) {
        int n, m;
        cin >> n >> m;
        Graph g(n);
        while(m--!=0) {
            int e1, e2, w;
            cin >> e1 >> e2 >> w;
            g.addEgde(e1-1, e2-1, w);
        }
        int t;
        cin >> t;
        vector<int> dis= g.dijkstra(t-1);
        for(int i=0; i<n; i++) {
            if(i!=t-1) {
                cout << dis[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
