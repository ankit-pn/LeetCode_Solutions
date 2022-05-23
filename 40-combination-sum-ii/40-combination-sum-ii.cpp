class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> res1;
        int i=0;
        sort(arr.begin(),arr.end());
        g(0,target,res1,arr);
        return res;
    }
    void g(const int order,const int target,vector<int> &local,vector<int> &num){
        
        if (target == 0)
    {
        res.push_back(local);
        return;
    }
    else
    {
        for (int i = order; i < num.size(); i++) // iterative component
        {
            if (num[i] > target)
                return;
            if (i && num[i] == num[i - 1] && i > order)
                continue; // check duplicate combination
            local.push_back(num[i]),
                g(i + 1, target - num[i], local, num); // recursive componenet
            local.pop_back();
        }
    }
    }
};