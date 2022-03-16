#include <iostream>
#include "ctime"
#include "fstream"
#include "seq.h"
using namespace std;



int main( )
{
    seq seq;
    seq::SeqList L;
    seq.ListInitial(L);
    seq.ListInsert(L,1,3);
    seq.ListInsert(L,2,2);
    seq.ListInsert(L,3,1);
    seq.PrintList(L);


    return 0;
}




