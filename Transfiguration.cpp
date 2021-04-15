                                       
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
        map<int, int>m1,m2;
        int n1 = A.length(), n2 = B.length();
        if(n1 != n2)  // if length of two string is not equal which mean we can't convert a -> b
        {
            return -1;
        }
        for(int i = 0 ; i < n1 ; i++)
        {
            m1[A[i]]++;
        }
        for(int i = 0 ; i < n2 ; i++)
        {
            m2[B[i]]++;
        }
        if(m1 != m2)  // if both string do not contain same characters that means we can't convert a->b
        {
            return -1;
        }
        // noew, we have to find minimum number of chanegs we can do to convert  a -> b
        int ans = 0;
        for(int i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0;)
        {
            if(A[i] == B[j])
            {
                i--;
                j--;
            }
            else
            {
                while(i >= 0 && A[i] != B[j])
                {
                    i--;
                    ans++;
                }
            }
        }
        return ans;
    }
};
