class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> hashmap;
        int res;
        for(int i = s.size() -1 ;i>=0;--i){
          if(hashmap.count(s[i]) >0 ){//find
              hashmap[s[i]] = -1;
          }else {
            //res = i;
            hashmap[s[i]] = i;
          }
        }
        for(auto& e:hashmap){
          if(e.second != -1){
            return e.second;
          }
        }
        return -1;
    }
};