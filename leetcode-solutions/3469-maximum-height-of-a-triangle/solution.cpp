class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int count  = 0;
        int i = 1;
        int originalRed = red;
        int originalBlue = blue;

        red = originalRed;
        blue = originalBlue;
        while(true)
        {
            if(i&1)
            {
                if(blue>=i)
                {
                    blue = blue-i;
                    i++;
                }
                else
                break;
                
            }
            else
            {
                if(red>=i)
                {
                    red = red - i;
                    i++;
                }
                else
                break;
            }
            
            count++;
        }
        int count2 = 0;
        i =1;
        red = originalRed;
        blue = originalBlue;
        while(true)
        {
            if(i&1)
            {
                if(red>=i)
                {
                    red = red - i;
                    i++;
                }
                else
                break;
                
            }
            else
            {
                if(blue>=i)
                {
                    blue = blue - i;
                    i++;
                }
                else
                break;
            }
            
            count2++;
        }
        return max(count,count2);
    }
};
