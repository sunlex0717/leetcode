//I have no idea about this . 
//From discussion board I know that I should use BFS to find the shortest path between initial state and target.


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dds(deadends.begin(),deadends.end());//use iterator to construct set.
        unordered_set<string> visited; //a set to store visited string.

        queue<string> bfs;
        string init = "0000";
        if(dds.find(init)!=dds.end()) return -1; //if deadend contains 
        bfs.push(init);
        visited.insert(init);

        int res = 0;
        while(!bfs.empty()){
            ++res;
            int size = bfs.size();
            for(int i=0; i< size; ++i){
                string key = bfs.front();
                bfs.pop();
                vector<string> nbrs = move(Nbrs(key));
                for(auto s:nbrs){

                    if(s == target) return res;
                    if(visited.find(s) != visited.end()) continue;
                    if(dds.find(s) == dds.end()){
                        visited.insert(s);
                        bfs.push(s);
                    }
                }
            }
            
        }

        return -1;
        
    }

    vector<string> Nbrs(string input){
        vector<string> res;
        for(int i=0;i<4;++i){
            string tmp = input;
            tmp[i] = (input[i] - '0' + 1)%10 + '0';//increment by 1
            res.push_back(tmp);
            tmp[i] = (input[i] - '0' - 1 + 10)%10 + '0';//decrement by 1
            res.push_back(tmp);

        }
        return res;
    }
};