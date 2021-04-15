class Solution{

    public:
    int repeatedStringMatch(string A, string B) 
    {
        int n1 = A.length(),n2 = B.length();
        if(A == B || A.find(B) != string::npos)
        {
            return 1;
        }
        string tmp = A;
        int ans = 1;
        while(tmp.length() <= n1 + n2)
        {
        
        if(tmp.find(B) != string::npos)
        {
            return ans;
        }
        ans++;
        tmp += A;
        }
        if(tmp.find(B) == string::npos)
        {
            return -1;
        }
        return ans;
    }
  
};
// tc o(N)
// sc o(1)
