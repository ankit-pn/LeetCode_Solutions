class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         if(!n)
//             return ;
//         int i=0;
//         int j=0;
//         while(i<m){
//             if(nums1[i]>nums2[j]){
//                 swap(nums1[i],nums2[j]);
                
//                 while(j+1<n && nums2[j]>nums2[j+1]){
//                     swap(nums2[j],nums2[j+1]);
//                     j++;
//                 }
               
//             }
//            i++;
//         }
//         for(int i=0;i<n;i++)
//             nums1[i+m]=nums2[i];
        if(m==0){
            nums1=nums2;
        return;
        }
        
       int i=m-1,j=n-1,c=n+m-1;
        while((i>=0 && j>=0) && c>=0){
            if(nums2[j]>nums1[i]){
                nums1[c]=nums2[j];
                j--;
            }
            else{
                nums1[c]=nums1[i];
                i--;
            }
            c--;
        }
        while(j>=0){
            nums1[c]=nums2[j];
            c--;
            j--;
        }
    }
};