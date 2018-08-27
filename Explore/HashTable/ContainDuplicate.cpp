class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        if( size < 2  ){
          return false;
        }
        unordered_map<int,int> hashmap; //<value, index>
        for(int i = 0;i <size;++i){
          if(hashmap.count(nums[i])>0){//find
            if( i - hashmap[nums[i]] <= k  ){
              return true;
            }else{
              hashmap[nums[i]] = i;
            }  
          }else{//not found
            hashmap[nums[i]] = i;

          }
        }
        return false;  
    }
};