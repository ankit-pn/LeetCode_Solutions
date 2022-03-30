class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> check(n+1,0);
        // for(int i=0;i<n;i++){
        //     if(check[i]==false)
        //     dfs(rooms,check,i);
        // }
        dfs(rooms , check , 0);
        for(int i=1;i<n;i++){
            // cout<<check[i]<<"\n";
        }
        for(int i=1;i<n;i++){
            if(check[i]==false)
                return false;
        }
        return true;
    }
    void dfs(vector<vector<int>> &rooms,vector<bool> &check,int i){
        if(check[i])
            return;
        check[i] = 1;
        int n=rooms.size();
        // if(i==n-1)
        //     return ;
        for(int j=0;j<rooms[i].size();j++){
            cout<<rooms[i][j]<<' ';
            dfs(rooms,check,rooms[i][j]);
            check[rooms[i][j]]=true;
        }
    }
};