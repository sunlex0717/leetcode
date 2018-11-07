#include<unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int size = s.size();
        if(size <=1 ){
          return size;
        }
        int res = 0;
        int pos1 = 0;
        int pos2 = 0;
        
        unordered_set<char> set;
        while(pos1 < size && pos2 < size){
          if(set.count(s[pos2]) == 0){
            set.insert(s[pos2++]);
            res = max(res,pos2-pos1);
          }else{
            set.erase(s[pos1++]);
          }
        }
        return res;
    }
};