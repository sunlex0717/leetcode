//use unordered_set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        if(size <=1 ) return false;
        unordered_set<int> hashset;
        for(auto& e:nums){
            if(hashset.count(e) > 0){
                return true;
            }
            hashset.insert(e);
        }
        return false;
    }
};