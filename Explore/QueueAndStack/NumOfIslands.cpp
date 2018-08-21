// the idea is to find all possible islands and remove the duplicates
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
     
        int count = 0;
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        if( m == 0 ) return 0;
        for(int i =0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == '1'){
                    //search and remove duplicates.
                    count ++ ;
                    remove_duplicate(grid,i,j);
                    //cout<<"island center: "<<i<<" , "<< j<<endl;
                }
            }
        }
        return count;
    }

    void remove_duplicate(vector<vector<char>>& grid, int i, int j){
        int rows=grid.size();
        int cols=grid[0].size();
        if( i< 0 || i>=rows || j<0 || j>=cols || grid[i][j]!='1' ){
           return ;
        }

        if(  grid[i][j]=='1'){
            grid[i][j] = '2';
        } 
        remove_duplicate(grid,i+1,j);
        remove_duplicate(grid,i,j + 1);
        remove_duplicate(grid,i -1 ,j);
        remove_duplicate(grid,i,j-1);
    }
};