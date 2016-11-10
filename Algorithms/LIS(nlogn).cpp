#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<sstream>

using namespace std;

#define Max 1000000000
#define Min -1000000000
#define inf 2000000000
#define _inf -2000000000
#define lli long long int
#define psb push_back
#define pob pop_back

int sequence[1000000] , L[1000000] , I[1000000] , seq[1000000] , n;

void getinput()
{

  n = 0;

  while(scanf("%d",&sequence[n])!=EOF)
  {
    n++ ;
  }
  n++;

}

int lis_nlogn()
{
  int a ;
  I[0] = _inf ;

  for(a=1;a<=n;a++)
    I[a] = inf ;

    // binary search
    int low , mid , high , lislength;
    lislength = 0;
  for(a=0;a<n;a++)
  {
     low = 0;
     high = lislength ;

     while(low<=high)
     {
       mid = (low+high)/2 ;

       if(I[mid] < sequence[a])
         low = mid + 1;
       else
         high = mid - 1;
     }
     I[low] = sequence[a];
     L[a] = low;

     if(lislength < low)
       lislength = low ;

  }
  return lislength ;

}

void get_lis()
{
  int l ;
  l = lis_nlogn();

  int i , j ,top;
  i = 0;
  for(j=1;j<n;j++)
  {
    if(L[i]<=L[j])
     i = j;
  }
  top = L[i] - 1;
  seq[top] = sequence[i];
  top--;

  for(j=i-1;j>=0;j--)
  {
     if(sequence[j] < sequence[i] && L[j] == L[i] - 1)
     {
       i = j;
       seq[top] = sequence[j];
       top--;
     }
  }

  printf("%d\n",l);
  printf("-");
  printf("\n");

  for(i=0;i<l;i++)
  printf("%d\n",seq[i]);


}

int main()
{

getinput();
get_lis();
return 0;
}
