class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res,"",n,n);
        return res;
    }

    void backtrack(vector<string>& result, string tmp, int n, int m){
      if(m==0 && n==0){
        result.push_back(tmp);
        return;
      }
      else{
        if(m>0) backtrack(result,tmp+"(",n,m-1);
        if(n>0 && n>m) backtrack(result,tmp+")",n-1,m);
      }
    }
};