class Solution{
    public:
    int candies(int m, int n) 
    { 
    int  Frobenius  = (m * n) - m - n; // largest number which we cannot visit using the combination of any two numbers
    
    queue<int> q; 
    unordered_set<int>s;
    q.push(Frobenius);  
    s.insert(Frobenius);
    int ans = 0;  
    while (q.size() > 0)  
    {  
  
        int front = q.front();  
        q.pop(); 
  
        ans++;  
  
        if (front - m > 0 && s.find(front - m) == s.end()) 
        {
             q.push(front - m); 
             s.insert(front - m);
        }

        if (front - n > 0 && s.find(front - n) == s.end())  
        {
            q.push(front - n);  
            s.insert(front - n);
        }
    }  
    return ans;  

    } 
};

https://www.geeksforgeeks.org/find-the-count-of-unvisited-indices-in-an-infinite-array/

// tc o(n)
// sc o(n)
// 1 ≤ M, N ≤ 500

/*
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


*/
