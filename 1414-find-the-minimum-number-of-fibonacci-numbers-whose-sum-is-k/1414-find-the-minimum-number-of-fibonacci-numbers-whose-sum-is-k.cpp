class Solution {
public:
    int nearest(int k){
        int a=1,b=1;
        while(b<=k){
            int temp=b;
            b=a+b;
            a=temp;
        }
        return a;
    }
    int findMinFibonacciNumbers(int k) {
        if(k==0)
            return 0;
        if(k==1)
            return 1;
        // cout<<nearest(19);
        return findMinFibonacciNumbers(k-nearest(k))+1;
    }
};