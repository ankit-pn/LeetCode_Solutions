class Solution {
public:
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        // usinh helper function...
        return atmost(arr,k)-atmost(arr,k-1);
    }
    int atmost(vector<int>& arr,int k){
        unordered_map<int,int> mp;
        int j=0,res=0,n=arr.size();
        for(int i=0;i<n;i++){
            // if elememt is already present in map , then we decresing remaining count of k
            if(!mp[arr[i]])
                k--;
            // marking down count of that element in array.
            mp[arr[i]]++;
            // condition when k<0 , when we have to slide left part of window as usual.
            while(k<0){
                // we are moving the left part of window to right as usual, hence decreasing the count in array.
                mp[arr[j]]--;
                // now if count is equal to zero , then as usual increment the k, becz then we are excluding that element. becz if k is positive or zero the there is now need to find new window.
                if(mp[arr[j]]==0)
                    k++;
                
                j++;
                
            }
            // adding windows size to sum, becz that is sum of windows size which will be equal to total number of subarray.
            res+=(i-j+1);
        }
        return res;
    }
};