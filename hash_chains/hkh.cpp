#include <iostream>
#include <unordered_map>
#include <string>
#include <string.h>

using namespace std;

class ma
{
    unordered_map<int, string> ph;
public:
    void input(string s,int n)
    {
        ph.insert(make_pair(n,s));
    }
    void sea(int n)
    {
        if(ph.find(n)==ph.end())
            cout<<"not found\n";
        else
            cout<<ph.find(n)->second;
    }
    void del(int n)
    {
        ph.erase(n);
    }
}p;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string q,s;
        int n;
        cin>>q;
        if(!strcmp(q,"add"))
        {
            cin>>n>>s;
            p.input(s,n);
        }
        else if(!strcmp(q,"find"))
        {
            cin>>n;
            p.sea(n);
        }
        else
        {
            cin>>n;
            p.del(n);
        }
    }
}
