class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n,0);
        dp[0]=1;
        if(s[0]=='0')
            return 0;
        else if(s.length()==1)
            return 1;
        if(s[1]=='0' && s[0]>'2')
                return 0;
        if(s[1]=='0' || (s[0]>'2' || (s[0]=='2' && s[1]>'6')))
        dp[1]=1;
        else
        dp[1]=2;
        cout<<dp[1];
        for(int i=2;i<n;i++){
            // string temp="";
            // temp+=s[i-1];
            // temp+=s[i];
            // int x=stoi(temp);
            if(s[i]=='0' && s[i-1]=='0')
                return 0;
            else if(s[i]=='0' && s[i-1]>'2')
                return 0;
            else if(s[i]=='0')
                dp[i]=dp[i-2];
            else if(s[i-1]=='0')
                dp[i]=dp[i-1];
            else if(!(s[i-1]>'2' || (s[i-1]=='2' && s[i]>'6')))
                dp[i]=dp[i-1]+dp[i-2];
            else
                dp[i]=dp[i-1];
        }
        for(auto it:dp)
            cout<<it<<"\n";
        return dp[n-1];
    }
};