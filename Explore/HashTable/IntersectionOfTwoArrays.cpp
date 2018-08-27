class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> res;
        if(size1 == 0 || size2==0){
            return res;
        }
        unordered_set<int> set1(nums1.begin(),nums1.end());
        for(auto e:nums2){
            if( set1.count(e)){
                res.push_back(e);
                set1.erase(e);
            }
        }
        return res;
    }
};