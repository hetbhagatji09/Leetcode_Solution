class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int ct=1;
        int s_row=0;
        int s_col=0;

        int e_row=n-1;
        int e_col=n-1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        while(s_row <= e_row && s_col <= e_col){
            //Top side
            for(int j=s_col; j<=e_col ;j++){
                matrix[s_row][j]=ct;
                ct++;
            }
            //Right side
            for(int i=s_row+1;i<=e_row;i++){
                matrix[i][e_col]=ct;
                ct++;
            }
            if(s_row<e_row){
                //Bottom side
            for(int j=e_col-1;j>=s_col;j--){
                matrix[e_row][j]=ct;
                ct++;
            }
        }
            
            //Left side
            if(s_col<e_col){
                for(int i=e_row-1;i>=s_row+1;i--){
               
                matrix[i][s_col]=ct;
                ct++;
            }
            }
            
            s_row++;
            e_row--;
                                                                                        
            s_col++;
            e_col--;
        }       
        return matrix;
        
    }
};