// shortest path, so we have to use BFS
// if matrix[i][j]==0 then it is still zero.
// if matrix[i][j]==1 then it could still be 1, in this case we should record if_visited.
// if matrix[i][j] == 2 then if_visited is not necessary.
// let's first use a extra visited matrix.
// for every non-zero node, we need do a BFS, (target : 0)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int width = matrix[0].size();
        vector<vector<bool>> visited(len,vector<bool>(width,false));

    }

    int bfs_node(vector<vector<int>>& matrix, int i, int j){
        
    }
};