
// nice problem using bfs

class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
        vector<vector<int>>ans(M, vector<int>(N , -1));
        vector<vector<bool>>vis(M, vector<bool>(N , false));
        queue<pair<int,pair<int,int>>> q;
        for(int i = 0 ; i < M ; i++)
        {
            for(int j = 0 ; j < N  ; j++)
            {
                if(matrix[i][j] == 'B')
                {
                    q.push({0,{i , j}});
                    vis[i][j] = true;
                    ans[i][j] = 0;
                }
            }
        }
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            int i = x.second.first;
            int j = x.second.second;
            // four directions
            if(i - 1 >= 0 && i - 1 <= M - 1 && j >= 0 && j <= N - 1 && !vis[i - 1][j] && matrix[i - 1][j] != 'W')
            {
                vis[i - 1][j] = true;
                q.push({x.first + 1,{i - 1, j}});
                ans[i -1][j] = x.first + 1;
            }
            if(i + 1 >= 0 && i + 1 <= M - 1 && j >= 0 && j <= N - 1  && !vis[i + 1][j] && matrix[i + 1][j] != 'W')
            {
                vis[i + 1][j] = true;
                q.push({x.first + 1,{i + 1, j}});
                ans[i + 1][j] = x.first + 1;
            }
            if(i >= 0 && i <= M - 1 && j - 1 >= 0 && j - 1<= N - 1 && !vis[i][j - 1] && matrix[i][j - 1] != 'W')
            {
                vis[i][j - 1] = true;
                q.push({x.first + 1,{i, j - 1}});
                ans[i][j - 1] = x.first + 1;
            }
            if(i >= 0 && i  <= M - 1 && j + 1 >= 0 && j + 1 <= N - 1  && !vis[i][j + 1] && matrix[i][j + 1] != 'W')
            {
                vis[i][j + 1] = true;
                q.push({x.first + 1,{i, j + 1}});
                ans[i][j + 1] = x.first + 1;
            }
        }
        return ans;
    } 
};




Spiderman is stuck in a difficult situation. His arch-enemy the Green Goblin has planted several of his infamous Pumpkin Bombs in various locations in a building. Help Spiderman activate his Spidey Sense and identify the impact zones. 
He has a blueprint of the building which is a M x N matrix that is filled with the characters ‘O’, ‘B’, and ‘W’ where: 
‘O’ represents an open space.
‘B’ represents a bomb.
‘W’ represents a wall.
You have to replace all of the O’s (open spaces) in the matrix with their shortest distance from a bomb without being able to go through any walls. Also, replace the bombs with 0 and walls with -1 in the resultant matrix. If no path exists between a bomb and an open space replace the corresponding 'O' with -1.

Example 1:

Input: N = 3, M = 3
A[] = {{O, O, O}, 
       {W, B, B}, 
       {W, O, O}}
Output: {{2, 1, 1}, 
         {-1, 0, 0},  
         {-1, 1, 1}}
Explanation: The walls at (1,0) and (2,0) 
are replaced by -1. The bombs at (1,1) and 
(1,2) are replaced by 0. The impact zone 
for the bomb at (1,1) includes open spaces 
at index (0,0), (0,1) and (2,1) with distance 
from bomb calculated as 2,1,1 respectively.
The impact zone for the bomb at (1,2) 
includes open spaces at index (0,3) and (2,2) 
with distance from bomb calculated as 1,1 
respectively.

Example 2:

IInput: N = 2, M = 2
A[] = {{O, O},
       {O, O}} 
Output: {{-1, -1}
         {-1, -1}
Your Task:  
You don't need to read input or print anything. Complete the function findDistance() which takes the matrix A[], M, and N as input parameters and the resultant matrix

Expected Time Complexity: O(M*N)
Expected Auxiliary Space: O(M*N)


Constraints:
1 ≤ N*M ≤ 106
