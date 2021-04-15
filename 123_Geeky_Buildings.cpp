// nice problem 


class Solution{
public:
	bool recreationalSpot(int arr[], int n)
	{
	    vector<int>tmp(n);
	    tmp[0] = arr[0];  // for first number
	    for(int i = 1; i < n; i++)
	    {
	        tmp[i] = min(arr[i], tmp[i - 1]);
	    }
	    stack<int>s;
	    for(int i = n - 1; i >= 0 ; i--)
	    {
	        if(arr[i] > tmp[i])  // first and middle number fixed
	        {
	            // we have to choose the last number properly
	            while(!s.empty() && s.top() <= tmp[i])
	            {
	                s.pop();
	            }
	            if(!s.empty() && s.top() < arr[i])
	            {
	                return true;
	            }
	        }
	        s.push(arr[i]);
	    }
	    return false;
	}
};
// tc o(N)
// sc o(N)


// My this solution fails at
5
3 2 5 1 4
// as it is only loopng for just next smaller number of the right , so for 5 , it chooses 1 and so return false , but here is should use 4 instead of 5
class Solution{
public:
	bool recreationalSpot(int arr[], int n)
	{
	    stack<int>s;
	    vector<int>next;      // for last number
	    for(int i = n - 1 ; i >= 0 ; i--)
	    {
	        if(s.empty())
	        {
	            next.push_back(-1);
	        }
	        else if(!s.empty() && s.top() < arr[i])
	        {
	            next.push_back(s.top());
	        }
	        else if(!s.empty() && s.top() >= arr[i])
	        {
	            while(!s.empty() && s.top() >= arr[i])
	            {
	                s.pop();
	            }
	            if(s.empty())
	            {
	                next.push_back(-1);
	            }
	            else
	            {
	                next.push_back(s.top());
	            }
	        }
	        s.push(arr[i]);
	    }
	    reverse(next.begin(), next.end());
	    vector<int>tmp(n);
	    tmp[0] = arr[0];    // for first number
	    for(int i = 1; i < n ;i++)
	    {
	        tmp[i] = min(tmp[i - 1], arr[i]);
	    }
	    for(int i = 1 ; i < n - 1 ; i++)
	    {                 // for middle number
	        if(arr[i] > tmp[i] && next[i] > tmp[i])
	        {
	            return true;
	        }
	    }
	    return false;
	}
};
// tc o(n)
// sc o(n)


There are N buildings in Linear Land. They appear in a linear line one after the other and their heights are given in the array arr[]. Geek wants to select three buildings in Linear Land and remodel them as recreational spots. The third of the selected building must be taller than the first and shorter than the second.
Can geek build the three-building recreational zone? 


Example 1:

Input:
N = 6
arr[] = {4, 7, 11, 5, 13, 2}
Output:
True
Explanation:
[4, 7, 5] fits the condition. 
Example 2:

Input:
N = 4
arr[] = {11, 11, 12, 9}
Output:
False
Explanation:
No 3 buildings fit the given condition. 

Your Task:
You don't need to read input or print anything. Complete the function recreationalSpot() which takes the array arr[] and its size N as input parameters and returns a boolean value based on whether his building selection was successful or not.
Note: The generated output will be "True" or "False".


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 104
1 ≤ arr[i] ≤ 105
