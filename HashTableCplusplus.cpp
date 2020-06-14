#include <iostream>
#include "HashTable.h"
#include "Referate.h"

using namespace std;
int main()
{
    HashTable<Referate>* HT = new HashTable<Referate>(3);
    auto first = new Referate(1, "first");
    auto second = new Referate(2, "fofof");
    auto first1 = new Referate(1, "first");
    auto second1 = new Referate(2, "fofof");
    HT->Add(*first);
    HT->Add(*second);
    HT->Add(*first1);
    HT->Add(*second1);
    HT->ShowTable();
}

