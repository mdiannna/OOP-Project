#include "node.h"
#include <iostream>

#include "persoana.h"

using namespace std;

void node::search(const char *v)
{
    if(this==nullptr)
    {
        cout<<"none\n";
        return;
    }

    if(v[0]==0)
    {
        for(int i=0; i< autocomplet.size(); i++)
        {
            cout<<Persoana::who[autocomplet[i]]<<" ";
        }
        cout<<"\n";
        return;
    }

    if(go[v[0]]==0)
    {
        cout<<"none\n";
        return;
    }

    return go[v[0]]->search(v+1);
}


bool node::find(const char *v)
{
    if(this==nullptr)
        return 0;

    if(v[0]==0)
        return end_something;

    if(go[v[0]]==0)
        return 0;

    return go[v[0]]->find(v+1);
}

void node::insert(const char *v, int ind)
{
    autocomplet.push_back(ind);

    if(v[0]==0)
    {
        end_something=1;
        return;
    }

    if(go[v[0]]==0)
    {
        go[v[0]]=new node;
    }

    go[v[0]]->insert(v+1, ind);

}
