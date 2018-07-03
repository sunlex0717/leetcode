class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //corner case
        if(numRows == 0){
            return {};
        }
        if(numRows == 1){
            vector<vector<int>> a(1);
            a[0]=vector<int>(1,1);
            return a;
        }
        if(numRows == 2){
            vector<vector<int>> a(2);
            a[0] = vector<int>(1,1);
            a[1] = vector<int>(2,1);
            return a;
        }
        // initialize
        vector<vector<int>> res(numRows);
        for(int i = 0; i<numRows;i++){
            // declare  the i-th row to size of column
            // and initialize values as 1
            res[i] = vector<int>(i+1,1);
        }
        

        //TODO: body code, to fill the triangle
        for(int i = 2;i<numRows;++i){ //row
            for (int j = 1 ;j <=i-1;++j){
                res[i][j] = res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;
    }
};