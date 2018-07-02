class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0){
            return {};
        }
        if(numRows == 1){
            vector<int> a(1,1);
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
    }
};