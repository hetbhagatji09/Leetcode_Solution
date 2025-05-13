class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        int s_row=0;
        int e_row=m-1;

        int s_col=0;
        int e_col=n-1;

        vector<int> ans;
        while(s_row <= e_row && s_col <= e_col){
            //Top side
            for(int j=s_col; j<=e_col ;j++){
                ans.push_back(matrix[s_row][j]);
            }
            //Right side
            for(int i=s_row+1;i<=e_row;i++){
                ans.push_back(matrix[i][e_col]);
            }
            if(s_row<e_row){
                //Bottom side
            for(int j=e_col-1;j>=s_col;j--){
              
                ans.push_back(matrix[e_row][j]);
            }
            }
            
            //Left side
            if(s_col<e_col){
                for(int i=e_row-1;i>=s_row+1;i--){
               
                ans.push_back(matrix[i][s_col]);
            }
            }
            
            s_row++;
            e_row--;
                                                                                        
            s_col++;
            e_col--;
        }       
            
        return ans;
        


    }
};