class Solution {
public:
    string alphabetBoardPath(string target) {
        map<char,pair<int,int>>mp;
        vector<string>board= {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z****"};
        for(int i=0;i<6;i++){
            for(int j=0;j<5;j++){
                mp[board[i][j]]={i,j};
            }
        }
        int x=0,y=0;
        string ans="";
        for(int i=0;i<target.size();i++){
            char w=target[i];
            int dx=mp[w].first;
            int dy=mp[w].second;
            if(w=='z'){
               int dxx=dx-x;
                int dyy=dy-y;
                 if(dyy>0){
                    while(dyy>0){
                        ans+='R';
                        dyy--;
                    }
                }
                else if(dyy<0){
                      while(dyy<0){
                        ans+='L';
                        dyy++;
                    }
                }
                if(dxx>0){
                    while(dxx>0){
                        ans+='D';
                        dxx--;
                    }
                }
                else if(dxx<0){
                      while(dxx<0){
                        ans+='U';
                        dxx++;
                    }
                }
               
                ans+='!'; 
            }
            else{
                int dxx=dx-x;
                int dyy=dy-y;
                if(dxx>0){
                    while(dxx>0){
                        ans+='D';
                        dxx--;
                    }
                }
                else if(dxx<0){
                      while(dxx<0){
                        ans+='U';
                        dxx++;
                    }
                }
                if(dyy>0){
                    while(dyy>0){
                        ans+='R';
                        dyy--;
                    }
                }
                else if(dyy<0){
                      while(dyy<0){
                        ans+='L';
                        dyy++;
                    }
                }
                ans+='!';
            }
            x=dx;
            y=dy;
        }
        return ans;
    }
};