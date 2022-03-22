class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
         for(int i=0;i<m;i++){
             if(board[i][0]=='O')
            dfs(board,i,0);
              if(board[i][n-1]=='O')
            dfs(board,i,n-1);
         }
        for(int i=0;i<n;i++){
             if(board[0][i]=='O')
            dfs(board,0,i);
             if(board[m-1][i]=='O')
            dfs(board,m-1,i);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='T')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
    void dfs(vector<vector<char>>& board,int sr,int sc){
         int m=board.size();
        int n=board[0].size();
        if(sr<0 || sc<0 || sr>=m || sc>=n || board[sr][sc]!='O')
            return ;
        board[sr][sc]='T';
        dfs(board,sr-1,sc);
         dfs(board,sr+1,sc);
         dfs(board,sr,sc-1);
         dfs(board,sr,sc+1);
    }
};