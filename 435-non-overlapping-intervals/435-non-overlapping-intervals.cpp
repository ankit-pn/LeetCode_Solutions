class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        // well another greedy solns.
        // all you need to sort the vector in ascending order and do nothing about it.
        // i still have no fucking idea where i am wrong.
        int n=arr.size();
        sort(arr.begin(),arr.end(),cmp);
        int i=1,c=0,end=arr[0][1];
        while(i<n){
            if(arr[i][0]<end){
                c++;
                i++;
            }else{
                end=arr[i][1];
                i++;
            }
        }
        return c;
    }
};