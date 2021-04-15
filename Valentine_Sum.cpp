// Nice problem 

class Solution{

    public:
Node* search(Node* root, int key)
    {
        if(root == NULL)
        {
            return NULL;
        }
        if(root -> data == key)
        {
            return root;
        }
        Node* tmp = search(root->left, key);
        if(tmp != NULL)
        {
            return tmp;
        }
        return search(root->right , key);
    }
    int sum_at_distK(Node* root, int target, int k)
    {
       int ans = 0;
       if(root == NULL)
       {
           return ans;
       }
       unordered_map<Node*,Node*>m;
        queue<Node*>par;
        par.push(root);
        while(!par.empty()){
            Node* front=par.front();
            par.pop();
     
            if(front==root){
                m[front]=NULL;
            }
            
            if(front->left!=NULL){
                par.push(front->left);
                m[front->left]=front;
            }
            if(front->right!=NULL){
                par.push(front->right);
                m[front->right]=front;
            }
        }
    
       queue<Node*>q;
       unordered_set<Node*>s;
       Node* tar = search(root , target);
       q.push(tar);
       s.insert(tar);
       ans += target;
      
       while(!q.empty() && k != 0)
       {
           k--;
           int sz = q.size();
           for(int i = 0 ; i < sz ; i++)
           {
               Node* front = q.front();
               q.pop();
               
               if(front -> left != NULL && s.find(front->left) == s.end())
               {
                   q.push(front->left);
                   s.insert(front->left);
                   ans += front->left->data;
               }
                if(front -> right != NULL && s.find(front->right) == s.end())
               {
                   q.push(front->right);
                   s.insert(front->right);
                   ans += front->right->data;
               }
                if(m[front] != NULL && s.find(m[front]) == s.end())
               {
                   q.push(m[front]);
                   s.insert(m[front]);
                   ans += m[front]->data;
                   
               }
           }
       }
       return ans;
    }


};

/* Note : agar vo bolte ki sum find kro of all nodes at dis k , to fir to original ques jesa hi hota ki bs vector return krne ki jgh , sum of that vector return krte , pr ye esa ni tha isme hme nikalna tha ki sum of target node + sum of all the nodes withing k distance , to hm bs agar end m jo queue m bche h unhe add krenge to vo to at dis k aagea pr na ki within dis k kyoki unhe hm queue se to pop kr hi chuke honge , islie sum = target node jo hm starting m hi kr lenge + hr baar jo jo quque m daal re h na usi time unhe sum m add kr denge...
*/

Find the sum of all nodes within a maximum distance k from target node. The target node should be included in the sum.


Example 1:

Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
target = 9, K = 1
Output:
22
Explanation:
Nodes within distance 1 from 9 are 9, 5, 7, 1  
Example 2:

Input:
                   1
                 /    \
                2      9
               /      /  \
              4      5     7
            /   \         /  \
           8     19     20    11
          /     /  \
         30   40   50
target = 40, K = 2
Output:
113
Explanation:
Nodes within distance 2 from 40 are 40, 19, 50, 4

Your Task:
You don't need to read input or print anything. Complete the function sum_at_distK() which takes the root of the tree, target, and K  as input parameter and returns the sum of all nodes within a max distance of k from the target


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N, Node Value ≤ 105
1 ≤ K ≤ 20

