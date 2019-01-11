#include<bits/stdc++.h>
using namespace std;
bool Find(vector<vector<int>>& input,int target){
  int rows = input.size();
  int cols = input[0].size();

  int row = 0;
  int col = cols -1;
  while(row < rows && col >=0){
    if(input[row][col]==target){
      cout<<"found"<<endl;
      return true; //found
    }else if(input[row][col]>target){
      -- col ;
      
    }else{
      ++ row;
    }
  }
  cout<<"not found"<<endl;
  return false;
}

int main(int argc, char const *argv[])
{
  vector<vector<int>> a{{1,2,8,9},
                        {2,4,9,12},
                        {4,7,10,13},
                        {6,8,11,15}};
  
  Find(a,10);
  return 0;
}
