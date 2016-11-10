#include<cstdio>
#include<iostream>
int v,e,p[20],r[20],c[20],el[20];
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



int main()
{
    int i , j , a , b ,set;

    scanf("%d %d",&v,&e);
    init();
    for(i=1;i<=e;i++)
    {
        scanf("%d %d",&a,&b);
        if(find_set(a)!=find_set(b))
        {
            union_(a,b);
            printf("Linked \n");
        }
        else
            printf("Not Linked \n");
    }
    set = 0;
    for(i=1;i<=v;i++)
    {
        if(c[p[i]]==0)
        {
        set++;
        c[p[i]] = 1;
        }
        el[p[i]]++;
    }
    for(i=1;i<=v;i++)
    c[p[i]] = 0;
     printf("Total Set : %d \n",set);
     j = 1;
     for(i=1;i<=v;i++)
     {
         if(c[p[i]]==0)
         {
         printf("set no. %d : %d (Max element)\n",j++,el[p[i]]);
         c[p[i]] = 1;
         }
     }

    return 0;
}
