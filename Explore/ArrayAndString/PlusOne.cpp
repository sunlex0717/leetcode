class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        vector<int> result(digits);
        result[length-1]++;
        return result;
    }
};