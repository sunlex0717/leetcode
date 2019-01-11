#include<iostream>
#include<vector>
#include<array>

// DP
// s[i][j] = min(s[i-1][j] , s[i][j-1]) + v[i][j] normal case
// s[0][j] = s[0][j-1] + v[0][j] corner case
// s[i][0] = s[i-1][0] + v[i][0] corner case
// s[0][0] = v[0][0] corner case
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> s(m,vector<int>(n));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; j++){
                find_solution(grid,s,i,j);
            }
        }

        return s[m-1][n-1];
        
    }

    void find_solution(vector<vector<int>>& grid,vector<vector<int>>& s, int m,int n){
        if(m==0 && n==0){
            s[0][0] == grid[0][0];
        }
        if(m == 0){
            s[0][n] = s[0][n-1] + grid[0][n];
            return;
        }
        if(n == 0){
            s[m][0] = s[m-1][0] + grid[m][0];
            return;
        }
        s[m][n] = min(s[m-1][n],s[m][n-1]) + grid[m][n];
        return;
    }
};
