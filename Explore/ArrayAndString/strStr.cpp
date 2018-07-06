/*
 * this codes are shit , although it works fine, I need  to tink a more efficient state machine
 *
 *
 *
 * well
 * class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (!n) return 0;
        for (int i = 0; i < m - n + 1; i++) {
            int j = 0;
            for (; j < n; j++)
                if (haystack[i + j] != needle[j])
                    break;
            if (j == n) return i;
        }
        return -1;
    }
};
this is the soulution !!!!
https://leetcode.com/problems/implement-strstr/discuss/12956/Explained-4ms-Easy-C++-solution
*/

class Solution {
public:
    enum mState { wait,start,listening,found};
    int strStr(string haystack, string needle) {
      /*corner case*/
        if(needle.empty()){
          return 0;
        }
        if( haystack.empty() || (needle.size() > haystack.size()) ){
          return -1;
        }

        int size_haystack = haystack.size();
        int size_needle = needle.size();
        int ind = 0;
        int first = -1;
        int candidate_first = -1;
        int flag = 0;
        int pos = 0;
        int num_found = 0;
        char start_byte = needle[0];
        mState state = mState::wait;
        for(int i = 0;i<size_haystack;i++){
                switch (state) {
                case mState::wait:
                    if((haystack[i] == start_byte) ){

                        state = mState::start;
                    }
                    else{
                        break;
                    }
                case mState::start:

                    first = i;
                    pos = i;
                    ind++;
                    num_found = 1;
                    if(num_found == size_needle){
                        return first;
                    }
                    state = mState::listening;
                    std::cout<<" start : find "<<needle[ind-1] << " at "<<i <<endl;
                    break;

                case mState::listening:
                    if( (haystack[i] == start_byte) && (flag == 0)){
                        candidate_first = i;
                        flag = 1;
                        std::cout<<" a candidate start byte found at "<<i<<endl;
                    }
                    if(haystack[i] != needle[ind] ){
                        break;
                    }
                    if(pos + 1 == i ){
                        std::cout<<"find "<<needle[ind] << " at "<<i <<endl;
                        pos++;
                        ind ++;
                        num_found++;

                        if(num_found == size_needle){
                            return first;
                        }
                    }else{ //check if it is a new start byte
                        if(flag == 1 ){//a start byte
                            ind = 0;
                            i = candidate_first - 1;
                            state = mState::wait;
                            num_found = 0;
                            std::cout<<"go to candiate first "<<candidate_first-1<<endl;
                            flag = 0;
                        }else{
                            std::cout<<"fail at "<<i<< ", go to wait "<<endl;
                            ind = 0;
                            num_found = 0;
                            first = -1;
                            i --;
                            state = mState::wait;
                        }

                    }
                    break;
                }

            }

        return -1;

    }
};


