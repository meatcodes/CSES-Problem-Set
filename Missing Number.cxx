Question
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
You are given all numbers between 1,2,…,n except one. Your task is to find the missing number.

Input:
The first input line contains an integer n.
The second line contains n−1 numbers. Each number is distinct and between 1 and n (inclusive).

Output:
Print the missing number.

Constraints: 2 ≤ n≤ 2⋅10^5

Time limit: 1.00 s 

Memory limit: 512 MB

Example-
Input:
5
2 3 1 5

Output:
4
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Solution 1: Store 1 to N in an array,  sort the given array and then compare both the array.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
 
    int array[200000];
    for(int i=0; i<n-1; i++)
    {
        cin>>array[i];
    }
 
    sort(array, array+(n-1));
 
 
    int temp[200000];
    for(int i=0; i<n; i++)
    {
        temp[i]=i+1;
    }
 
    for(int i=0; i<n; i++)
    {
        if(array[i]!=temp[i])
        {
            cout<<temp[i];
            break;
        }
    }
    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Solution 2: Store the elements form 1 to N in an array and compare with the given array  (Gives TLE)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
 
    int array[200000];
    for(int i=0; i<n-1; i++)
    {
        cin>>array[i];
    }
 
    int temp[200000];
    for(int i=0; i<n; i++)
    {
        temp[i]=i+1;
    }
 
 
    for(int i=0; i<n; i++)
    {
        bool flag=false;
        for(int j=0; j<n-1; j++)
        {
            if(temp[i]==array[j])
            {
                flag=true;
                break;
            }
        }
        if(flag==false)
        {
            cout<<temp[i];
        }
    }
 
    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Solution 3: Same as above just not using array, and doing linear comparison. (gives TLE)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
 
    int array[200000];
    for(int i=1; i<n; i++)
    {
        cin>>array[i];
    }
 
    for(int j=1; j<=n; j++)
    {
        bool flag=true;
        for(int k=1; k<n; k++)
        {
            if(array[k]==j)
            {
                flag=false;
                break;
            }
        }
        if(flag==true)
        {
            cout<<j<<endl;
        }
    }
    return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

Solution 4: sum from 1 to N and subtract array sum from that (the best solution)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
 
  int array[200000];
  for(int i=0; i<n-1; i++){
    cin>>array[i];
  }
 
  int d;
  if(n%2==0)
  {
    d=(n/2)*(n+1);
  }
  else
  {
    d=(n)*((n+1)/2);
  }
 
 
  int sum=0;
  for(int i=0; i<n; i++)
  {
    sum=sum+array[i];
  }
 
  cout<<d-sum<<endl;
  return 0;
}
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
