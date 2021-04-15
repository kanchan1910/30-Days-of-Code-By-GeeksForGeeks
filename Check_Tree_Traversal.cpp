Given Preorder, Inorder and Postorder traversals of some tree of size N. The task is to check if they are all of the same tree or not.

Example 1:

Input:
N = 5
preorder[] = {1, 2, 4, 5, 3}
inorder[] = {4, 2, 5, 1, 3}
postorder[] = {4, 5, 2, 3, 1}
Output: Yes
Explanation: 
All of the above three traversals 
are of the same tree.
           1
         /   \
        2     3
      /   \
     4     5
Example 2:

Input:
N = 5
preorder[] = {1, 5, 4, 2, 3}
inorder[] = {4, 2, 5, 1, 3}
postorder[] = {4, 1, 2, 3, 5}
Output: No
Explanation: The three traversals can 
not be of the same tree.

Your Task:
You don't need to read input or print anything. Complete the function checktree() which takes the array preorder[ ], inorder[ ], postorder[ ] and integer N as input parameters and returns true if the three traversals are of the same tree or not. 

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 103



class Solution{
    public:
    int search(int arr[],int x,int n) // searching root's index in inorder traversal
    {
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i] == x)
            {
                return i;
            }
        }
        return -1;
    }
    void fun(int preorder[],int inorder[],int n,vector<int>&post,bool &f) // calculating postorder traversal of a tree
    {
       
        int root = search(inorder,preorder[0], n);
        if(root == -1)
        {
            f = false;
            return;
        }
        if(root != 0) // left
        {
            fun(preorder + 1,inorder,root,post,f);
        }
        if(root != n - 1)  // right
        {  
            fun(preorder + root + 1, inorder + root + 1, n - root - 1,post,f);
        }
        post.push_back(preorder[0]);
    }
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
        vector<int>post;
        bool f = true;
        fun(preorder,inorder,N,post,f);
        if(f == false)
        {
            return false;
        }
        for(int i = 0 ; i < N ; i++)
        {
            if(postorder[i] != post[i])
            {
                return false;
            }
        }
        return true;
    } 

};

// tc o (n*n) , n for traversing each node and n for searching
// sc o(n)
