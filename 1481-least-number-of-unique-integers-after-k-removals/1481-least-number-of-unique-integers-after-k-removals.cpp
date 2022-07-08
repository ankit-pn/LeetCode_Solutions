class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto &it:arr)
            mp[it]++;
        vector<int> temp;
        for(auto &it:mp){
            temp.push_back(it.second);
        }
        sort(temp.begin(),temp.end());
        int i=0;
        int sum=0;
        int n=temp.size();
        while(i<temp.size()){
            sum+=temp[i];
            if(sum>k)
                return n-i;
            i++;
        }
        return 0;
        // look when ever you will not able to write greedy.
        // just take some ex
        // 1 1 1 1 2 2 4
        // vro go nd learn writing some greedy code.
    }
};