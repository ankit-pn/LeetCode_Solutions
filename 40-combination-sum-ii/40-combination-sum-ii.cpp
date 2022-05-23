class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> res1;
        int i=0;
        sort(arr.begin(),arr.end());
        g(0,target,res1,arr);
        return ans;
    }
    void g(const int index,const int target,vector<int> &res,vector<int> &arr){
        
        if (target == 0)
    {
        ans.push_back(res);
        return;
    }
    else
    {
        for (int i = index; i < arr.size(); i++) // iterative component
        {
            if (arr[i] > target)
                return;
            if (i && arr[i] == arr[i - 1] && i > index)
                continue; // check duplicate combination
            res.push_back(arr[i]),
                g(i + 1, target - arr[i], res, arr); // recursive componenet
            res.pop_back();
        }
    }
    }
};