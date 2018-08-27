class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;  // <value,index>
        vector<int> res; // value is key here
        int size = nums.size();
        for(int i = 0;i<size;++i){
          auto got = hashmap.find(target-nums[i]);
          if(got != hashmap.end()){//find
            
            res.push_back(got->second);
            res.push_back(i);
            return res;
          }else{
            hashmap[nums[i]] = i; //insert <nums[i],i>  <value,index>
          }

        }
    }
};