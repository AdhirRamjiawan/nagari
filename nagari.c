#include "nagari.h"


// EVERY METHOD MUST TREAT STRINGS AS IMMUATABLE
NAGSTR *nstring();
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

