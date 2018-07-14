/*
naive solution
time complexity O(n)
extra space O(n)
brief: just create a new string 
*/

class Solution {
public:
    void reverseWords(string &s) {
        string res(s);
        res = res + ' ';
        string tmp_word;
        int len = res.size();
        
        s.clear();
        for(int i = 0; i < len ; i++){
            if(res[i] == ' ' ){
                if(!tmp_word.empty()){
                    s = tmp_word + ' ' + s;
                    tmp_word.clear();
                }
            }else{
                tmp_word = tmp_word + res[i];
            }
        }
        if (s[s.size()-1]==' '){
	    s = s.substr(0,s.size()-1);
        }
    }
};