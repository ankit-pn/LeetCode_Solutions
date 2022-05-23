class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> vect;
        vector<int> arr;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                arr.push_back(matrix[j][i]);
            }
            vect.push_back(arr);
            arr.clear();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = vect[i][j];
            }
        }
        
    }
};