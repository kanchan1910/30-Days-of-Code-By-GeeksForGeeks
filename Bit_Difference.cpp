Given an integer array of size  N . You have to find sum of bit differences in all pairs that can be formed from array elements. Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y.
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).

Example 1:

Input: N = 2, arr[] = {1, 2}
Output: 4
Explanation: All possible pairs are [(1,1) (1,2) 
(2,1) (2,2)] their respective Bit differences 
are 0 ,  2 , 2 , 0

Example 2:

Input: N = 5, arr[] = {3, 5, 2, 5, 2}
Output: 36
Your Task:  
You dont need to read input or print anything. Complete the function sumBitDiff() which takes the array a[] and size of array N as input parameters and returns the answer

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ arr[i] ≤ 108



class Solution{
    public:
    long long sumBitDiff(int arr[], int n) 
    { 
       long long ans = 0;
       for(int i = 0 ; i < n ; i++)
       {
           for(int j = i + 1; j < n ; j++)
           {
               if(arr[i] != arr[j])
               {
                    int diff = __builtin_popcount(arr[i] ^ arr[j]);
                    ans += 2 * diff;
               }
           }
       }
       return ans;
    } 
};

// tle 
// tc o(n*n)
// sc o(1)


class Solution{
    public:
    long long sumBitDiff(int arr[], int n) 
    { 
       long long ans = 0;
     
       for(int i = 0 ; i < 32; i++)  
       {
           long long count = 0;
           
           for(int j = 0 ; j < n ; j++)
           {
               if((arr[j] & (1 << (i - 1))) != 0) // for checking if the ith bot is set or not
               {
                   count++;
               }
           }
           ans += (count * (n - count) * 2);
           
       }
       return ans;
    } 
};

// accepted
// tc o(n)
// sc o(1)
