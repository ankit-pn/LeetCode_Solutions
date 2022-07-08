class Solution {
public:
    int count(int n){
        if(n%2)
            return 0;
        int c=0;
        while(n%2==0){
            n/=2;
            c++;
        }
        return c;
    }
    int integerReplacement(int n) {
        if(n==INT_MAX)
            return 32;
        if(n==1)
            return 0;
        if(n%2==0)
            return integerReplacement(n/2)+1;
        else{
            if((n+1)%4==0 && n-1!=2)
                return integerReplacement(n+1)+1;
            // int x1=count(n+1);
            // int x2=count(n-1);
            // if(x1<x2)
            //     return integerReplacement(n+1)+1;
            else
                return integerReplacement(n-1)+1; 
        }
    }
};