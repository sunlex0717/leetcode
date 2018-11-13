#include<vector>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> forward(n,1);
        vector<int> backward(n,1);
        vector<int> res(n);
        for(int i=1;i<n;++i){
          forward[i] = forward[i-1]*nums[i-1];
          backward[i] = backward[i-1]*nums[n-i];
        }
        for(int i = 0;i<n;++i){
          res[i] = forward[i]*backward[n-i-1];
        }

        return res;

    }
};