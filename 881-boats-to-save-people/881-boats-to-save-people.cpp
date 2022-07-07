class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        sort(arr.begin(),arr.end());
        int c=0,n=arr.size(),i=0,j=n-1;
        // well you have to use two pointer , not implement anything without proper thinking you foolish , because at end of day it is gonna wrong , they why to waste time on random things.
        //periods.
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