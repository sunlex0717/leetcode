class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1){
            return false;
        }
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        if( (sum % 2) == 1 ) return false;
        int target = sum >> 1;
        if(*max_element(nums.begin(),nums.end()) > target) return false;

        vector<bool> reached(target+1,false);
        reached[0] = true;
        for(auto e:nums){
            for(int i = target; i>=e ; i++){ // here we must start from target down to e, otherwise the e will be used mutiple times.
                if(reached[i - e]){
                    reached[i] = true;
                }
            }
        }
        return reached[target];
    }
};

