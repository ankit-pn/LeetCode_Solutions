class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        if(n==1)
            return 0;
        int i=0,j=1;
        vector<int> ls(n,0);
        while(i<n && j<n){
            if(s[i]==s[j]){
                ls[j]=i+1;
                i++;
                j++;
            }
            else{
                if(i>0)
                    i=ls[i-1];
                else
                    j++;
            }
        }
        int x=*max_element(ls.begin(),ls.end());
        int c=0;
        for(auto it:ls)
            cout<<it<<" ";
        for(int i=0;i<n;i++){
            if(ls[i]==x)
                c++;
        }
        int len=n-x;
        string s1=s.substr(0,len);
        string s2=s.substr(n-len,len);
        if(x==0)
            return 0;
        return (s1==s2);
    }
};