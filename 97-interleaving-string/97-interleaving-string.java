class Solution {
    public boolean solution(String s1,String s2,String s3,int i,int j,Boolean[][]dp){
        if(i==s1.length()&&j==s2.length()){
            return true;
        }
        
        if(dp[i][j]!=null){
            return dp[i][j];
        }
       
        
        if(s1.length()>i&&i+j<s3.length()&&s1.charAt(i)==s3.charAt(i+j)){
          boolean first=solution(s1,s2,s3,i+1,j,dp);
            if(first){
                dp[i][j]=true;
                return true;
            }
            
        }
        if(s2.length()>j&&i+j<s3.length()&&s2.charAt(j)==s3.charAt(i+j)){
           boolean second=solution(s1,s2,s3,i,j+1,dp);
            if(second){
                dp[i][j]=true;
                return true;
            }
        }
        dp[i][j]=false;
        return false;
        
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        Boolean dp[][]=new Boolean[s1.length()+1][s2.length()+1];
        if(s1.length()+s2.length()<s3.length()){
            return false;
        }
        if(s1.equals("")&&s2.equals("")&&s3.equals("")){
            return true;
        }
         if(s3.equals(s2)&&s1.equals("")){
            return true;
        }
         if(s3.equals(s1)&&s2.equals("")){
            return true;
        }
        else if(s1.length()==0||s2.length()==0||s3.length()==0){
            return false;
        }
       return solution(s1,s2,s3,0,0,dp);
    }
}