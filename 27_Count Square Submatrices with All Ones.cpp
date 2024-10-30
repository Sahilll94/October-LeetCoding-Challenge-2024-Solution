// Question Link : https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/?envType=daily-question&envId=2024-10-27

// Solution -> 

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count=0;
        int n=matrix.size();
        int m=matrix[0].size(); 
        

        cout<<n<<endl;
        cout<<m<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0 && j>0 && matrix[i][j]==1){
                    matrix[i][j]=min(matrix[i-1][j],min(matrix[i][j-1],matrix[i-1][j-1])) +1;
                }
                count+=matrix[i][j];
            }
        }
        return count;
    }
};