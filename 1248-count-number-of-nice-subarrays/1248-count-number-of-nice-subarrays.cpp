class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // same as previous.
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int>&arr,int k){
         int i=0,res=0,n=arr.size();
        for(int j=0;j<n;j++){
            if(arr[j]%2)
                k--;
            while(k<0){
                if(arr[i]%2)
                    k++;
                i++;
            }
            res+=(j-i+1);
        }
        return res;
        
    }
};