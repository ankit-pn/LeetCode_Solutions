class Solution {
public:
    #define ll long long
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1)
            return 1;
        
        int m=primes.size();
        vector<vector<ll>> dp(m+1,vector<ll> (n+1));
        
        dp[1][1] = 1;
        for(int j = 2; j <= n ;++j){
            dp[1][j] = primes[0]*dp[1][j-1];
            if(dp[1][j] >= 1e15)
                dp[1][j] = 1e15;
        }
        
        for(int i=2;i<=m;i++){
            int p1=2,p2=1;
            for(int j=1;j<=n;j++){
                if(j==1){
                    dp[i][j]=1;
                    // continue;
                }
                else{
                    // if(p1<m && p2<m)
                    dp[i][j]=min(dp[i-1][p1],primes[i-1]*dp[i][p2]);
                    // else if(p1>m && p2<m)
                    //     dp[i][j]=primes[i-1]*dp[i][p2];
                    // else
                    //     dp[i][j]=dp[i-1][p1];
                    if(dp[i][j]==dp[i-1][p1])
                        p1++;
                    else
                        p2++;
                }
            }
        }
        return dp[m][n];
    }
};