/*
corner case:
1. cause carry in first element, then we should insert a new element which means that it will increment vector size;  eg 9 9 9 -> 1 0 0 0 
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        vector<int> result(digits);
        //case one , will not cause carry at first element(i.e. size keeps same)
        result[length-1]++;
        for(int i = length-1; i>=0;){
            if( (result[i]) == 10 ){
                std::cout<<" index "<<i << " causes carry , with value "<<result[i]<<endl;
                result[i]=0;
                if(i==0){ //first element cause carry 
                    result.insert(result.begin(),1);
                    break; //then break
                }
                result[i-1] ++;
            }else{
                break; //then break
            }
            i--;
        }
        return result;
    }
};