// we can consider BFS.
// construct a graph with each node which has n edges 
class Solution {
public:
    int numSquares(int n) {
        
        vector<int> candidate_number;
        vector<int> CntPerfect(n); // to check if this node is visited or not

        for(int i=1;i*i <= n;i++){
            candidate_number.push_back(i*i); // neighbors of each node.
            CntPerfect[i*i-1] =1;
        }

        if(candidate_number.back()==n){ //check if the target node is in the initial queue or not.
            return 1;
        }

        queue<int> BFS;
        for(auto a : candidate_number){
            BFS.push(a);// root node, we have different candidate start points here
        }
        int res = 1; //step

        

        while(!BFS.empty()){
            res ++;
            int size = BFS.size();
            for(int i=0;i<size;i++){
                int tmp = BFS.front();
                BFS.pop();
                
                for(auto s:candidate_number){
                    if(tmp + s == n) return res;
                    else if(tmp + s < n && (CntPerfect[tmp + s -1] == 0 )){
                        CntPerfect[tmp + s -1] =res;
                        BFS.push(tmp + s);
                    }
                    else if(tmp + s > n){
                        break;
                    }
                }
            }


        }
        return 0;



    }
};