class Solution {
public:
    int racecar(int target) {
        queue<vector<int>>q;
        //moves pos speed
        q.push({0,0,1});
        
        while(!q.empty()){
          auto move = q.front()[0];
          auto pos = q.front()[1];
          auto speed = q.front()[2];
            
            // string str=q.front().second;
            q.pop();
          if(pos==target){
              // cout<<str<<" ";
              return move;
          }
           
            //accelerate
            // cout<<speed<<" "<<pos<<"\n";
            // if(speed>target)continue;
             // cout<<pos<<" "<<speed<<"\n";
            
            if(speed+pos>=0&&speed<=target){
            q.push({move+1,pos+speed,speed*2});
            }
            //reverse
            if(speed>0&&speed+pos>target||speed<0&&speed+pos<target){
                int t=speed;
                if(t<0){
                    q.push({move+1,pos,1});
                }
                else if(t>0){
                    q.push({move+1,pos,-1});
                }
            }
            
                
            
        }
        
        return -1;
    }
};