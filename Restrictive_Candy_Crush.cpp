Given a string S and an integer K, the task is to reduce the string by applying the following operation:
Choose a group of K consecutive identical characters and remove them. The operation can be performed any number of times until it is no longer possible.

Example 1:

Input:
K = 2
S = "geeksforgeeks"
Output:
gksforgks
Explanation:
Modified String after each step: 
"geegsforgeeks" -> "gksforgks"
Example 2:

Input:
K = 2
S = "geegsforgeeeks" 
Output:
sforgeks
Explanation:
Modified String after each step:
"geegsforgeeeks" -> "ggsforgeks" -> "sforgeks"
Your Task:  
You don't need to read input or print anything. Complete the function Reduced_String() which takes integer K and string S as input parameters and returns the reduced string.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)

Constraints:
1 ≤ |S| ≤ 105
1 ≤ K ≤ |S|



class Solution{
    public:
    string Reduced_String(int k,string s)
    {
        stack<pair<char,int>>st;
        int n = s.length();
        for(int i = 0 ; i < n ; i++)
        {
            if(st.empty())
            {
                st.push({s[i], 1});
            }
            else
            {
                if(!st.empty() && st.top().second == k)
                {
                    char ch = st.top().first;
                    while(!st.empty() && st.top().first == ch)
                    {
                        st.pop();
                    }
                }
                if(!st.empty() && st.top().first == s[i])
                {
                    st.push({s[i],st.top().second + 1});
                }
                else if(!st.empty() && st.top().first != s[i])
                {
                    st.push({s[i], 1});
                }
                if(st.empty())
                {
                    st.push({s[i], 1});
                }
            }
        }
        // for last numbers
        if(!st.empty() && st.top().second == k)
                {
                    char ch = st.top().first;
                    while(!st.empty() && st.top().first == ch)
                    {
                        st.pop();
                    }
                }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }


};

// tc o(n)
// sc o(n)
