/*
 *  4 ms , beats 99.8%
 *  2018-7-6
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = strs.size();
        int j =0;
        string res;
        if(m == 0){
            return res;
        }
        vector<int> length_s;
        for(int i=0;i<m;i++){
            length_s.push_back(strs[i].size());
        }
        int min_col = *max_element(std::begin(length_s), std::end(length_s));
        if(min_col == 0){
            return res;
        }
        for(int i =0;i<min_col;i++){
            for( j = 0;j<m - 1;j++){
                if(strs[j][i] != strs[j+1][i] ){
                    return res;
                }
            }
            res.push_back(strs[0][i]);
        }
        return res;
    }
};
