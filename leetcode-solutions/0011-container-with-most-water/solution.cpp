class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int maximum=0;
        int area=0;
        int i=1;
        int n=height.size();
        int left=0;
        int right=n-1;
        while(left<right)
        {
            area=(min(height[left],height[right])*(n-i));
            maximum=max(area,maximum);
            if(height[left]<height[right])
            {
                left++;
                i++;
            }
            else
            {
                right--;
                i++;
            }
        }
        return maximum;

        
    }
};
