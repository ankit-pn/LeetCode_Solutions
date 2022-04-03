class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n=isConnected.size();
        vector<int> check(n,0);
        for(int i=0;i<n;i++){
            if(check[i]==0){
                ans++;
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1)
                dfs(isConnected,check,j);
            }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& isConnected, vector<int>& check,int i){
        if(check[i])
            return ;
        int n=isConnected.size();
        check[i]=1;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && check[j]==0){
            dfs(isConnected,check,j);
            }
        }
    }
};