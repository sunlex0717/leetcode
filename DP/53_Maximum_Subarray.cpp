class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1;i<len;++i){
            dp[i] = nums[i] + ( (dp[i-1] > 0 )? dp[i-1]:0 ) ;
            if(dp[i]>res){
                res = dp[i];
            }
        }
        /*
        for(int n : dp){
            std::cout<<n <<" ";
        }*/
        return res;
    }
};