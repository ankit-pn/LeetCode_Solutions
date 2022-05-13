class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int mi=INT_MAX;
        int n=s.size();
        for(int i=0;i<n;i++){
            mi=min(mi,(int)s[i].length());
        }
        string ans;
        for(int j=0;j<mi;j++){
            char x=s[0][j];
            int f=1;
        for(int i=1;i<n;i++)
            if(s[i][j]!=x)
                f=0;
            if(f==0)
            break;
        else
            ans+=x;
        }
        return ans;
    }
};