#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> map; // key = num[i] val : frequent
       for(int e:nums){
         map[e] ++;
       }

       vector<int> res;
       priority_queue<pair<int,int>> pq([](const pair<int,int>$ e1, const pair<int,int>& e2)
                                          {return e1.first>e2.first});
       for(const decltype(map)::value_type& e:map ){
         pq.push(make_pair(e.second,e.first));
         if(pq.size() > map.size() - k){
           res.push_back(pq.top().second);
           pq.pop();
         }
       }
       reverse(res.begin(),res.end()); 
       return res;
    }
};