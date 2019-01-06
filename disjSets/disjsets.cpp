#include <iostream>
#include "disjsets.h"


Disjsets::Disjsets(int numElementes)
    : s(numElementes,-1){}


void Disjsets::unionSets(int root1, int root2)
{
    s[root2] = root1;

}


int Disjsets::find(int x) const
{
    if(s[x] < 0)
        return x;
    else
        return find(s[x]);

}

int Disjsets::find(int x) 
{
    if(s[x] < 0)
        return x;
    else
        return find(s[x]);
}
void Disjsets::unionByHeight(int root1, int root2)
{
    if( s[root2] <  s[root1]) // root2 is deeper
        s[root1] = root2; // Make root2 new root
    else
    {
        if( s[root1] == s[root2])
            --s[root1];  // Update height if same
        s[root2] = root1; // Make root1 new root
    }


}
