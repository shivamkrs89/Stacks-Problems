/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T test-cases follow. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the array represents the height of the bars.

Output:
For each test-case, in a separate line, the maximum rectangular area possible from the contiguous bars.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[i] <= 104

Example:
Input: 
2
7
6 2 5 4 5 1 6
4
6 3 4 2
Output:
12
9

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
//the idea of problem is simple is to see next smaller and prev small
//and calculate area in between these indexes with taking care of cases where
//no pre small and next small exists.
	while(T--)
	{
	    ll n,i;
	    cin>>n;
	    
	    ll arr[n];
	    
	    fir(i,n)
	    cin>>arr[i];
	    
	    ll rights[n];
	    ll lefts[n];
	    
	    stack<int> s;
	    s.push(n-1);
	    fir(i,n)
	    rights[i]=-1;
	    for(i=n-2;i>=0;i--)
	    {
	        if(arr[i]>arr[i+1])
	        {
	            rights[i]=i+1;
	        }
	        else
	        {
	          
	            while(!s.empty() && arr[s.top()]>=arr[i])
	            {
	                s.pop();
	            }
	            if(!s.empty() && arr[s.top()]<arr[i])
	            {
	                rights[i]=s.top();
	            }
	        }
	        s.push(i);
	    }
	  
	    while(!s.empty())
	    s.pop();
	   
	    s.push(0);
	    fir(i,n)
	    lefts[i]=-1;
	    for(i=1;i<n;i++)
	    {
	        if(arr[i]>arr[i-1])
	        {
	            lefts[i]=i-1;
	        }
	        else
	        {
	            while(!s.empty() && arr[s.top()]>=arr[i])
	            {
	                s.pop();
	            }
	            if(!s.empty() && arr[s.top()]<arr[i])
	            {
	                lefts[i]=s.top();
	            }
	        }
	        s.push(i);
	    }
	   
	    ll maxi=0;
	    for(i=0;i<n;i++)
	    {
	        if(lefts[i]!=-1 && rights[i]!=-1)
	        {
	            ll ar=(rights[i]-lefts[i]-1)*arr[i];
	            maxi=max(ar,maxi);
	        }
	        else if(lefts[i]==-1 && rights[i]==-1)
	        maxi=max(maxi,arr[i]*(n));
	        else if(lefts[i]==-1)
	        {
	            ll ar=(rights[i])*(arr[i]);
	            maxi=max(maxi,ar);
	            
	        }
	        else if(rights[i]==-1)
	        {
	            ll ar=(n-lefts[i]-1)*(arr[i]);
	            maxi=max(maxi,ar);
	        }
	       
	    }
	    
	    
	    
	    cout<<maxi<<'\n';
	}
	
	return 0;
}
