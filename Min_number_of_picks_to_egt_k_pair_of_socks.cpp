class Solution{

	public:
	int find_min(int a[], int n, int k) {
	    int pairs = 0;
	    for(int i = 0 ; i < n ; i++)
	    {
	        pairs += a[i]/2;
	    }
	    if(k > pairs)
	    {
	        return -1;
	    }
	    int max_pair_picked_without_exhausting_any_color_type = 0;
	    for(int i = 0 ; i < n ;i++)
	    {
	        if(a[i] % 2 == 0)
	        {
	            max_pair_picked_without_exhausting_any_color_type += (a[i] - 2)/2;
	        }
	        else
	        {
	            max_pair_picked_without_exhausting_any_color_type += (a[i] - 1)/2;
	        }
	    }
	    if(max_pair_picked_without_exhausting_any_color_type < k)
	    {
	        return max_pair_picked_without_exhausting_any_color_type * 2 + n + (k - max_pair_picked_without_exhausting_any_color_type);
	    }
	    else if(max_pair_picked_without_exhausting_any_color_type >= k)
	    {
	        // will not just return max_pair_picked_without_exhausting_any_color_type as , if k = 3 and max_pair_picked_without_exhausting_any_color_type = 5
	        //then extra 4 socks are not giving optimal answer as we don't need them
	        //so
	        return 2 * (k - 1) + n + 1;
	        
	    }
    }

};

A drawer contains socks of n different colours. The number of socks available of ith colour is given by a[i] where a is an array of n elements. Tony wants to take k pairs of socks out of the drawer. However, he cannot see the colour of the sock that he is picking. You have to tell what is the minimum number of socks Tony has to pick in one attempt from the drawer such that he can be absolutely sure, without seeing their colours, that he will have at least k matching pairs.

Example 1:

Input: N = 4, a[] = {3, 4, 5, 3}, K = 6
Output: 15
Explanation: The worst case scenario, after 
14 picks will be 3,3,3,3 or 3,1,5,3 where 
each number represents picks of socks of 
one colour. Hence, 15th pick will get the 
5th pair for sure.

Example 2:

Input: N = 2, a[] = {4, 6}, K = 3
Output: 7
Explanation: The Worst case scenario after 6 
picks can be 3,3 or 1,5 or 5,1 of each 
coloured socks. Hence 7th pick will ensure 
3rd pair. 
Your Task:  
You don't need to read input or print anything. Complete the function find_min() which takes the array a[], size of array N, and value K as input parameters and returns the minimum number of socks Tony has to pick. If it is not possible to pick then return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105 
1 ≤ a[i] ≤ 106


// puzzle type 	ques, was asked in amazon
