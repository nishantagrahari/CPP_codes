class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        
        int l=s.length();//lenght of string
        if(l==0){return 0;}
        
        
        int initial=0;//using sliding window methodology
        int end=0;
        
        m[s[0]]=end; //storing the location of initial string in map
        int curr_len=INT_MIN;
        int max_len=0;
        
       for(end=1;end<l;end++)
       {
           //check if the string is already present in map or not
           if(m.find(s[end])==m.end()){
               m[s[end]]=end;
           }
           else{
               //if string is already present in map and it is coming before the current substring
               if (m[s[end]]>=initial){
                   curr_len=end-initial;
                   max_len=max(max_len,curr_len);
                   initial=m[s[end]]+1;                   
               }               
            m[s[end]]=end;
         }       
       }
          max_len=max(max_len,end-initial);  //case when all the letters are not repeated       
           
                  
       return max_len;
    }
};