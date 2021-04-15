class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
     vector<int>ans;
     int dir = 0;
     int top = 0;	
     int down = n - 1;
     int left = 0;
     int right = m - 1;
     while(top <= down && left <= right)
     {
         if(dir == 0)
         {
             for(int j = left ; j <= right; j++)
             {
                 ans.push_back(a[top][j]);
             }
             top++;
         }
         else if(dir == 1)
         {
             for(int i = top; i <=down; i++)
             {
                 ans.push_back(a[i][right]);
             }
             right--;
         }
         else if(dir == 2)
         {
             for(int j = right; j >= left; j--)
             {
                 ans.push_back(a[down][j]);
             }
             down--;
         }
         else if(dir == 3)
         {
             for(int i = down; i >=top; i--)
             {
                 ans.push_back(a[i][left]);
             }
             left++;
         }
         dir = (dir + 1) % 4;
     }
     return ans[k - 1];
    }

};

/*Given a matrix of size N x M. You have to find the Kth element which will obtain while traversing the matrix spirally starting from the top-left corner of the matrix.

Example 1:

Input: 
N = 3, M = 3, K = 4
A[] = {{1, 2, 3}, 
       {4, 5, 6}, 
       {7, 8, 9}}
Output: 
6
Explanation: Spiral traversal of matrix: 
{1, 2, 3, 6, 9, 8, 7, 4, 5}. Fourth element
is 6.
Example 2:

Input: 
N = 2, M = 2, K = 2 
A[] = {{1, 2},
       {3, 4}} 
Output: 
2
Explanation: Spiral traversal of matrix: 
{1, 2, 4, 3}. Second element is 2.
*/

// tc o(n*m)
// sc o(n*m)
