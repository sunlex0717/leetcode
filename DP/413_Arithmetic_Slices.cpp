class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {

      int len = A.size();
      if(len <3 ){
        return 0;
      }
      int res = 0;
      int cur = 0;
      int num = 0;
      vector<int> dis(len-1);
      
      for(int i = 0;i<len-1;i++){
        dis[i] = A[i+1] - A[i];
      }
      
      
      cur = dis[0];
      num = 1;
      for(int i =1;i<len-1;i++){
        if(dis[i] == cur){
          num++;
        }else{
          if(num>=2){
            res+=sum(num);
            num = 1;
          }
        }
        cur = dis[i];
      }
      if(num>=2){
          res+=sum(num);
          num = 1;
      }
      return res;
    }

    int sum(int s){
      int res = 0;
      for(int i=1;i<=s-1;i++){
        res+=i;
      }
      return res;
    }


};