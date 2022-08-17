class Solution {
public:
    bool isInside(int circle_x, int circle_y,
                   int rad, int x, int y)
{
    // Compare radius of circle with distance
    // of its center from given point
    if ((x - circle_x) * (x - circle_x) +
        (y - circle_y) * (y - circle_y) <= rad * rad)
        return true;
    else
        return false;
}
    bool checkOverlap(int rad, int x, int y, int x1, int y1, int x2, int y2) {
        //check points lie inside the circle
        for(int i=x1;i<=x2;i++){
            if(isInside(x,y,rad,i,y1)) return true;
        }
        for(int i=y1;i<=y2;i++){
            if(isInside(x,y,rad,x1,i)) return true;
        }
        for(int i=x1;i<=x2;i++){
            if(isInside(x,y,rad,i,y2)) return true;
        }
        for(int i=y1;i<=y2;i++){
            if(isInside(x,y,rad,x2,i)) return true;
        }
        if(x>=x1&&x<=x2&&y>=y1&&y<=y2) return true;
        return false;
    }
};