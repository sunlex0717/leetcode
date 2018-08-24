//recursion 
class Solution {
public:
    string decodeString(string s) {
        string res;
        int pos = 0;
        return decode_part(s,pos);

    }

    string decode_part(string s,int& index){
        int num = 0;
        string res;
        for(; index<s.size();index++){
            char cur = s[index];
            if(cur == '['){
                string curstring =  decode_part(s,++index);
                for(;num > 0;num--) res+=curstring;
            }else if(cur >= '0' && cur <='9'){
                num = num*10  + cur - '0';

            }else if(cur == ']'){
                return res;
            } else{
                res += cur;
            }
        }
        return res;
    }
    

};