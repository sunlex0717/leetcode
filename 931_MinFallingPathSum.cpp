// dp(r,c) = A[r,c] + min{ dp(r-1,c),dp(r-1,c-1),dp(r-1,c+1) }
// if r ,c are not in the bound then set the value to 0
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i] = A[0][i];
        }
        for(int i = 1;i<n;i++){
            for(int j=0;j<n;j++){
                int rt = i-1;
                int c0 = j-1 >=0 ? j-1:0;
                int c1 = j;
                int c2 = j+1 < n? j+1: n-1;
                dp[i][j] = A[i][j] + std::min( std::min(dp[rt][c0], dp[rt][c1]),dp[rt][c2]);
            }

        }

        return *std::min_element(dp[n-1].begin(),dp[n-1].end());
    }
};