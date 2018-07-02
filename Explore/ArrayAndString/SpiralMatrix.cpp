/*
1. use enum to define four cases: right left down up;
2. use switch-case statement
3. 
*/

class Solution {
public:
  enum Direction
    {
        up,
        down,
        left,
        right
    };
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //get size of matrix, M*N   
        if(matrix.empty()){
            return {} ;
        }
        int num_row = matrix.size();
        int num_col = matrix[0].size(); //because they are same 
        int total = num_col*num_row;
        int begin_row = 0;
        int begin_col = 0;
        int end_row = num_row-1;
        int end_col = num_col-1;

        int min_row_col = min(num_row,num_col);
        int num_round = min_row_col/2;
        int round_ = 0;

        vector<int> res;
        Direction d = Direction::right; //initialize
        
        int x=0,y=0; //
                for(int k=0;k< total ;++k){
                    
                    switch (d)
                    {
                        case Direction::right:
                            res.push_back(matrix[x][y]);
                            
                            y++;
                            if(y == end_col + 1){
                                y--;
                                begin_row++;
                                x++;
                                d = Direction::down;
                            }
                            /* code */
                            break;
                        case Direction::down:
                            res.push_back(matrix[x][y]);
                            
                            x++;
                            if(x == end_row+1 ){
                                x--;
                                end_col -- ;
                                y--;
                                d = Direction::left;
                            }
                            /* code */
                            break;
                        case Direction::left:
                            res.push_back(matrix[x][y]);
                            
                            y--;
                            if(y == begin_col-1 ){
                                y++;
                                end_row -- ;
                                x--;
                                d = Direction::up;
                            }
                            /* code */
                            break;
                        case Direction::up:
                            res.push_back(matrix[x][y]);
                            
                            x--;
                            if(x == begin_row -1 ){
                                x++;
                                begin_col ++;
                                y++;
                                d = Direction::right;
                                x = begin_row;
                                y = begin_col;
                            }
                            /* code */
                            break;
                        default:
                            break;
                    }
                    std::cout<<"(" << x <<","<<y<<")    ";
                }
        return res;
    }
};