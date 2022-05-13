// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
         vector<int>fact={1,2,6,24,120,720,5040,40320,362880,3628800};
        int sets=fact[n-1];
        sets=sets/n;
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        string ans;
        k--;
        while(n>0){
            ans.push_back(nums[k/sets] + '0');
            nums.erase(nums.begin()+k/sets);
            k=k%sets;
            n--;
            if(n<=0){
                break;
            }
            sets=sets/n;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends