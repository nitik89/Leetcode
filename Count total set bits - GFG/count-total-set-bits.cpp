// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if(n<=1){
            return n;
        }
        int power=floor(log2(n));
        int val=pow(2,power);
         
        int cnt=1;
        int myval=2;
    
        while(myval<val){
            cnt=myval+cnt*2;
            myval*=2;
        }
        // return 1;
         return cnt+countSetBits(n-val)+(n-val+1);
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends