//TODO: can not solved long string
// we need use general method like a for-loop to solve this problem.

#include <iostream>   // std::cout
#include <string>  
#include <math.h> 
#include <stdlib.h> 
class Solution {
public:
    string addBinary(string a, string b) {
        char digits[] = {'0', '1' };
        string binary;
        int carry_bit = 0;
        int a_i;
        int b_i;
        int t;
        int size_a = a.size();
        int size_b = b.size();
        int min_size = min(size_a,size_b);
        int max_size = max(size_a,size_b);
        std::reverse(a.begin(),a.end());
        std::reverse(b.begin(),b.end());
        for(int i=0;i<max_size + 1;i++){
            if( i < min_size){
                a_i = a[i] - 48;
                b_i = b[i] - 48;
                t =  a_i + b_i + carry_bit;
                switch (t)
                {
                    case 0:
                        binary.push_back('0');
                        carry_bit = 0;
                        break;
                
                    case 1:
                        binary.push_back('1');
                        carry_bit = 0;
                        break;

                    case 2:
                        binary.push_back('0');
                        carry_bit = 1;
                        break;

                    case 3:
                        binary.push_back('1');
                        carry_bit = 1;
                        break;
                }
            }
            else{
                if(i < max_size){
                    if(size_a > size_b){
                        a_i = a[i] - 48;
                        t = a_i  + carry_bit;
                        switch (t)
                        {
                            case 0:
                                binary.push_back('0');
                                carry_bit = 0;
                                break;
                        
                            case 1:
                                binary.push_back('1');
                                carry_bit = 0;
                                break;

                            case 2:
                                binary.push_back('0');
                                carry_bit = 1;
                                break;
                        }

                    }
                    else if (size_a < size_b){
                        b_i = b[i] - 48;
                        t = b_i  + carry_bit;
                        switch (t)
                        {
                            case 0:
                                binary.push_back('0');
                                carry_bit = 0;
                                break;
                        
                            case 1:
                                binary.push_back('1');
                                carry_bit = 0;
                                break;

                            case 2:
                                binary.push_back('0');
                                carry_bit = 1;
                                break;
                        }

                    }
                }else if(i == max_size){
                    if(carry_bit == 1){
                        binary.push_back('1');
                    }
                }
            }
        }
        std::reverse(binary.begin(),binary.end());
        return binary;
    }
};
