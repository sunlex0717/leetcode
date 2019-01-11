#include<bits/stdc++.h>

// change the original vector
using namespace std;
bool duplicate_1(vector<int>& input , int* duplication){
  int length = input.size();
  if(length == 0 ){
    return false;
  }

  for(int i = 0 ;i<length;++i){

    while(i != input[i]){

      int m = input[i];
      if( m == input[m]){
        *duplication = m;
        return true;
      }else{
        swap(input[i],input[input[i]]);
      }
    } 
  }
   return false;
}






int main(int argc, char const *argv[])
{
  vector<int> a{2,3,1,0,2,5,3};
  vector<int> b{2,3,5,4,3,2,6,7};
  int res;
  duplicate_1(b,&res);
  cout<<res<<endl;
  return 0;
}
