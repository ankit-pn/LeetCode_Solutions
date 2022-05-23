class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int> local;
        int index=0;
        g(arr,index,local);
        return ans;
    }
    void g(vector<int>& arr,int index,vector<int> &local){
            ans.push_back(local);
        for(int i=index;i<arr.size();i++){
            local.push_back(arr[i]);
            index++;
            g(arr,index,local);
            local.pop_back();
        }
    }
};