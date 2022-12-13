class Solution {
public:
    string rev(string str){
        string temp="";
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]=='0'){
            temp.push_back('1');
            }
            else{
                temp.push_back('0');
            }
        }
        return temp;
        
    }
    string getAns(int n){
         if(n==1){
           return "0";
       } 
       string temp=getAns(n-1);
       return temp+"1"+rev(temp);
    }
    char findKthBit(int n, int k) {
      
        string temp=getAns(n);
        // cout<<temp<<"\n";
        return temp[k-1];
    }
};