// Binary Search
class Solution {
public:
    int mySqrt(int x) {
      if(x==0){
        return 0;
      }
      int left = 1;
      int right = INT_MAX;
      while(true){
        int mid = left + (right-left)/2;
        if(mid > x/mid){
          right = mid -1;
        }else{ // mid <= x/mid
          if( (mid+1) > x/(mid+1)  ){
            return mid;
          }
          left = mid + 1;
        }
      }
    }
};

// Newton method
class Solution {
public:
    int mySqrt(int x) {
      long r = x;
      while (r*r > x)
        r = (r + x/r) / 2;
      return r;
    }
};