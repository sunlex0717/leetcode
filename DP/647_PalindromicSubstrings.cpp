//O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        int res = len;
        for(float a = 0.5;a < len;a+=0.5){
            int left = int(a-0.5);
            int right = int(a+1);
            while(left>=0 && right<len && (s[left--] == s[right++])){
                ++res;
            }
        }
        return res;
    }
};