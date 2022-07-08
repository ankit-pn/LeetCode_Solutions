class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        int n=arr.size();
        int i=1,end=arr[0][1],c=0;
        while(i<n){
            if(arr[i][0]>end){
                c++;
                end=arr[i][1];
            }
            i++;
        }
        return c+1;
    }
};