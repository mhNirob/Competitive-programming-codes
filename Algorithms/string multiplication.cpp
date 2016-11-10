#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>


using namespace std;

string s;

string cutLeadingZero(string a)
{
    string s="";
    int i;
    if(a[0]!='0') return a;
    for(i=0; i<sz(a); i++) if(a[i]!='0') break;
    for(;i<sz(a);i++) s+=a[i];

    return s;
}
string strAdd(string a, string b)
{
    int carry=0,i;
    string ans;
    if(sz(a)>sz(b)) b = string(sz(a)-sz(b),'0')+b;
    if(sz(b)>sz(a)) a = string(sz(b)-sz(a),'0')+a;

    ans.resize(sz(a));
    for(i=sz(a)-1; i>=0; i--)
    {
        int sum=carry+a[i]+b[i]-96;
        ans[i]=(char)(sum%10+'0');
        carry=sum/10;
    }
    if(carry) ans.insert(0,string(1,carry+'0'));
    ans=cutLeadingZero(ans);

    return ans;
}
string strMul(string a, string b)
{
    int i,j,multi,carry ;
    string ans="0",temp ;
    for(j=b.size()-1; j>=0; j--)
    {
        temp="";
        carry=0;
        for(i=a.size()-1; i>=0; i--)
        {
            multi = (a[i]-'0')*(b[j]-'0')+carry;
            temp+=(multi%10+'0');
            carry=multi/10;
        }
        if(carry) temp+=(carry+'0');
        Reverse(temp);
        temp+=string(b.size()-j-1,'0');
        ans=strAdd(ans,temp);
    }
    ans=cutLeadingZero(ans);

    return ans;
}
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
    cout<<"SUM : "<<strAdd(a,b)<<'\n';
    cout<<"Product : "<<strMul(a,b)<<'\n';
    }

}



















