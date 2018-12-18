#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        for(int i = 1;i<nums.size();++i){
          if(nums[i]==nums[i-1]){
            return nums[i];
          }
        }
        return -1;
        
    }
};



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto num:nums){
          if(seen.count(num)==1){
            return num;
          }
          seen.insert(num);
        }
    }
};