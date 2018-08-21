//use stack
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        stack<char> s1;

        for(char c:s){
            if(is_right(c)){
                if(s1.empty()) return false;
                if(check_brackets(s1.top(),c) ){
                   // cout << c;
                    s1.pop();
                }else{
                    return false;
                }
            }else{
                //cout << c;
                s1.push(c);
            }

        }

        if(s1.empty()){
            return true;
        }else{
            return false;
        }
        
    }

    bool is_right(char c){
        if(c == ')' || c == '}' || c== ']'){
            return true;
        }
        return false;
    }

    bool check_brackets(char left, char right){
        if(left == '(' && right == ')' ) return true;
        if(left == '{' && right == '}' ) return true;
        if(left == '[' && right == ']' ) return true;

        return false;
    }
};