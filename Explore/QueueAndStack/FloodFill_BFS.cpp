// BFS
using namespace std;
class Solution {
private:
    
    struct coordinate
    {
        int x;
        int y;
        coordinate(int a,int b){
            x=a;y=b;
        };
    };
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldcolor = image[sr][sc];
        if(oldcolor == newColor){ //if new == old, return immediately, otherwise the program will get stuck in the loop
            return image;
        }
        image[sr][sc] = newColor;
        queue<coordinate> bfs;
        //coordinate tmp(sr,sc);
        bfs.push(coordinate(sr,sc));
        
        while(!bfs.empty()){
            int size = bfs.size();
            
            for(int i=0;i<size;++i){
                coordinate cur = bfs.front();
                bfs.pop();
                vector<coordinate> nbrs = get_nbrs(image,cur.x,cur.y,oldcolor,newColor);
                for(coordinate next:nbrs){
                    bfs.push(next);
                }
                
            }
        }
        return image;

        
    }

    vector<coordinate> get_nbrs(vector<vector<int>>& image, int sr,int sc,  int oldcolor,int newColor){
        //check if it is out of bound
        vector<coordinate> res;
        int len = image.size();
        int width = image[0].size();
        if( sr+ 1<len && image[sr+ 1][sc]==oldcolor ){
            image[sr+ 1][sc] = newColor;
            res.push_back(coordinate(sr+1,sc ));
        }
        if( sr - 1 >= 0  && image[sr- 1][sc]==oldcolor){
            image[sr- 1][sc]=newColor;
            res.push_back(coordinate(sr-1,sc ));
        }
        if( sc + 1 <width && image[sr][sc+1]==oldcolor){
            image[sr][sc+1]=newColor;
            res.push_back(coordinate(sr,sc+1 ));
        }
        if( sc - 1 >=0  && image[sr][sc-1]==oldcolor){
            image[sr][sc-1]=newColor;
            res.push_back(coordinate(sr,sc-1 ));
        }

        return res;
    }
};