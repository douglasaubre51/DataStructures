/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
int lengthOfLongestSubstring(char* s) 
{
    int c=0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        for(int j=0;s[j]!='\0';j++)
        {
            if(s[i]!=s[j])
            {
                c=c+1;
            }
        }
    }
    

}
// @lc code=end

