class Solution {
public:
    string longestPrefix(string s) {
         int n=s.length();
        vector<int> dp(n+1,0);
        int i=0,j=1;
        while(j<n && i<n){
            if(s[i]==s[j]){
                dp[j]=i+1;
                i++;
                j++;
            }
            else{
                if(i>0)
                    i=dp[i-1];
                else
                    j++;
            }    
        }
        for(auto it:dp)
            cout<<it<<" ";
        return s.substr(0,dp[n-1]);
    }
};