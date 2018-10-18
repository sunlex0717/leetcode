// OPT(i) = min{opt(i-1) + cost[i-1], opt(i-2) + cost[i-2]}
// opt(0) = 0; opt(1) = 0; end : opt(cost.size())
#include<algorithm>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if(size <= 1){
            return 0;
        }
        int opt_pre = 0; // i -1
        int opt_pre_pre = 0; //i-2
        if(size >2 ){
            for(int i = 2; i<size;i++){
            int tmp = std::min(opt_pre + cost[i-1], opt_pre_pre + cost[i-2]);
            opt_pre_pre = opt_pre;
            opt_pre = tmp;
            //std::cout << "tmp = " << tmp << " opt_pre = " <<opt_pre <<" opt_pre_pre = "<<opt_pre_pre << std::endl;
         }
        }
        

        return std::min(opt_pre+cost[size-1],opt_pre_pre + cost[size-2]);
    }

};