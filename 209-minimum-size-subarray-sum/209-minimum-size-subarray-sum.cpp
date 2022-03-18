class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
       int i=0,j=0;
        int ans=INT_MAX;
        int sum=0;
        while(j<arr.size()){
            sum+=arr[j];
            j++;
            while(sum>=target){
                ans=min(ans,j-i);
                sum-=arr[i];
                i++;
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};