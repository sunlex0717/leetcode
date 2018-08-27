class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int len1 = list1.size();
        int len2 = list2.size();
        
        unordered_map<string,int> map2;
        int ind =0;
        vector<string> res;
        
        string tmp;
        int temp_min = len1+len2;
        for(string s:list2){ // construct map2
          map2[s] = ind;
          ++ind;
        }

        for(int i = 0 ; i <len1 ;++i){
          auto got = map2.find(list1[i]);
          if(got!=map2.end()){//
            if(temp_min > (got->second + i) ){
              res.clear();
              temp_min = got->second + i;
              res.push_back(list1[i]);
            }else if( temp_min == (got->second + i)){
              res.push_back(list1[i]);
            }
          }
        }
        
        return res;
    }
};