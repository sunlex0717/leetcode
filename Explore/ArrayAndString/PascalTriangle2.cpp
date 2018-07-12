/*
only need O(k) extra memory

still wrong, need to think a bit about this

drawing a picture helps understanding.
*/
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
        int tmp;
        for(int i = 2; i<=rowIndex ;++i){
            tmp = res[1];
            for(int j = 1; j <= i -1 ;j++){
                if(j = i-1){
                    res[j] = tmp +1;
                }
                
                tmp = res[j];
                res[j] = tmp+res[j];
            }
            return res;
        }
    }
};