class Solution {
public:
    int mySqrt(int x) 
    {
        if(x==1 || x==2 || x==3)
        return 1;
        if(x==5)
        return 2;
       for(long long i = 1;i<=x/2;i++)
       {
        long long int multiply = i*i;
        if(multiply==x)
        return i;
        else if (multiply>x)
        return  (i-1);
       }
       return 0; 
        
    }
};
