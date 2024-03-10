#include <bits/stdc++.h>
using namespace std;

// const int N = 1e5+5;
// int V, E;
// vector<int> adj[N];
// bool visited[N], cvisited[N];

bool dfs(int s, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &cvisited){
    visited[s] = 1;
    cvisited[s] = 1;

    for(auto x:adj[s]){
        if(!visited[x]){
            if(dfs(x, adj, visited, cvisited))
                return true;
        }
        
        else if(cvisited[x])
            return true;
    }
    
    cvisited[s] = 0;
    return false;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin >> t;

    while(t--){
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V+1);
        vector<bool> visited(V+1);
        vector<bool> cvisited(V+1);

        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
        }
        bool flag = 0;

        for(int i=0; i<V; i++){
            if(!visited[i] && dfs(i, adj, visited, cvisited)){
                cout << "YES" << endl;
                flag = 1;
                break;
            }
        }

        if(!flag){
            cout << "NO" << endl;
        }
    }
}