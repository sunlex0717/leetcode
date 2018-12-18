#include<algorithm>
#include<vector>
// https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89345/Easy-concept-with-PythonC%2B%2BJava-Solution
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto compare = [](const pair<int,int>& p1, const pair<int,int>& p2){
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };

        sort(people.begin(),people.end(),compare);
        
        vector<pair<int,int>> ret;

        for(auto & e : people){
            ret.insert(ret.begin()+e.second, e);
        }

        return ret;
        
    }
};