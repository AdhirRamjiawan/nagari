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

   /* nprint(hello);
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

    int len = nlength("hello world!");

    printf("Length of 'hello world!': %d\n", len);

    NBOOL starts_with_result_valid  = nstarts_with("helloworld", "hello");
    NBOOL starts_with_result_invalid  = nstarts_with("helloworld", "ello");

    printf(" 'hello world' starts with 'hello': %d\n", starts_with_result_valid);
    printf(" 'hello world' starts with 'ello': %d\n", starts_with_result_invalid);

    printf("lower case of 'HELLO WORld!' is: %s\n", nto_lower("HELLO WORld!")->val);
    printf("upper case of 'hEllO wORld!' is: %s\n", nto_upper("hEllO wORld!")->val);

    printf("remove from index 9 from 'Hello world!': %s \n", nremove("Hello world!", 9)->val);

    printf("The substring from 3 to 7 of 'Hello world!' is: %s\n", nsubstring("Hello world!", 3, 7)->val);
*/
    printf("Having '   Hello  ' trimmed is: '%s'\n", ntrim("   Hello  ")->val);
    ncleanup();
    return 0;
}