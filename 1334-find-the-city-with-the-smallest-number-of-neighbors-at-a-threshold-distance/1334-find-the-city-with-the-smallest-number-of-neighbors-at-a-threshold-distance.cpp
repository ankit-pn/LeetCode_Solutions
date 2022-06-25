class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dp(n,vector<int> (n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            dp[edges[i][0]][edges[i][1]]=edges[i][2];
            dp[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++)
            dp[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int x=INT_MAX;
        int in=0;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(i!=j && dp[i][j]<=dt)
                    c++;
            }
            if(c<=x){
                x=c;
                in=i;
            }
        }
        return in;
    }
};