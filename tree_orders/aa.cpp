#include <iostream>
#include <vector>

using namespace std;

class tree
{
    int n;
    vector<int> a,lf,rt;
public:
    void input()
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int k,l,r;
            cin>>k>>l>>r;
            a.push_back(k);
            lf.push_back(l);
            rt.push_back(r);
        }
    }
    void inorder(int i)
    {
        if(lf[i]!=-1)
        {
            inorder(lf[i]);
        }
        cout<<a[i]<<" ";
        if(rt[i]!=-1)
        {
            inorder(rt[i]);
        }
    }
    void pre(int i)
    {
        cout<<a[i]<<" ";
        if(lf[i]!=-1)
        {
            pre(lf[i]);
        }
        if(rt[i]!=-1)
        {
            pre(rt[i]);
        }
    }
    void post(int i)
    {
        if(lf[i]!=-1)
        {
            post(lf[i]);
        }
        if(rt[i]!=-1)
        {
            post(rt[i]);
        }
        cout<<a[i]<<" ";
    }
};

int main()
{
    tree t;
    t.input();
    t.inorder(0);
    cout<<"\n";
    t.pre(0);
    cout<<"\n";
    t.post(0);
}
