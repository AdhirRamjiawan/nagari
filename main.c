#include "nagari.h"

int main(void)
{
    ninit();
    NAGSTR *hello = nstring("hello");
    NAGSTR *space = nstring(" ");
    NAGSTR *world = nstring("world!");

    nprint(hello);
    nprint(space);
    nprintln(world);
    
    ncleanup();
    return 0;
}