class Solution {
public:
    int maxArea(vector<int>& height) {
        int area;
        int n = height.size();
        int maxArea = INT_MIN;
        int i = 0;
        int j = n-1;
        while(i<j)
        {
            area = min(height[i],height[j]) * (j-i);
            maxArea = max(maxArea,area);
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxArea;
    }
};
