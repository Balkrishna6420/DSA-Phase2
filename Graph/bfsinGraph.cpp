//for disconnected graph
#include<bits/stdc++.h>
void prepareAdjList(unordered_map<int,list<int>>&adjList,vector<pair<int,int>>&edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}
void bfs(unordered_map<int,list<int>>&adjList,unordered_map<int,bool>&visited,vector<int>&ans,int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        //store front node into ans;
        ans.push_back(frontNode);
        //traverse all neighbor of front node
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> bfsTraversal(int vertex,vector<pair<int,int>edges){
    // Write your code here.
    unordered_map<int,list<int>>adjList;
    vector<int>ans;
    unordered_map<int,bool>visited;
    prepareAdjList(adjList,edges);
    //traverse all components of a graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}

///or for non disconnected graph
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i : adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    unordered_map<int,bool> visited;

    // ? ONLY BFS from node 0
    bfs(adj, visited, ans, 0);

    return ans;
}
//time and c is O(n+e)