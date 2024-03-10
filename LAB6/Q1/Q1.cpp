#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int start, stack<int> &st, vector<bool> &visited){

    visited[start] = 1;
    for(auto x: adj[start])
        if(!visited[x])
            dfs(adj, x, st, visited);
    st.push(start);
}

vector<int> topological_sort(vector<vector<int>> &adj){
    stack<int> st;
    vector<bool> visited(adj.size(), false);
    vector<int> res;

    for(int i = 0; i < adj.size(); i++){
        if(!visited[i])
            dfs(adj, i, st, visited);
    }

    while(!st.empty()){
        res.emplace_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());

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
            
            adj[u].emplace_back(v);
        }

        vector<int> res = topological_sort(adj);
        for(int &i: res)
            cout << i << ' ';
        cout << endl;
    }
}