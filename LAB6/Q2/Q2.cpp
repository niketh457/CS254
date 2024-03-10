#include <bits/stdc++.h>
using namespace std;

void dfs(int s, stack<int> &st, vector<vector<int>> &adj, vector<bool> &visited){
    visited[s] = true;

    for(auto x: adj[s]){
        if(!visited[x])
            dfs(x, st, adj, visited);
    }
    st.push(s);
}

vector<int> topological_sort(vector<vector<int>> &adj){
    stack<int> st;
    vector<int> res;
    vector<bool> visited(adj.size()+1);

    for(int i = 0; i < adj.size(); i++){
        if(!visited[i])
            dfs(i, st, adj, visited);
    }

    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }

    return res;
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
        
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
        }

        vector<int> res = topological_sort(adj);
        reverse(res.begin(), res.end());
        vector<int> dist(V);

        for(auto s: res){
            for(auto x:adj[s])
                dist[s] = max(dist[s], dist[x]+1);
        }

        cout << *max_element(dist.begin(), dist.end()) << endl;
    }
}