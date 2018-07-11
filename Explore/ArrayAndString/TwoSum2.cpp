/*
Binary search find closest index, recursive method.
target - numbers[0]

only beat 6.64%
*/

using namespace std;
class Solution {
public:
    int find_ind(int indL,int indU, int tar_val, vector<int>& numbers){
        int tmp = (indU + indL)/2;
        int n_indL;
        int n_indU;
        cout<<"indL: "<<indL <<". indU: "<<indU<<endl;
        //when break 
        if(indL >= indU -1){
            return indL;
        }
        if(numbers[tmp] < tar_val ){
            n_indL = tmp ;
            n_indU = indU;
            return find_ind(n_indL,n_indU,tar_val,numbers);
        }else{
            n_indL = indL;
            n_indU = tmp ;
            return find_ind(n_indL,n_indU,tar_val,numbers);
        }

    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size() - 1;
        
        int interested_range = find_ind(1,len,target-numbers[0],numbers);
        vector<int> res;
        
        int min_ind = 0;
        int lar_ind = 1;
        for(; min_ind<interested_range ;++min_ind){
            lar_ind = min_ind+1;
            for(;lar_ind <= interested_range;++lar_ind){
                if(numbers[min_ind] + numbers[lar_ind] == target){
                    res.push_back(min_ind+1);
                    res.push_back(lar_ind+1);
                    return res;
                }
            }
        }

        
    }
};