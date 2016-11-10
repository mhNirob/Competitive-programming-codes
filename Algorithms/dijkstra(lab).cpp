#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cstring>

using namespace std;
#define sz 1024

long source , flag[sz] , adj[sz] , dist[sz] , adjmat[sz][sz] , costmat[sz][sz] , par[sz];

struct data
{
    long address , cost;

    bool operator <(const data  &x)const{

     return cost > x.cost;

    }
};

priority_queue<data> q;

void initialize(int v)
{
    long ind;
    for(ind=1;ind<=v;ind++)
    {
        dist[ind] = 100000;
        par[ind] = ind ;

    }
}

void dijkstra()
{
    long v , u , w , ind ;
    data temp ;
    //printf("u2");
    scanf("%d",&source) ;
    dist[source] = 0;
    memset(flag,0,sizeof(flag)) ;
    temp.address = source ;
    temp.cost = 0 ;
    q.push(temp) ;
    while(!q.empty())
    {
        //printf("u1");
       // temp = q.pop() ;
        temp = q.top();
        q.pop();
        u = temp.address ;
        if(flag[u])
        continue ;
        flag[u] = 1 ;

        for(ind=1;ind<=adj[u];ind++)
        {
            v = adjmat[u][ind];

            if (flag[v]) continue;

            w = costmat[u][v];

            if(dist[v]>dist[u]+w)
            {
                temp.address = v;
                temp.cost = w + dist[u];
                q.push(temp);
                par[v] = u;
                dist[v] = dist[u] + w;
            }
        }

    }

    return ;
}

int  print_path(int a)
{
    //printf("uu");
    if(a==source)
    return 0;
    print_path(par[a]);
    printf("%d ",a);
}

int main()
{
    int x , y , v , u , e , i , c;

    scanf("%d %d",&v,&e);
    initialize(v) ;
    for(i=1;i<=e;i++)
    {
        scanf("%d %d %d",&x,&y,&c);

        adj[x]+=1;
        adjmat[x][adj[x]] = y;
        costmat[x][y] = c;

        adj[y] += 1;
        adjmat[y][adj[y]] = x;
        costmat[y][x] = c;

    }

    dijkstra();
    for(i=1;i<=v;i++)
    {
    printf("%d ",source);
    print_path(i);
    printf("\n");
    }
    return 0;
}
/*
7 10
1 2 5
1 6 10
2 4 3
1 4 8
4 5 3
5 7 4
3 7 4
2 3 7
6 5 2
2 6 9
1
*/
















