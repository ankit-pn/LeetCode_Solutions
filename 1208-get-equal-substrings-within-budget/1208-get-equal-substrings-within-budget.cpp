class Solution {
public:
    int equalSubstring(string s, string t, int k) {
        // using sliding window becz it is best.
        int i=0,res=0,n=s.length();
        for(int j=0;j<n;j++){
            k-=abs(s[j]-t[j]);
            while(k<0){
                k+=abs(s[i]-t[i]);
                i++;
            }
            res=max(res,j-i+1);
        }
        return res;
    }
};