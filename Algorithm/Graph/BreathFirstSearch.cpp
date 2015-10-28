#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

class Graph {
    int v;
    list<int> *adj;
  public:
    Graph(int v) {
        this->v = v;
        adj = new list<int>[v]; 
    };
    void addEdge(int u, int w) {
        adj[u].push_back(w);
        adj[w].push_back(u);
    }
    vector<int> BFS(int n) {
        vector<int> visited(v, -1);
        list<int> queue;
        visited[n]=0;
        queue.push_back(n);
        while(queue.size()) {
            int t = queue.front();
            queue.pop_front();
            for(auto it=adj[t].begin(); it!=adj[t].end(); it++) {
                if(visited[*it]==-1) {
                    visited[*it]=visited[t]+6;
                    queue.push_back(*it);   
                }
            }
        }
        return visited;
    };
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--!=0) {
        int v, e;
        cin >> v >> e;
        Graph g(v);
        while(e--!=0) {
            int u, w;
            cin >> u >> w;
            g.addEdge(u-1, w-1);
        }
        int n;
        cin >> n;
        vector<int> dis = g.BFS(n-1);
        for(int i=0; i<v; i++) {
            if(i!=n-1) {
                cout << dis[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
