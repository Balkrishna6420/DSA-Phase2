//using vector
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    //creating ans array which stores all adjacentnodes correspondin to indexes
    vector<int>ans[n];
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        //storing same 
        adj[i].push_back(i);
        //stoing neighbours in ans array
        for(int j=0;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;

}