 //Given a string s, find the length of the longest substring without repeating characters.


 int lengthOfLongestSubstring(string s) {
        int max = 0;
        int l = 0 , r = 0;
        unordered_map<char, int> mp;
        int cur = 0;
        while(r < s.length())
        {
    
           mp[s[r]]++  ; 
           cur++;
            
           if(mp[s[r]] > 1)
           {
               while(mp[s[r]] > 1)
               {
                   mp[s[l]]--;
                   cur--;
                   l++;
               }
           }
            
           max = std::max(max, cur);
               
           r++;
        }
        
        return max;
    }