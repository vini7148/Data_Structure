#include <iostream>
#include <string>
#include <stack>

using namespace std;

void ck(string ss)
{
    stack<char> a;
    stack<int> b;
    int co=0;
    for(int i=0;i<ss.length();i++)
    {
        co++;
        if(ss[i]=='(' || ss[i]=='{' || ss[i]=='[')
        {
            a.push(ss[i]);
            b.push(co);
        }
        else if(ss[i]==')' || ss[i]=='}' || ss[i]==']')
        {
            if(a.empty())
            {
                a.push(ss[i]);
                b.push(co);
                break;
            }
            if(ss[i]==')')
            {
                if(a.top()!='(')
                {
                    b.push(co);
                    break;
                }
                else
                {
                    a.pop();
                    b.pop();
                }
            }
            if(ss[i]=='}')
            {
                if(a.top()!='{')
                {
                    b.push(co);
                    break;
                }
                else
                {
                    a.pop();
                    b.pop();
                }
            }
            if(ss[i]==']')
            {
                if(a.top()!='[')
                {
                    b.push(co);
                    break;
                }
                else
                {
                    a.pop();
                    b.pop();
                }
            }
        }
    }
    if(a.empty())
        cout<<"Success";
    else
        cout<<b.top();
}

int main()
{
    string ss;
    cin>>ss;
    ck(ss);
}
