class Solution {
public:
    bool isPalindrome(int x) 
    {
        long long int sum=0;
       long long int temp=x;
        if(x<0)
        return false;
        else
        {
       
        while(x!=0&x>0)
        {
            
           long long int digit=x%10;
            
            sum= sum*10 + digit;
            x=x/10;
            
        }
        }
        return (sum==temp);
    }    
};
