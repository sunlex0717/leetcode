#include<bits/stdc++.h> 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if(size == 0){
          return 0;
        }
        int res = 0;
        int pos1 = 0;
        int pos2 = size - 1;
        while(pos1 < pos2){
          int h = min(height[pos1],height[pos2]);
          res = max(res,(pos2-pos1)*h);
          while(height[pos1]<=h && pos1 < pos2) pos1++;
          while(height[pos2]<=h && pos1 < pos2) pos2--;

        }
        return res;
    }
};