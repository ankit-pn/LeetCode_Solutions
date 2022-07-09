class Solution {
public:
    int maximumDifference(vector<int>& arr) {
        // trying to provide soln in O(n)
        
        // 7 1 5 4
        
        // max 7 7 7 7
        // min      1 1 4 4
        // well this question is same to best time to buy and sell stocks.
        
        // well work will be done by finding min array only.
        
        // 7 1 1 1
        //original array will be..
        //7 1 5 4
        // becs if we know min element upto this point point we treat element at that index and considering substracting it.
        int mi=INT_MAX,ans=-1,n=arr.size();
        for(int i=0;i<n;i++){
            mi=min(arr[i],mi);
            ans=max(ans,arr[i]-mi);
        }
        return ans<=0?-1:ans;
    }
};