class Solution{
	public:
    	long long findNth(long long N)
    {
      long long ans = 0;
      int i = 0;
      while(N != 0) {
           ans += (pow(10,i)*(N%9));
           N /= 9;
           i++;
      }
      return ans;
    }
};
// logic ???
// tc o(logn)
// sc o(1)
