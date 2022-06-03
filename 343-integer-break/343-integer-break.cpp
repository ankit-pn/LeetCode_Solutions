class Solution {
public:
    int integerBreak(int n) {
        if(n==2)
            return 1;
        else if(n==3)
            return 2;
        vector<int> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++){
            dp[i]=max(2*dp[i-2],3*dp[i-3]);
        }
        return dp[n];
        
    }
};