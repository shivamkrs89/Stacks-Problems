/*


You are given two array A[] and B[]. Your task is to arrange elements of first array according to the order defined by second array. The first array contains integers which represent heights of persons and second array defines how many persons in front of him should stand with height greater than or equal to that person.

Input:
First line of input contains number of testcases T. For each testcase, there will be three lines, first of which will contain an integer N denoting the size of the array. Second line contains N space separated integers for array A[] denoting the height of the persons and last line of the test case contains the arrangement array B[].

Output:
Print the result array showing the new height arrangement.

Your Task:
You don't need to read input or print output. Your task is to complete the function arrange() that takes array A, array B, integer N as input parameters and returns a list of integers denoting the new arrangement of people according to their heights. 

Constraints:
1 <= T <= 50
1 <= N <= 103
1 <= A[i] <= 104
1 <= B[i] <= N

Example:
Sample Input:
2
3 
3 2 1
0 1 1
6
5 3 2 6 1 4
0 1 2 0 3 2

Sample Output:
3 1 2
5 3 2 1 6 4 

Explanation:
Testcase 1: 
The output is :                 3 1 2
Corresponding B value:  0 1 1
0 people of greater or equal height in front of person of height 3. 
1 person of greater or equal height in front of person of height 1. 
1 person of greater or equal height in front of person of height 2.

Testcase 2: 
The output is :                 5 3 2 1 6 4 
Corresponding B value:  0 1 2 3 0 2
*/

//code begins here
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function Template for C++
struct Height
{
    int h,gr_h;
};
bool comparegr(Height ha,Height hb)  //comparator function for custom sort according to descending order and when same then sort acording to value of B array
{
     if (ha.h != hb.h)
        return ha.h > hb.h;
    if(ha.h==hb.h)
    return ha.gr_h < hb.gr_h;
}

vector<int> arrange(vector<int> &A, vector<int> &B, int n)
{

int i,j;
Height h1[n];
for(i=0;i<n;i++)
{
    h1[i].h=A[i];
    h1[i].gr_h=B[i];
    
    
}
sort(h1,h1+n,comparegr);


// for(i=0;i<n;i++)
// {
//     cout<<h1[i].h<<' '<<h1[i].gr_h<<'\n';;
// }
stack<int> s1,s2;
//using stack to make them stand by inserting them one by one by value of the gr_h
for(i=0;i<n;i++)
{
  int x=h1[i].h,y=h1[i].gr_h;
  
 
  if(y==s1.size()){    //just insert as there are y larger elements already in stack
  s1.push(x);
  continue;
  }
  while(s1.size()>y)//if number of larger elements in stack is greater than given we adjust ot to position
  {
      s2.push(s1.top());
      s1.pop();
  }
   s1.push(x);
  while(!s2.empty())
  {
      s1.push(s2.top());
      s2.pop();
  }
}
vector<int> ans;
while(!s1.empty())
{
    ans.push_back(s1.top());
    s1.pop();
}
reverse(ans.begin(),ans.end());//reversing to get answer in indexing order as given
return ans;
    
}

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n,0);
        vector<int> b(n,0);

        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
            cin>>b[i];

        vector<int> result = arrange(a,b,n);

        for(int i=0;i<n;i++)
            cout<<result[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
  // } Driver Code Ends
