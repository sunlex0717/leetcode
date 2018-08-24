class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int result = 0;
        DFS_sum(nums,0,S, result);
        return result;
    }


    void DFS_sum(vector<int>& nums,int index, int node, int& result){
        if(index == nums.size()){
            if(node == 0){
                result ++;
            }
            return;
        }
        DFS_sum(nums,index+1, node + nums[index]  ,result );
        DFS_sum(nums,index+1, node - nums[index]  ,result);

    }
};