#include "nagari.h"

int main(void)
{
    ninit();
    NAGSTR *hello = nstring("hello");
    NAGSTR *space = nstring(" ");
    NAGSTR *world = nstring("world!");
    NAGSTR *helloworld = nconcat("hello ", "world!");
    NAGSTR *quick_brown_fox = njoin(13, "The", " ", "brown", " ", 
            "fox", " ", "jumps", " ", "over", " ", 
            "lazy", " ", "dog");

    nprint(hello);
    nprint(space);
    nprintln(world);

    nprintln(helloworld);
    nprintln(quick_brown_fox);

    ncleanup();
    return 0;
}