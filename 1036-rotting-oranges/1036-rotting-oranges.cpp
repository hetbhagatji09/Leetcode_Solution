class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int tm=0;
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    visited[i][j]=2;
                    q.push({{i,j},0});
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        vector<int>rows={-1,0,1,0};
        vector<int>cols={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int time=q.front().second;
            q.pop();
            tm=max(tm,time);
            for(int i=0;i<4;i++){
                int nrow=r+rows[i];
                int ncol=c+cols[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                    && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                        visited[nrow][ncol]=2;
                        q.push({{nrow,ncol},tm+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]!=2){
                    return -1;
                }
            }
        }
        return tm;
        


        
    }
};