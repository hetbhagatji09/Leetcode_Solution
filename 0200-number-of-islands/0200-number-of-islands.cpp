class Solution {
public:
    void bfs(int row,int col,vector<vector<bool>>&visited,vector<vector<char>>&grid){
        queue<pair<int,int>>q;
        visited[row][col]=true;
        int n=grid.size();
        int m=grid[0].size();
        q.push({row,col});
        vector<int>delCol={-1,1,0,0};
        vector<int>delRow={0,0,-1,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                
                    int nrow=row+delRow[i];
                    int ncol=col+delCol[i];

                    if(nrow >=0 && nrow<n 
                        && ncol>=0 && ncol<m
                        && !visited[nrow][ncol]
                        && grid[nrow][ncol]=='1'){
                            visited[nrow][ncol]=true;
                            q.push({nrow,ncol});
                    }
                
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int ct=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    ct++;
                    bfs(row,col,visited,grid);
                }
            }
        }
        return ct;
    }
};