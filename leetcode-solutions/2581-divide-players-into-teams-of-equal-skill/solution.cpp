class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        sort(skill.begin(),skill.end());
        int targetTeamSkill=accumulate(skill.begin(),skill.end(),0)/(skill.size()/2);
        long long totalChemistry=0;
        for(int i=0;i<skill.size()/2;i++)
        {
            int currentTeamSkill=skill[i]+skill[skill.size()-i-1];
            if(currentTeamSkill != targetTeamSkill)
            return -1;
            totalChemistry += skill[i]*skill[skill.size()-i-1];
        }
        return totalChemistry;
    }
};
