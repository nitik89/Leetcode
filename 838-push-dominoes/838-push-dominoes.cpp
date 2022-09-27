class Solution {
public:

    string pushDominoes(string dom) {
        //taking 2 dummy nodes
        string temp="L"+dom;
        temp+="R";
        
        int i=1,j=0;
        string ans="";
        while(i<temp.size()){
            // cout<<i<<" ";
            
            if(temp[i]=='.'){
                i++;
            }
           
            else if(temp[i]=='R'&&temp[j]=='L'){
                ans+="L";
                int k=j;
            k++;
          
            while(k<i){
                ans+=".";
                k++;
            }
            ans+="R";
                
               // string t=makeAns(i,j,temp,1);
               // ans+=t;
                j=i;
                i++;
            }
            else if(temp[i]=='L'&&temp[j]=='L'){
                
               int k=j; 
            ans+="L";
            k++;
            while(k<i){
                ans+="L";
                k++;
            }
                 // string t=makeAns(i,j,temp,2);
                //ans+=t;
                j=i;
                i++;
            }
            else if(temp[i]=='R'&&temp[j]=='R'){
                int k=j;
                ans+="R";
            k++;
            while(k<i){
                ans+="R";
                k++;
            }
                
                 // string t=makeAns(i,j,temp,3);
                //ans+=t;
                j=i;
                i++;
            }
            else if(temp[i]=='L'&&temp[j]=='R'){
                    int diff=i-j-1;
            if(diff%2==0)
            {
               
                int c=0;
                while(c<diff/2){
                    ans+="R";
                    c++;
                }
                c++;
               c=0;
                while(c<diff/2){
                    ans+="L";
                    c++;
                }
            }
            else{
                
//cout<<diff<<" ";
                int c=0;
                while(c<diff/2){
                    ans+="R";
                    c++;
                }
                c++;
                ans+=".";
                c=0;
                while(c<diff/2){
                    ans+="L";
                    c++;
                }
            }
                //string t=makeAns(i,j,temp,4);
                //ans+=t;
                j=i;
                i++;
            }
        }
        string ans1=ans.substr(1,ans.size()-2);
        return ans1;
    }
};