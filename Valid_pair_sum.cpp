Given an array of size N, find the number of distinct pairs {a[i], a[j]} (i != j) in the array with their sum greater than 0.

Example 1:

Input: N = 3, a[] = {3, -2, 1}
Output: 2
Explanation: {3, -2}, {3, 1} are two 
possible pairs.
Example 2:

Input: N = 4, a[] = {-1, -1, -1, 0}
Output: 0
Explanation: There are no possible pairs.
Your Task:  
You don't need to read input or print anything. Complete the function ValidPair() which takes the array a[ ] and size of array N as input parameters and returns the count of such pairs.

Expected Time Complexity: O(N * Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105 
-104  ≤ a[i] ≤ 104


class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
        long long ans = 0;
        for(int i = 0; i < n ; i++)
        {
            for(int j = i + 1 ; j < n ;j++)
            {
               if((a[i] + a[j]) > 0)
               {
                   ans++;
               }
            }
        }
        return ans;
    }   
};
// tc o(n*n)
// sc o(1)
// TLE


class Solution{
    
    public:
    long long ValidPair(int a[], int n) 
    { 
        long long ans = 0;
        sort(a, a + n);
        for(int i = 0 ;i < n - 1; i++)
        {
            if(a[i] > 0)
            {
                ans += n - i - 1;
            }
            else
            {
                int val = abs(a[i]) + 1;
                int idx = lower_bound(a,a + n, val) - a;
                if(idx == n)
                {
                    continue;
                }
                ans += n - idx;
            }
        }
        return ans;
    }   
};

//  tc o(nlogn)
//  sc o(1)
// accepted
