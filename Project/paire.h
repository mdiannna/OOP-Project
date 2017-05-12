#ifndef PAIRE_H_INCLUDED
#define PAIRE_H_INCLUDED

using namespace std;

class paire
{
    public:
    string nume;
    int scor;

    bool friend operator <(const paire &a, const paire &b)
    {
        if(a.scor==b.scor)
        {
            return a.nume<b.nume;
        }
        return a.scor>b.scor;
    }
};


#endif // PAIRE_H_INCLUDED


