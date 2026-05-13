class Solution {
public:
    void dfs(int i,vector<vector<int>> &edges,vector<bool>&visited,vector<int>&component){
        visited[i] = true;
        component.push_back(i);
        for(int neighbour: edges[i]){
            if(!visited[neighbour]){
               
                dfs(neighbour,edges,visited,component);
            }
        }

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<bool>visited(n);
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int ct = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                vector<int>component;
                bool completed=true;
                dfs(i,graph,visited,component);
                int size=component.size();
                for(int c: component){
                    if(graph[c].size() != size-1){
                        completed=false;
                        break;
                    }
                }
                if(completed) ct++;
            }
        }
        return ct;
    }
};