//using set
#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // creare adjacency list
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    //creation of distance array with infnte value initially
    vector<int>dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }
    //creation of set on basis of distance and node
    set<pair<int,int>>st;
    //inotoalise dist and set with source node
    dist[source]=0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        //fetch top node
        auto top=*(st.begin());
        int nodeDistance=top.first;
        int topNode=top.second;
        //remove top record now
        st.erase(st.begin());
        //traverse on neighbour
        for(auto neighbour:adj[topNode]){
            if(nodeDistance+neighbour.second<dist[neighbour.first]){
                auto record=st.find(make_pair(dist[neighbour.first],neighbour.first));
                //if record found then erase it
                if(record!=st.end()){
                    st.erase(record);
                }
                //update distance
                dist[neighbour.first]=nodeDistance+neighbour.second;
                //push record in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
}

//tc is O(ElogV) e-edges and v is vertices
//sc is o(n+e) using adjancncy list & linear if not taking adjancenvy list