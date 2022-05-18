// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        
        int x=ceil((double)N/(double)(K+1));
        
        sort(candies,candies+N);
        int sum=0;
        
        for(int i=0;i<x;i++){
            // cout<<candies[i]<<" ";
            sum+=candies[i];
        }
        int sum2=0;
        for(int i=N-1;i>=N-x;i--){
            sum2+=candies[i];
        }
        return {sum,sum2};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends