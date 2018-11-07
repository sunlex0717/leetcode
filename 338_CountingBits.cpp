class Solution {
public:
    vector<int> countBits(int num) {
        int offset = 1;
        vector<int> res(num+1,0);
        res[0] = 0;
        for(int i = 1; i<=num;++i){
          if(offset*2 == i){
            offset *= 2;
          }
          res[i] = res[i-offset] +1;
        }
        return res;
    }
};