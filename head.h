#ifndef HEAD_H_
#define HEAD_H_
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

void Swap(int* l, int* r)
{
    int t = *l;
    *l = *r;
    *r = t;
}

int RandomInRange(int l, int r)
{
    int index = 0;
    srand(time(nullptr));
    index = l + rand()%r;
    return index;
}
#endif // ! HEAD_H_
