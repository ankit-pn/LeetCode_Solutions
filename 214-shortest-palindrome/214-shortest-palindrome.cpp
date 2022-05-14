class Solution {
public:
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=2*s.length()+1;
        vector<int> dp(n,0);
       string temp=s+'#'+t;
        int i=0,j=1;
        while(i<n && j<n){
            if(temp[i]==temp[j]){
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
        int len=dp[n-1];
        string q=s.substr(len,n-len);
        reverse(q.begin(),q.end());
        return q+s;
        
    }
};