#include<cstdio>
#include<iostream>
#include<algorithm>
int v,e,p[4000],r[4000],c[4000],el[4000];

typedef struct
{
    int S;
    int E;
    int cost;
}edge ;

edge ed[4000],select[4000];

void init()
{
    for(int i=1;i<=v;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}

int find_set(int i)
{
    if(i!=p[i])
        p[i] = find_set(p[i]);
    return p[i];
}

void link(int x,int y)
{
    if(r[x]>r[y])
    {
      p[y] = x;
      r[y]++;
    }
    else
    {
        p[x] = y;
        if(r[x]==r[y])
        r[y]++ ;
    }
}

void union_(int x, int y)
{
    link(find_set(x),find_set(y));
}

int comp(const void *x , const void *y)
{
    edge *a , *b;
    a = (edge *)x;
    b = (edge *)y;

    return a->cost - b->cost ;
}

void kruskal()
{
    int i , count , c;
    count = 1;
    c = 0;
    for(i=1;i<=e;i++)
    {

        if(find_set(ed[i].S)!=find_set(ed[i].E))
        {
            union_(ed[i].S,ed[i].E);
            select[count++] = ed[i] ;
            c += ed[i].cost;

        }

    }

    printf("\n Total Cost : %d\n",c);

    for(i=1;i<count;i++)
    {
        printf("%d %d : %d\n",select[i].S,select[i].E,select[i].cost);

    }
}

int main()
{
    int i , j , a , b ,set;

    scanf("%d %d",&v,&e);
    init();

    for(i=1;i<=e;i++)
    {
        scanf("%d %d %d",&ed[i].S,&ed[i].E,&ed[i].cost);
    }

    qsort((void *)&ed[1],e,sizeof(edge),comp);

    kruskal();



    return 0;
}

