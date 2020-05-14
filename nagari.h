#ifndef __NAGARI_H__
#define __NAGARI_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct t_nagari_string {
    char *val;
};

typedef struct t_nagari_string NAGSTR;

struct t_nagari_bank_string {
    NAGSTR *str;
    struct t_nagari_bank_string *next;
    struct t_nagari_bank_string *prev;
};

// TODO: make bank thread safe
struct t_nagari_bank_string NAGBANK;
struct t_nagari_bank_string *NAGBANK_PTR;

void ninit();
void ncleanup();

// EVERY METHOD MUST TREAT STRINGS AS IMMUATABLE
NAGSTR *nstring(const char *str);
NAGSTR *nconcat(char *s1, char *s2);
int ncontains(char *s1, char *s2);
int nends_width(char *s1, char *s2);
int nequals(char *s1, char *s2);
int nindex_of(char *s1, char *s2);
NAGSTR *nto_lower(char *s1);
NAGSTR *nto_upper(char *s1);
NAGSTR *ninsert(char s1, char *s2);
int nlast_index_of(char *s1, char *s2);
int nlength(char *s1);
NAGSTR *nremove(char *s1, int i);
NAGSTR *nsplit(char *s1, char *s2);
int nstarts_with(char *s1, char *s);
NAGSTR *nsubstring(char s1, int si, int ei);
NAGSTR *ntrim(char *s1);

void nprint(NAGSTR *s1);
void nprintln(NAGSTR *s1);


// debug methods
void __nagari_dump();
#endif