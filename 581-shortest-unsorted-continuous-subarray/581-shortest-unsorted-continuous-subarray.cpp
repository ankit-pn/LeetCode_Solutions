class Solution {
public:
    int findUnsortedSubarray(vector<int>& temp) {
        if(is_sorted(temp.begin(),temp.end()))
            return 0;
        vector<int> arr=temp;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int i=0,j=n-1;
        while(i<=j && i<n && j>=0){
            if(arr[i]==temp[i])
                i++;
            if(arr[j]==temp[j])
                j--;
            if(arr[i]!=temp[i] && arr[j]!=temp[j])
                break;
        }
        return j-i+1;
    }
};