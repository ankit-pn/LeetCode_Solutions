class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int b1=b.length();
        int a1=a.length();
        int x=b1/a1+(b1%a1==0 ? 0 : 1);
        string d="";
        for(int i=0;i<x;i++)
            d+=a;
        cout<<x<<"";
        if(d==b){
            return x;
        }
        else if(d.length()==b1){
            // cout<<"mdc";
            d+=a;
            // cout<<kmp("asdfgh","fgh");
            return (kmp(d,b) ? x+1 : -1);
        }
        else
            return (kmp(d,b) ? x : (kmp(d+a,b) ? x+1 : -1));
    }
    bool kmp(string a,string s){
        int n=s.length();
        int i=0,j=1;
        vector<int> dp(n,0);
        while(i<n && j<n){
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
        i=0,j=-1;
        int c=0;
        while(i<a.length()){
            if(a[i]==s[j+1]){
                i++;
                c++;
                if(c==n)
                    return 1;
                j++;
            }
            else{
                if(j>=0)
                j=dp[j]-1;
                else
                i++;
                c=j+1;
            }
        }
        return 0;
    }
};