#include <iostream>
#include <vector>

using namespace std;

class aa
{
    int n,m;
    vector<int> t,jj,tt;
    void kk(int n)
    {
        for(int i=0;i<n;i++)
        {
            t.push_back(i);
            tt.push_back(0);
        }
    }
public:
    void input()
    {
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int t;
            cin>>t;
            jj.push_back(t);
        }
        kk(n);
    }
    void output()
    {
        int i=0,ti=0;
        while(i < jj.size())
        {
            int pi=i;
            for(int j=0;j<t.size();j++)
            {
                if(tt[j]==0)
                {
                    tt[j]=jj[i];
                    cout<<t[j]<<" "<<ti<<"\n";
                    i++;
                }
                else
                {
                    tt[j]--;
                }
            }
            if(pi!=i)
                ti++;
        }
    }
};

int main()
{
    aa a;
    a.input();
    a.output();
}
