class Solution{
    public:
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
         vector<int>ans;
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; 
         for(int i = 0 ; i < n ; i++)
         {
             pq.push({abs(arr[i] - x), arr[i]});
         }
         while(!pq.empty() && k != 0)
         {
             k--;
             ans.push_back(pq.top().second);
             pq.pop();
         }
         sort(ans.begin(), ans.end());
         return ans;
    }  
};
// tc o(nlogn)
// sc o(n)
