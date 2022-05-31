class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int c=image[sr][sc];
       
        dfs(image,sr,sc,newColor,c);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,int c){
         int m=image.size();
        int n=image[0].size();
        if(sr<0 || sc<0 || sr>=m || sc>=n || image[sr][sc]!=c || c==newColor)
            return ;
            image[sr][sc]=newColor;
        
        dfs(image,sr-1,sc,newColor,c);
         dfs(image,sr,sc-1,newColor,c);
             dfs(image,sr,sc+1,newColor,c);
             dfs(image,sr+1,sc,newColor,c);
        return ;
    }
};