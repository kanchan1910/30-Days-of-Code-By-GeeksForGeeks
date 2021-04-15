class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<int>ans(n, -1);
        for(int i = 0 ; i < n ; i++)
        {
            if(gallery[i] >= 0)
            {
                int l = max(0 , i - gallery[i]);
                int r = min(n - 1, i + gallery[i]);
                for(int j = l ; j <= r; j++)
                {
                    ans[j] = max(ans[j], r);
                }
            }
        }
        int final = 0;
        for(int i = 0 ; i < n ; )
        {
            if(ans[i] == -1)
            {
                return -1;
            }
            final++;
            i = ans[i] + 1;
        }
        return final;
    }
};
// asked in microsoft

// tc o(n*n)
// sc o(n)

A gallery with plants is divided into n parts, numbered : 0,1,2,3...n-1. There are provisions for attaching water sprinklers at every partition. A sprinkler with range x at partition i can water all partitions from i-x to i+x.
Given an array gallery[ ] consisting of n integers, where gallery[i] is the range of sprinkler at partition i (power==-1 indicates no sprinkler attached), return the minimum number of sprinklers that need to be turned on to water the complete gallery.
If there is no possible way to water the full length using the given sprinklers, print -1.

Example 1:

Input:
n = 6
gallery[ ] = {-1, 2, 2, -1, 0, 0}
Output:
2
Explanation: Sprinklers at index 2 and 5
can water thefull gallery, span of
sprinkler at index 2 = [0,4] and span
â€‹of sprinkler at index 5 = [5,5].
Example 2:

Input:
n = 9
gallery[ ] = {2, 3, 4, -1, 2, 0, 0, -1, 0}
Output:
-1
Explanation: No sprinkler can throw water
at index 7. Hence all plants cannot be
watered.
Example 3:

Input:
n = 9
gallery[ ] = {2, 3, 4, -1, 0, 0, 0, 0, 0}
Output:
3
Explanation: Sprinkler at indexes 2, 7 and
8 together can water all plants.
Your task:
Your task is to complete the function min_sprinklers() which takes the array gallery[ ] and the integer n as input parameters and returns the value to be printed.

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ n ≤ 105
gallery[i] ≤ 50
