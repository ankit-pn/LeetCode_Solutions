class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length(),m=haystack.length();
        int i=0,j=1;
        vector<int> ls(n,0);
        while(i<n && j<n){
            if(needle[i]==needle[j]){
                ls[j]=i+1;
                i++;
                j++;
            }
            else{
                if(i)
                i=ls[i-1];
                else
                j++;
            }
        }
      i=0,j=-1;
        int f=0,c=0;
        while(i<m && j<n-1){
            if(haystack[i]==needle[j+1]){
                c++;
                if(c==n){
                    f=1;
                break;    
                }
                i++;
                j++;
            }
            else{
                 if(j>=0)
                j=ls[j]-1;
                else
                i++;
                
                c=j+1;
               
            }
            cout<<c<<" ";
        }
        if(f)
            return i-n+1;
        else
            return -1;
    }
    
};