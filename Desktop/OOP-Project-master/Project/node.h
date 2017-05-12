#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <string>
#include <map>
#include <vector>

using namespace std;

class node
{
    public:
    map<char, node*> go;
    vector<int> autocomplet;
    bool end_something;

    bool find(const char *v);
    void insert(const char *v, int ind);
    void search(const char *v);
};


#endif // NODE_H_INCLUDED

