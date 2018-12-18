class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(res,tmp,0,nums);
        return res;

    }
    void backtrack(vector<vector<int>>& res,vector<int>& tmp, int l, vector<int>& nums  ){
        res.push_back(tmp);
        for(int i = l;i<nums.size();++i){
          tmp.push_back(nums[i]);
          backtrack(res,tmp,i+1,nums);
          tmp.pop_back();
        }
    }
};