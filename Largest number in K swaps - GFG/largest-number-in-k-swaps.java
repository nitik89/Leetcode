// { Driver Code Starts
import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])throws IOException
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int k = sc.nextInt();
                    String str = sc.next();
                    Solution obj = new Solution();
                    System.out.println(obj.findMaximumNum(str, k));
                }
        }
}// } Driver Code Ends




class Solution
{
    //Function to find the largest number after k swaps.
    	static String max;
	public static void findMaximum(String str, int k,int idx) {
		
		if(idx==str.length()||k==0){
		   return;
		}
		int cd=str.charAt(idx) - '0';
		int ld=cd;
		for(int j=idx+1;j<str.length();j++){
		    if(str.charAt(j) - '0' >ld){
		        ld=str.charAt(j) - '0';
		    }
		}
		if(ld!=cd){
		    for(int j=idx+1;j<str.length();j++){
		        if((str.charAt(j) - '0')==ld){
		            String ss=swap(str,idx,j);
		            
		            if (ss.compareTo(max)>0 ) {
		                max = ss;
		                
		            }
		            findMaximum(ss,k-1,idx+1);//swap done
		        }
		    }
		}
		else{
		    findMaximum(str,k,idx+1);//no swap
		}
		
	}
	public static String swap(String str,int i,int j){
	    char ith=str.charAt(i);
	    char jth=str.charAt(j);
	    String left=str.substring(0,i);
	    String middle=str.substring(i+1,j);
	    String right=str.substring(j+1);
	    return left+jth+middle+ith+right;
	}
    public static String findMaximumNum(String str, int k)
        {
            	 max = str;
		findMaximum(str, k,0);
		return max;
        }
}