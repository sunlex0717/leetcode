class Solution {
public:
    string reverseString(string s) {
        int len = s.size();
        string res;
        if(len ==0 ){
          return {};
        }
        for(int i = len -1; i>=0 ;i--){
          res.push_back(s[i]);
        }
        return res;
    }
};