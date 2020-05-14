#include "nagari.h"


// EVERY METHOD MUST TREAT STRINGS AS IMMUATABLE
// EVERY METHOD NEEDS TO BE THREAD SAFE

NAGSTR *nstring(const char *str)
{
    struct t_nagari_bank_string *ptr = &NAGBANK;

    /* Navigate down the chain to
     * allocate new memory. */
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = (struct t_nagari_bank_string *)
        malloc(sizeof(struct t_nagari_bank_string));

    ptr->next->str = (NAGSTR *)malloc(sizeof(NAGSTR));
    ptr->next->str->val = (char *)malloc(sizeof(char) * strlen(str));
    ptr->next->prev = ptr;

    strcpy(ptr->next->str->val, str);

    return ptr->next->str;
}

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

void ninit()
{
    NAGBANK_PTR = &NAGBANK;
}

void ncleanup()
{
    // Go to the end of the list
    while(NAGBANK_PTR->next != NULL)
        NAGBANK_PTR = NAGBANK_PTR->next;

    // Clean up from the back
    while(NAGBANK_PTR->prev != NULL)
    {
        NAGBANK_PTR = NAGBANK_PTR->prev;

        if (NAGBANK_PTR != NULL)
        {
            if (NAGBANK_PTR->str != NULL)
            {
                if (NAGBANK_PTR->str->val != NULL)
                    free(NAGBANK_PTR->str->val);

                free(NAGBANK_PTR->str);
            }
        }
        
    }
}

inline void nprint(NAGSTR *s1)
{
    printf("%s", s1->val);
}

inline void nprintln(NAGSTR *s1)
{
    printf("%s\n", s1->val);
}