class Solution {
public:
    static bool cmp(vector<int> &a1,vector<int> &a2){
        return a1[0]<=a2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        // well this is the problem that you are not able to solve ealier now you got approch , leemme solve it today.
        
        // sorting by starting time.
        // you are turning into legends.
        // solveed, you have to maintain end variable baby.
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int i=0,n=arr.size(),end=arr[0][1];
        int start=arr[0][0];
        while(i<n){
             end=max(end,arr[i][1]);
            if(i+1<n && end<arr[i+1][0]){
                ans.push_back({start,end});
                i++;
                if(i<n){
                start=arr[i][0];
                end = arr[i][1];
                }
            }
            else if(i+1==n){
                ans.push_back({start,end});
                i++;
            }
            else{
            i++;
            }
        }
        
        return ans;
        
        
    }
};