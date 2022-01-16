
Given a list of distinct integers pushes, and another list of integers pops, return whether this is a valid sequence of stack push and pop actions.

Constraints

n ≤ 100,000 where n is the length of pushes
m ≤ 100,000 where m is the length of pops
Example 1
Input
pushes = [0, 1, 4, 6, 8]
pops = [1, 0, 8, 6, 4]
Output
true
Explanation
We can first push [0, 1], then pop both off. Then push [4, 6, 8] and then pop them all off.

Example 2
Input
pushes = [1, 2, 3, 4]
pops = [4, 1, 2, 3]
Output
false
Explanation
This is not valid since 3 was pushed after 1 but is popped earlier.
  
  //code
  
bool solve(vector<int>& pushes, vector<int>& pops) {
    int n=pops.size();
    stack<int> pop1;
    int i,j=0;
    for(i=0;i<n;i++)
    {
        pop1.push(pushes[i]);

        while(!pop1.empty() && j<n && pops[j]==pop1.top())
        {
            j++;
            pop1.pop();
        }
    }

    if(j==n)
    return 1;

    
     return 0;
}
