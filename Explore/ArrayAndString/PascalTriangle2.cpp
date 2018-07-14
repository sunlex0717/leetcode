/*
only need O(k) extra memory

still wrong, need to think a bit about this

drawing a picture helps understanding.


result: beats 100% @ 2018.07.13
*/
using namespace std;
class Solution {
public:

    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
             return vector<int>(1,1);
        }
        if( rowIndex == 1){
           return vector<int>(2,1);
        }

        vector<int> res(rowIndex+1,1);
        
        
        int prev;
        for(int i = 2; i<=rowIndex  ;++i){
            prev = 1;
            for(int j = 1; j <= i-1  ;j++){
                int tmp = res[j];
                res[j] = prev+res[j];
                prev = tmp;
            }
           
        }
        return res;
    }
};