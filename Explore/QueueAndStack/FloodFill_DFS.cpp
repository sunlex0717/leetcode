//DFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldcolor = image[sr][sc];
        if(oldcolor == newColor){ //if new == old, return immediately, otherwise the program will get stuck in the loop
            return image;
        }
        dfs(image,sr,sc,newColor,oldcolor);

        return image;

        
    }

    void dfs(vector<vector<int>>& image,int sr,int sc,int newColor,int oldcolor){
        int len = image.size();
        int width = image[0].size();
        if( sr<0 || sr >=len || sc < 0 || sc >= width ){
            return;
        }
        if(image[sr][sc] != oldcolor){ //no edge 
            return;
        }
        image[sr][sc] = newColor;
        dfs(image,sr+1,sc,newColor,oldcolor);
        dfs(image,sr-1,sc,newColor,oldcolor);
        dfs(image,sr,sc+1,newColor,oldcolor);
        dfs(image,sr,sc-1,newColor,oldcolor);

        
    }
};