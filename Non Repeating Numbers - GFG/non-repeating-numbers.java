// { Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            String s = br.readLine();
            String[] S = s.split(" ");
            int[] v = new int[2 * n + 2];
            for(int i = 0; i < 2 * n + 2; i++)
            {
                v[i] = Integer.parseInt(S[i]);
            }
            Solution ob = new Solution();
            int[] ans = ob.singleNumber(v);
            for(int i = 0; i < ans.length; i++)
                System.out.print(ans[i] + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
   public int[] singleNumber(int[] arr)
   {
       int []nums=new int[2];
       int xor=0;
       for(int i=0;i<arr.length;i++)
       {
           xor^=arr[i];
       }
       int x=0;
       int y=0;
       int rmbm=xor & -xor;
       for(int i=0;i<arr.length;i++)
       {
           if((arr[i] & rmbm)==0)
           x^=arr[i];
           else 
           y^=arr[i];
       }
       int index=0;
       if(x>y)
       {
           nums[index++]=y;
           nums[index]=x;
       }
       else 
       {
            nums[index++]=x;
           nums[index]=y;
       }
       return nums;
   }
}