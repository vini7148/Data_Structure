#include <iostream>
#include <vector>

using namespace std;

class tree
{
    int n,mi,ma;
    vector<int> a,lf,rt;
public:
    void input()
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int k,l,r;
            if(i==0)
                mi=ma=k;
            cin>>k>>l>>r;
            a.push_back(k);
            lf.push_back(l);
            rt.push_back(r);
            if(mi>k)
                mi=k;
            if(ma<k)
                ma=k;
        }
    }
    /*int bst(int i)
    {
        if(n==0)
            return 1;
        else
        {
            if(rt[i]==-1 && lf[i]==-1)
                return 1;
            else if(rt[i]==-1)
            {
                if(a[i]<a[lf[i]])
                    return 0;
                else
                    return bst(lf[i]);
            }
            else if(lf[i]==-1)
            {
                if(a[i]>a[rt[i]])
                    return 0;
                else
                    return bst(rt[i]);
            }
            else if(a[i]>a[rt[i]] || a[i]<a[lf[i]])
                return 0;
            else
                return min(bst(rt[i]),bst(lf[i]));
        }
    }*/
    int bst(int i)
    {
        return(isBSTUtil(i, mi - 1, ma + 1));

    }
    int isBSTUtil(int i, int min, int max)
    {
        if (n==0 || n==1)
            return 1;
        if(i==-1)
            return 1;
        if (a[i] < min || a[i] > max)
            return 0;

        return isBSTUtil(lf[i], min, a[i]-1) && isBSTUtil(rt[i], a[i]-1, max);
    }
};

int main()
{
    tree t;
    t.input();
    if(t.bst(0))
        cout<<"CORRECT";
    else
        cout<<"INCORRECT";
}
