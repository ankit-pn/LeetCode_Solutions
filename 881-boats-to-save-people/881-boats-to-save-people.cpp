class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(),arr.end());
        int c=0,n=arr.size(),i=0,j=n-1;
        while(i<=j){
            if(arr[i]+arr[j]<=limit){
                c++;
                i++;
                j--;
            }
            else{
                c++;
                j--;
            }
        }
        return c;
            
    }
};