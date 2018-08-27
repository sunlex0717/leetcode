// A ^ A = 0;
// 0 ^ A = A;
// 1 ^ A = ~ A; bitwise reverse.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(auto e:nums){
            result ^= e;
        }
        return result;
    }
};