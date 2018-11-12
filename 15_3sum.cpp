#include<algorithm>
#include<vector>
using namespace std;
class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> res(0, vector<int>(3,0));
        if(size <=2 ){
          return res;
        }
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i<size; ++i){
          int target = -nums[i]; // pos
          int pos1 = i+1;
          int pos2 = size -1;
          while(pos1 < pos2){
            int sum = nums[pos1] + nums[pos2];
            
            if(sum < target){
              pos1++;
            }else if(sum > target){
              pos2--;
            }else{ // sum == target
              vector<int> can = {-target,nums[pos1],nums[pos2]};
              res.push_back(can);

              while(pos1 < pos2 && nums[pos1] == can[1]) pos1++;

              while(pos1 < pos2 && nums[pos2] == can[2]) pos2--;
            }

          }

          while(i+1<size && nums[i]==nums[i+1]){
            i++;
          }
        }
        return res;
    }
};