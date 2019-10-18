#include <iostream>
#include <vector>

using namespace std;

class heap
{

    vector<int> hp,ansl,ansr;
    int si=-1,n;

    public:

    void input()
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int te;
            cin>>te;
            hp.push_back(te);
        }
    }

    int par(int i)
    {
        return (i-1)/2;
    }

    int lf(int i)
    {
        return (2*i)+1;
    }

    int ri(int i)
    {
        return (2*i)+2;
    }

    void shd(int i)
    {
        int mi=i;
        int l=lf(i);
        if(l<si && hp[l]<hp[mi])
            mi=l;
        int r=ri(i);
        if(r<si && hp[r]<hp[mi])
            mi=r;
        if(i!=mi)
        {
            int te=hp[i];
            hp[i]=hp[mi];
            hp[mi]=te;

            ansl.push_back(i);
            ansr.push_back(mi);

            shd(mi);
        }
    }

    void make()
    {
        si=hp.size();
        for(int i=hp.size()/2;i>-1;i--)
        {
            shd(i);
        }
    }

    void ans()
    {
        make();
        cout<<ansl.size()<<"\n";
        for(int i=0;i<ansl.size();i++)
            cout<<ansl[i]<<" "<<ansr[i]<<"\n";
    }

};

int main()
{
    heap h;
    h.input();
    h.ans();
}
