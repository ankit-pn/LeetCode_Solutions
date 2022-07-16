class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n)
            return ;
        int i=0;
        while(i<m){
            if(nums1[i]>nums2[0]){
                swap(nums1[i],nums2[0]);
                int j=0;
                while(j+1<n && nums2[j]>nums2[j+1]){
                    swap(nums2[j],nums2[j+1]);
                    j++;
                }
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n;i++)
            nums1[i+m]=nums2[i];
    }
};