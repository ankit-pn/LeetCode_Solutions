class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums,ans,0);
        return ans;
    }
    void dfs(vector<int>& arr,vector<vector<int>>&ans,int in){
        // never push temp by reference, just to make sure to note that point.
        // i hope it got accepted.
        // if(temp.size()==arr.size()){
        //     ans.push_back(temp);
        //     return;
        // }
        // for(auto &it:arr){
        //     temp.push_back(it);
        //     dfs(arr,ans,temp,in+1);
        //     temp.pop_back();
        // }
        // we cant use this type of arr loop , becs repetation will be there.
        // well this was not even the issue , just make a visited array.
        // for(int i=0;i<arr.size();i++){
        //     if(v[i]==0){
        //     temp.push_back(arr[i]);
        //     // v[i]=1;
        //     }
        //     dfs(arr,ans,temp,v);
        //     temp.pop_back();
        //     // v[i]=0;
        // }
        // well this all is not working , coming back to swap approch.
        int n=arr.size();
        if(in>=n)
       ans.push_back(arr);
        for(int i=in;i<n;i++){
            // for(int j=i+1;j<n;j++){
                swap(arr[in],arr[i]);
                dfs(arr,ans,in+1);
            // it will be in+1 , not i+1, becs you r looping fro overall in 
                swap(arr[in],arr[i]);
            // }
        }
        
        
    }
};