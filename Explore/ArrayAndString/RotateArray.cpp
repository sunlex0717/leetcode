/*
simple and naive solution
time complexity O(n)
extra space O(n)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res;
        int len = nums.size();
        k = k % len;
        for(int i = len - k  ; i < len;++i){
            res.push_back(nums[i]);
        }
        for(int i=0;i < len -k  ;++i){
            res.push_back(nums[i]);
        }
        nums = res;
        //return res;
    }
};


/*
in-place solution insert and erase 
time complexity  
extra space O(1)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        int pos = 0;
        vector<int>::iterator it;
        it = nums.begin();
        for(int i = len -1 ;i >= len - k ;--i){
            int tmp = nums[len-1];
            nums.erase(it+len-1);
            nums.insert(it,tmp);
           // pos++;
        }
    }
};