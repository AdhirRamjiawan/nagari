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

    NBOOL result_true = ncontains("Hello world", "wor");
    NBOOL result_false = ncontains("Hello world", "lo wo");
    NBOOL result_eq_true = nequals("hello", "hello");
    NBOOL result_eq_false = nequals("hello", "helLO");

    printf("Hello world contains 'wor': %d\n", result_true);
    printf("Hello world contains 'lo wo': %d\n", result_false);

    printf("hello == hello: %d\n", result_eq_true);
    printf("hello == helLO: %d\n", result_eq_false);

    int position_valid = nindex_of("hello world!", "lo");
    int position_invalid = nindex_of("hello world!", "mars");

    printf("position of 'lo' in 'hello world!': %d\n", position_valid);
    printf("position of 'mars' in 'hello world!': %d\n", position_invalid);

    ncleanup();
    return 0;
}