// asked in adobe
 Geekland there is a grid of coins of size N x N. You have to find the maximum sum of coins in any sub-grid of size K x K.
Note: Coins of the negative denomination are also possible at Geekland.

Example 1:

Input: N = 5, K = 3 
mat[[]] = {1, 1, 1, 1, 1} 
          {2, 2, 2, 2, 2} 
          {3, 8, 6, 7, 3} 
          {4, 4, 4, 4, 4} 
          {5, 5, 5, 5, 5}
Output: 48
Explanation: {8, 6, 7}
             {4, 4, 4}
             {5, 5, 5}
has the maximum sum

Example 2:

Input: N = 1, K = 1
mat[[]] = {{4}} 
Output: 4
Your Task:  
You don't need to read input or print anything. Complete the function Maximum_Sum() which takes the matrix mat[], size of Matrix N, and value K as input parameters and returns the maximum sum.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ K ≤ N ≤ 103
-5*105 ≤ mat[i][j] ≤ 5*105



class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        int ans = 0;
        int strip[N][N];
        for(int j = 0 ; j < N ;j++)
        {
            int sum = 0;
            for(int i = 0 ; i < K ;i++)
            {
                sum += mat[i][j];
            }
            strip[0][j] = sum;
            
            for(int i = 1 ; i <= N - K; i++)
            {
                sum += (-mat[i -1][j] + mat[i + K - 1][j]);
                strip[i][j] = sum;
            }
        }
        for(int i = 0 ; i <= N - K ; i++)
        {
            int sum = 0;
            for(int j = 0 ; j < K ;j++)
            {
                sum += strip[i][j];
            }
            ans = max(ans, sum);
            for(int j = 1; j <= N - K; j++)
            {
                sum += (-strip[i][j - 1] + strip[i][j + K -1]);
                ans = max(ans, sum);
            }
        }

        return ans;
    }  
};
// tc o(N*N)
// sc o(N*N)
// accpeted


class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        int ans = 0;
        for(int i = 0 ; i <= N - K; i++)
        {
            for(int j = 0 ; j <= N - K ; j++)
            {
                int sum = 0;
                for(int p = i ; p < K + i ; p++)
                {
                    for(int q = j ; q < K + j ; q++)
                    {
                        sum += mat[p][q];
                    }
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }  
};
// tc o(N*N*K*K)
// sc o(1)
// TLE

// important article : https://www.geeksforgeeks.org/given-n-x-n-square-matrix-find-sum-sub-squares-size-k-x-k/
