class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int x=(a+b+c)-max({a,b,c});
        int mx=max({a,b,c});
        if(x<mx)
            return x;
        else
        return (x-mx)/2 + max({a,b,c});
    }
};