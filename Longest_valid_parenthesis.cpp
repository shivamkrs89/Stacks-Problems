/*
Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

Input:
First line contains number of test cases T.  Each test case have one line string S of character '(' and ')' of length  N.

Constraints:
1 <= T <= 500
1 <= N <= 105

Example:
Input:
2
((()
)()())

Output:
2
4

Explanation:
Testcase 1: Longest valid balanced parantheses is () and its length is 2.
*/

//code goes here
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define loop(i,a,n) for(i=a;i<n;i++)
#define fir(i,n) loop(i,0,n)
#define pb push_back()

//Code 2 Conquer
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
	    string s;
	    cin>>s;
	    long int n=s.length();
	    long int i=0;
	    stack<int> s1;
	    s1.push(-1); //for base as if Like str="()" then len=(1-(-1)) will performed below
	    long int maxi=0,len=0;
	    for(i=0;i<n;i++)
	    {
	        if(s[i]=='('){
	        s1.push(i);
	        }
	        else
	        {
	            s1.pop();  //first we pop most recent
	            if(!s1.empty())
	            {
	            
	             maxi=max(maxi,i-s1.top());//we check for length if '((((' then len=1
	            }
	            else
	            s1.push(i); //if there is no '(' then we push ')' index for base
	        }                //whenever '(' encounters it gives '(' index which increases the length
	    }   
	     
	    
	    
	    
	    cout<<maxi<<'\n';
	}
	
	return 0;
}
