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
#include<utility>

using namespace std;

#define Max 100000
#define Min -1
#define lli long long int
#define psb push_back
#define pob pop_back
#define forl(i,n) for(i=1;i<=n;i++)

lli n,f,l;
lli arr[Max+7] , tree[4*(Max+7)] ;

void input()
{
  lli i;
  scanf("%lld",&n);
  forl(i,n)
  scanf("%lld",&arr[i]);
  scanf("%lld %lld",&f,&l);
  return ;
}

lli init(lli n,lli a,lli b)
{
   cout<<n<<endl;
   if(a==b)
   {
     return tree[n] = arr[a] ;
   }

   lli left = n*2 ;
   lli right = n*2 + 1 ;
   lli mid = (a+b)/2 ;
   return tree[n] = init(left,a,mid) + init(right,mid+1,b) ;
}

lli query(lli n,lli a,lli b,lli i,lli j)
{
   if(i>b || j<a) return 0;
   if(a>=i && b<=j) return tree[n];
   lli left = n*2;
   lli right = n*2 + 1;
   lli mid = (a+b)/2;
   lli p1 = query(left,a,mid,i,j);
   lli p2 = query(right,mid+1,b,i,j);

   return p1+p2 ;

}

void update(lli n,lli a,lli b,lli i,lli newvalue)
{
   if(i> b || i<a)
   return ;

   if(a==i && b==i)
   {
     tree[n] = newvalue;
     return;
   }

   lli left = n*2 ;
   lli right = n*2 + 1 ;
   lli mid = (a+b)/2 ;
   update(left,a,mid,i,newvalue);
   update(right,mid+1,b,i,newvalue);
   tree[n] = tree[left] + tree[right];

}

void output()
{
  lli i ;
  forl(i,2*n+1)
  printf("%lld ",tree[i]) ;
}

int main()
{
  lli ret ;
  input() ;
  init(1,1,n);
  //update(1,1,n,4,9);
  ret = query(1,1,n,f,l);
  cout<<ret<<endl;
  //output();


return 0 ;
}
