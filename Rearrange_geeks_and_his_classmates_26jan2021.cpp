class Solution {
  public:
    void prank(long long a[], int n){
        long long arr[n];
        for(int i = 0 ; i < n; i++)
        {
            arr[i] = a[i];
        }
        for(long long i = 0; i < n ; i++)
        {
            if(a[i] == i)
            {
             continue;   
            }
            else
            {
                a[i] = arr[arr[i]];
            }
        }
     
    }
};
// tc o(n)
// sc o(n)


// OR

class Solution {
  public:
    void prank(long long a[], int n){
   
        for(long long i = 0; i < n ; i++)
        {
          a[i] += ((a[a[i]])%n)*n;
        }
        for(int i = 0 ; i < n ; i++)
        {
            a[i]/= n;
        }
    }
};
// tc o(n)
//sc o(1)


https://practice.geeksforgeeks.org/problems/47e5aa3f32aee9e0405f04960f37c8a562d96a2f/1/?track=30-DOC-day-1&batchId=320


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
