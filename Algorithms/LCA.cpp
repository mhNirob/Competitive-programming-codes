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
#include<set>
#include<list>
#include<sstream>
#include<utility>
#include<climits>
#include<fstream>
#include<bitset>

using namespace std;

#define Max 1000000
#define Min -1
#define logmax 20
#define lli long long int
#define psb push_back
#define pob pop_back
#define forl(i,n) for(i=1;i<=n;i++)
#define all(a) a.begin(),a.end()

typedef pair<int,int> pii;
typedef pair<lli,lli> pli;
typedef vector<int> vi;
typedef vector<lli> vli;

//int kdx[] = { -2, -2, -1, 1, 2,  2,  1, -1 };
//int kdy[] = { -1,  1,  2, 2, 1, -1, -2, -2 };
/*
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
*/

// root : 1
vector<int>adj[Max+5];
int n,e,par[Max+5][logmax+5],L[Max];

void reset()
{
    memset(par,-1,sizeof(par));
    return;
}

void input()
{
    int n1,n2;
    scanf("%d %d",&n,&e);
    for(int i=1; i<=e; i++)
    {
        scanf("%d %d",&n1,&n2);
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    return;
}

void dfs(int node,int f)
{
    int child,sz;
    sz=adj[node].size();
    for(int i=0; i<sz; i++)
    {
        child=adj[node][i];
        if(f!=child)
        {
            par[child][0]=node;
            L[child]=L[node]+1;
            dfs(child,node);
        }
    }
    return ;
}

void process()
{

    for(int i=1; i<=20; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(par[j][i-1]!=-1)
                par[j][i]=par[par[j][i-1]][i-1];
        }
    }
    return ;
}

int lca_query(int p,int q)
{

    int temp,step;
    if(L[p]<L[q])
    {
        temp=p;
        p=q;
        q=temp;
    }

    for(step=1; (1<<step)<=L[p]; step++);
    step--;
    temp=step;
    for(; step>=0; step--)
    {
        if((L[p]-(1<<step))>=L[q])
        {
            p=par[p][step];
        }
    }

    if(p==q)
    {
        return p;
    }
    step=temp;
    for(; step>=0; step--)
    {
        if(par[p][step] != -1 && par[p][step]!=par[q][step])
        {
            p=par[p][step];
            q=par[q][step];
        }
    }

    return par[p][0];
}

void query()
{
    int q,u,v;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&u,&v);
        printf("LCA : %d\n",lca_query(u,v));
    }
    return;
}

int main()
{
//ios::sync_with_stdio(false);
    reset();
    input();
    dfs(1,1);
    process();
    query();
    return 0;
}

/*
14
13
1 2
1 3
2 4
2 5
4 9
4 10
3 6
3 7
3 8
7 11
7 12
11 13
11 14
*/
