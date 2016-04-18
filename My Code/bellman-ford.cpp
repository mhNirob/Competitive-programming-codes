#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<limits>
#include<cmath>

using namespace std;

//template <class T> (T) INFINITY;

#define Max 1000
int v , e ;
int inf = (int)INFINITY;

int dist[Max+7];
struct data
{
    int sour;
    int dest;
    int cost;

}edge[Max+7] ;

void input()
{
    int a;
    scanf("%d %d",&v,&e);
    for(a=0;a<e;a++)
    {
        scanf("%d %d %d",&edge[a].sour,&edge[a].dest,&edge[a].cost);
    }
    return ;
}

void initialize_single_source()
{
    for(int i=1;i<v;i++)
    {
        dist[i] = inf;
    }
    dist[0] = 0;
}

void relax(int u,int v,int w)
{

    if(dist[v]>dist[u]+w)
        dist[v] = dist[u]+w;

    return ;
}

bool bellman_ford()
{
    int i,j;

    initialize_single_source();

    for(j=1;j<v;j++)
    {
        for(j=0;j<e;j++)
        {
            relax(edge[j].sour,edge[j].dest,edge[j].cost);
        }
    }

    for(j=0;j<e;j++)
    {
        if(dist[edge[j].dest] > dist[edge[j].sour] + edge[j].cost)
            return true;
    }

    return false;

}

int main()
{

    int t;
    bool s;
    scanf("%d",&t);
    while(t--)
    {
    //reset();
    input();

    s = bellman_ford();

    if(s==true)
        printf("possible\n");
    else
        printf("not possible\n");
    }


    return 0;
}
