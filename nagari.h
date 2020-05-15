#ifndef __NAGARI_H__
#define __NAGARI_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define NTRUE   1
#define NFALSE  0

struct t_nagari_string {
    char *val;
};

typedef struct t_nagari_string NAGSTR;

struct t_nagari_bank_string {
    NAGSTR *str;
    struct t_nagari_bank_string *next;
    struct t_nagari_bank_string *prev;
};

typedef int NBOOL;

// TODO: make bank thread safe
struct t_nagari_bank_string NAGBANK;
struct t_nagari_bank_string *NAGBANK_PTR;

void ninit();
void ncleanup();

// EVERY METHOD MUST TREAT STRINGS AS IMMUATABLE
NAGSTR *nstring(const char *str);
NAGSTR *nconcat(char *s1, char *s2);
NAGSTR *njoin(int num, ...);
NBOOL ncontains(char *s1, char *s2);
NBOOL nends_width(char *s1, char *s2);
NBOOL nequals(char *s1, char *s2);
int nindex_of(char *s1, char *s2);
NAGSTR *nto_lower(char *s1);
NAGSTR *nto_upper(char *s1);
NAGSTR *ninsert(char s1, char *s2);
int nlast_index_of(char *s1, char *s2);
int nlength(char *s1);
NAGSTR *nremove(char *s1, int i);
NAGSTR *nsplit(char *s1, char *s2);
NBOOL nstarts_with(char *s1, char *s2);
NAGSTR *nsubstring(char s1, int si, int ei);
NAGSTR *ntrim(char *s1);

void nprint(NAGSTR *s1);
void nprintln(NAGSTR *s1);


// debug methods
void __nagari_dump();
#endif