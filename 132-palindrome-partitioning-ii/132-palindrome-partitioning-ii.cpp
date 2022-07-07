class Solution {
public:
    bool is_palindrome(string &s,int i,int j){
        j--;
       while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int minCut(string s) {
        // unlike previous question , which was comlete backtracing this question has something to deal with.
        int n=s.length();
        int start=0,end=n-1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        
        // for(int i=0;i<=n;i++)
        //     cout<<dp[i][end]<<" ";
        return dfs(s,start,end,dp);
    }
    int dfs(string &s,int start,int end,vector<vector<int>>&dp){
         if(start>=end || is_palindrome(s,start,end+1))
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        int ans=1e6;
            for(int i=start;i<end;i++){
                if(is_palindrome(s,start,i+1)){
                int x = dfs(s,i+1,end,dp)+1;
                    ans=min(x,ans);
                }
            }
        // why you cant use common sense in indexing.
        // you are such a loser.
        dp[start][end]=ans;
        return ans;
    }
};