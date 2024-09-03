
class Solution {
public:
    
    int digit_sum_function(int digit)
    {
        int digit_sum=0;
        int remainder;
        while(digit!=0)
        {
            remainder=digit % 10;
            digit_sum +=remainder;
            digit=digit/10;
        }
        return (digit_sum);
        
    }
    bool check_even(int digit_sum)
    {        
        return (digit_sum%2==0);
    }
    int countEven(int num) 
    {
        int count=0;
        for(int i=1;i<=num;i++)
        {
            int digit_sum=digit_sum_function(i);
            if(check_even(digit_sum))
            {
                count++;
            }
        }  
        return count;
    }
    
};
