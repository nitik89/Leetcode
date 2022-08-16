class Solution {
public:
    int dp[9][9][(1<<8)+1][(1<<8)+1];
    bool isValid(int j,int mask,int pmask,int n){
        // if(((mask<<1) & (1<<j)) or ((mask>>1) & (1<<j))) return false;
        // if(((pmask<<1) & (1<<j)) or ((pmask>>1) & (1<<j))) return false;
        // return true;
        if((j-1>=0&&(pmask&(1<<(j-1)))) or (j+1<n&&(pmask&(1<<(j+1)))) ) return false;
        if((j-1>=0&&(mask&(1<<(j-1)))) or (j+1<n&&(mask&(1<<(j+1)))) ) return false;
        return true;
    }
    int getAns(vector<vector<char>>&seats,int row,int col,int mask,int pmask){
        // cout<<row<<" "<<col<<"\n";
        int newrow=row,newcol=col;
        if(row>=seats.size()&&col==0){
            return 0;
        }
        if(dp[row][col][mask][pmask]!=-1){
            return dp[row][col][mask][pmask];
        }
        int t=mask,t1=pmask;
       if(col+1<seats[0].size()){
           newcol++;
       }
       else if(col+1==seats[0].size()){
           newcol=0;
           newrow++;
           pmask=mask;
           mask=0;
           
       }
        int cnt=INT_MIN;
        if(seats[row][col]=='.'){
        if(isValid(col,t,t1,seats[0].size())){
             
        if(col+1==seats[0].size()){
            cnt=max(cnt,1+getAns(seats,newrow,newcol,mask,pmask|(1<<col)));
        }
            else{
                cnt=max(cnt,1+getAns(seats,newrow,newcol,mask|(1<<col),pmask));
            }
            
        }
        }
       cnt=max(cnt,getAns(seats,newrow,newcol,mask,pmask));
        return dp[row][col][mask][pmask]=cnt;
       
    }
    int maxStudents(vector<vector<char>>& seats) {
        memset(dp,-1,sizeof dp);
     return getAns(seats,0,0,0,0);
        
    }
};