class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return  1;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=10;
        int fact=81;
        int ct=8;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+fact;
            fact*=ct;
            ct--;
        }
        return dp[n];
    
    }
};