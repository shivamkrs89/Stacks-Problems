Given a string s, repeatedly delete the earliest consecutive duplicate characters.

Constraints

n ≤ 100,000 where n is the length of s.
Example 1
Input
s = "abbbaac"
Output
"c"
Explanation
"bbb" are the earliest consecutive duplicate characters which gets deleted. So we have "aaac".
"aaa" then gets deleted to end up with "c".
  
  //code
  string solve(string s) {
    stack<char> st1;
    int n=s.size();

    int i,j;
    i=0;
    while(i<n)
    {
        cout<<i<<'\n';
      
        st1.push(s[i]);
        int flag=0;
       while(i<n-1 && s[i]==s[i+1])
       {
           st1.push(s[i]);
           i++;
       }

       
     
    
       while(!st1.empty() && st1.top()==s[i])
       {
           flag+=1;
           st1.pop();
       }
       if(flag==1) //case to handleonly single character i.e no consecutive
       st1.push(s[i]);
       i++;
    }
    string ans="";
    while(!st1.empty())//recreate string from stack
    {
       ans+=(st1.top());
       st1.pop();
    }
   
reverse(ans.begin(),ans.end()); //reverse the string to get required string
    return ans;
}
  
