/*
I did not come up with a efficient solution, it is from other coder, a very smart solution;
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        //get size of matrix, M*N   
        if(matrix.empty()){
            return {} ;
        }
        int num_row = matrix.size();
        int num_col = matrix[0].size(); //because they are same 
       
        vector<int> ret;
        for(int i = 0; i <= num_col+num_row - 2;i++){

            for(int j = 0; j <= i ;j++ ){
            int x = j; //row
            int y = i-x; //col
            //
            if((i%2 == 0)){ //up
                swap(x,y);    
            }
            if( (x >= num_row) || (y >= num_col)){
                continue;
            }
            ret.push_back(matrix[x][y]);
            }
        }
        return ret;
    }
};