
class Solution
{   
public:
    long long smallestpositive(vector<long long> array, int n)
    { 
        sort(array.begin(),array.end());
        long long ans = 1;
        if(array[0] != 1)
        {
            return ans;
        }
        for(int i = 1; i < n ; i++)
        {
            if(array[i] > ans + 1)
            {
                break;
            }
            else
            {
                ans += array[i];
            }
        }
        return ans + 1;
    } 
};
// tc o(nlogn)
// sc o(1)

//ques
/*
Given an array of size N, find the smallest positive integer value that cannot be represented as sum of some elements from the array.


Example 1:

Input: 
N = 6
array[] = {1, 10, 3, 11, 6, 15}
Output: 
2
Explanation:
2 is the smallest integer value that cannot 
be represented as sum of elements from the array.

Example 2:

Input: 
N = 3
array[] = {1, 1, 1}
Output: 
4
Explanation: 
1 is present in the array. 
2 can be created by combining two 1s.
3 can be created by combining three 1s.
4 is the smallest integer value that cannot be 
represented as sum of elements from the array.
*/
//aksed in amazon , no try to do it in O(n)
