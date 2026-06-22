#include<bits/stdc++.h>
using namespace std;
int countComponents(int V,vector<vector<int>> &edges){
    vector<vector<int>> adj(V);
    for(auto & e: edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<int> Visted(V,0);
    int comp = 0;
    for(int i = 0;i<V;i++){
        queue<int> q;    
        if(!Visted[i]){
            comp++;
            q.push(i);
            Visted[i] = 1;
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto & a :adj[node]){
                if (!Visted[a]) {
                    Visted[a] = 1;
                    q.push(a);
                }
            }
        }
    }
    return comp;
}
int main() {
    int V = 5;

    // List of undirected edges
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    cout << "Number of Connected Components: " 
         <<countComponents(V, edges) << endl;
    return 0;
}