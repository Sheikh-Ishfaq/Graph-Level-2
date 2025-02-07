//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  // Function to detect cycle in a directed graph
  bool checkCyclic(int src, vector<vector<int>> &adj, unordered_map<int,bool> &vis, unordered_map<int,bool> &dfsTrack){
      vis[src] = 1;
      dfsTrack[src] = 1;
      
      for(auto nbr : adj[src] ){
          if(!vis[nbr]){
          bool ans = checkCyclic(nbr, adj, vis, dfsTrack);
          if(ans)return ans;
          }
           
          if(vis[nbr] && dfsTrack[nbr])return 1;
      }
      dfsTrack[src] = 0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        unordered_map<int,bool>vis;
        unordered_map<int,bool>dfsTrack;
        
        for(int node = 0; node < V; node++){
            if(!vis[node]){
                bool ans = checkCyclic(node, adj, vis, dfsTrack);
                if(ans)return ans;
            }
        }
        return false;
    }
};

// Function to detect cycle in an undirected graph
bool checkCyclic(int src, vector<vector<int>>&adj, unordered_map<int,bool>&vis){
       
        unordered_map<int,int>parent;
        queue<int>q;
        q.push(src);
        vis[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr : adj[node]){
                if(vis[nbr] != true){
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr] = node;
            }
            else if(vis[nbr] == true && nbr != parent[node]){
                return true;
                
            }
        }
       
    }
     return false;
    }

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends