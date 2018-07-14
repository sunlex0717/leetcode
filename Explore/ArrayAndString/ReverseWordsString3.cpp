class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        if( len == 0){
            return {};
        }
        s = s + ' ';
        string res;
        string r_word;
        for(int i = 0; i < len +1 ; i++){
            if(s[i] == ' '){
                if(!r_word.empty()){
                    if(res.empty()){
                        res = r_word;
                        
                    }else{
                        res = res + ' ' + r_word;
                    }
                    r_word.clear();
                    
                }
            }else{
                r_word = s[i]+r_word;
            }
        }

        if( res[res.size()-1] == ' '){
            res.pop_back();
        }
        return res;
        
    }
};



/// a two pointer solution
    string reverseWords(string s) {
        size_t start = 0;
        for (size_t i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }