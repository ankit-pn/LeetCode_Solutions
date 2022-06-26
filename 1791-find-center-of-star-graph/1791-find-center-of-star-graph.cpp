class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int x=edges[0][0];
        int y=edges[0][1];
        int x1=edges[1][0];
        int y1=edges[1][1];
        if(x==x1 || x==y1)
            return x;
        else 
            return y;
    }
};