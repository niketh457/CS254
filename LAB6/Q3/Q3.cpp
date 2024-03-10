#include <bits/stdc++.h>
using namespace std;

void dfs(int s, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
    visited[s] = 1;

    for(auto x:adj[s]){
        if(!visited[x])
            dfs(x, adj, visited, st);
    }

    st.push(s);
}

vector<int> topological_sort(vector<vector<int>> &adj){
    int V = adj.size();
    stack<int> st;
    vector<int> srt;
    vector<bool> visited(adj.size());

    for(int i = 0; i < V; i++){
        if(!visited[i])
            dfs(i, adj, visited, st);
    }

    while(!st.empty()){
        srt.push_back(st.top());
        st.pop();
    }
    return srt;
}

void rdfs(vector<vector<int>> &rev_adj, vector<bool> &rev_visited, int s){

    rev_visited[s] = 1;
    cout << s << " ";

    for(auto x:rev_adj[s]){
        if(!rev_visited[x])
            rdfs(rev_adj, rev_visited, x);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin >> t;

    while(t--){
        int V, E;
        cin >> V >> E;
        
        vector<vector<int>> adj(V);
        vector<vector<int>> rev_adj(V);
        vector<bool> rev_visited(V);

        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            rev_adj[v].push_back(u);
        }

        vector<int> res = topological_sort(adj);

        for(auto &i: res){
            if(!rev_visited[i]){
                rdfs(rev_adj, rev_visited, i);
                cout << endl;
            }
        }
    }
}