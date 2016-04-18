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
#include<climits>
#include<fstream>

using namespace std;

/*
struct NODE
{

    int j;
    int k;
    NODE() {}
    NODE(int a, int b) : j(a), k(b) { }
    bool operator < (const NODE& rhs) const
    {
        return rhs.k < k ;
    }
};
*/

#define Max 22
#define Min -1
#define lli long long int
#define psb push_back
#define pob pop_back
#define forl(i,n) for(i=1;i<=n;i++)

//int kdx[] = { -2, -2, -1, 1, 2,  2,  1, -1 };
//int kdy[] = { -1,  1,  2, 2, 1, -1, -2, -2 };

int n;

vector<int>v,sum;
void find_all_sum()
{
  int sz,i,j,s;

  sz = v.size();

  for(i=0;i<(1<<sz);i++) // this nested loop is the main portion of your programme :)
  {
    s = 0;
    for(j=0;j<sz;j++)
    {
      if(i & (1<<j))
      s += v[j];
    }
    sum.push_back(s);
  }
/*
  for(i=0;i<(1<<sz);i++)
  cout<<sum[i]<<"   ";
  cout<<'\n';
*/

  sort(sum.begin(),sum.end());

  for(i=1;i<(1<<sz);i++)
  {
    if(!binary_search(sum.begin(),sum.end(),i))
    {
     cout<<i<<'\n';
     break ;
    }
  }

  return ;
}

int main()
{
  int a,num;
  cin>>n;
  a = n;

  while(a--)
  {
    cin>>num;
    v.push_back(num);
  }

  find_all_sum();


 return 0;
}

//94512 2 87654 81316 6 5 6 37151 6 139 1 36 307 1 377 101 8 37 58 1
