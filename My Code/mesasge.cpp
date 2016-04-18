#include<cstdio>
#include<cstring>
#include<map>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char,char>mm;
    int a,b,c,d,e;
    char str[1000],str2[1000];
    gets(str);
    for(int i=0;i<strlen(str);i++)
    {
        mm[(char)i+'a'+1]=str[i];
    }
    gets(str2);
    for(int i=0;i<strlen(str2);i++)
    {
        if(str2[i]>='a'&&str2[i]<='z')
        {
        printf("%c",mm[str2[i]]);
        }
        else printf("%c",toupper(mm[str2[i]]));
    }
    puts("");
}
