class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool f1=1,f2=1;
        int n=s1.length();
        for(int i=0;i<n;i++){
            if(s1[i]<s2[i]){
                f1=0;break;
            }
        }
         for(int i=0;i<n;i++){
            if(s1[i]>s2[i]){
                f2=0;break;
            }
        }
        return f1||f2;
    }
};