
#include <algorithm> 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_ind = 0;
        int sell_ind = 1;
        int res = 0;
        int size = prices.size();
        int possible_ind = 0;
        if(size <= 1){
          return res;
        }

        if(size == 2){
          return std::max(prices[1]-prices[0],0);
        }
        //base case
        if(prices[0] >= prices[1]){
          buy_ind = 1;
          sell_ind = 1;
          possible_ind = 1;
        }else{
          buy_ind = 0;
          sell_ind = 1;
          possible_ind = buy_ind;
          res = prices[sell_ind] - prices[buy_ind];
        }
        for(int i = 2;i<size;++i){
          int amount_buy = prices[buy_ind];
          int amount_sell = prices[sell_ind];
          int possible_val = prices[possible_ind];
          int cur = prices[i];
          //std::cout << cur << " buy ind = " << buy_ind << " sell ind " << sell_ind << "possible_ind = " << possible_ind << " res = " << res << std::endl;
          if(cur - possible_val > res){
            buy_ind = possible_ind;
            res = cur - possible_val;
            sell_ind = i;
            
          }

          if(cur <= amount_sell && cur >= amount_buy){
            //std::cout << cur<< " continue" <<std::endl;
            continue;
            
          }else if( cur > amount_sell ){
            
              sell_ind = i;
              res = cur - prices[buy_ind];
              //std::cout << cur<< " sell_ind = " << i << " res = " << res << std::endl;
            
            continue;
          }else if( cur < amount_buy){
            //std::cout << cur <<" possible_ind = "<< i << std::endl;
            if(cur <= possible_val)
              possible_ind = i;
          }
        }

        return res;
    }
};