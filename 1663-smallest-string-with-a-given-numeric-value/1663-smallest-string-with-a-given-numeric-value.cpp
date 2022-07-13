class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        s.resize(n,'a');
        k-=n;int i=n-1;
        while(i>=0){
            if(k>=25){
            k-=25;
                s[i]='z';
                i--;
            }
            else{
                s[i]='a'+k;
                break;
            }
        }
        return s;
    }
};