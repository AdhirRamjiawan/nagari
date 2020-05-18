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
    ptr->next->str->val = (char *)malloc(sizeof(char) * _nlen(str));
    ptr->next->prev = ptr;

    strcpy(ptr->next->str->val, str);

    return ptr->next->str;
}

/* Only works with \0 terminated strings. */
int _nlen(const char *str)
{
    int result = 0;
    char *ptr = (char *)str;

    while(*str != '\0')
        str++;

    result = str - ptr;
    str = ptr;

    return result;
}

NAGSTR *nconcat(char *s1, char *s2)
{
    NAGSTR *tmp;
    char *raw_str;
    char *ptr;
    int len = _nlen(s1);
    int len2 = _nlen(s2);
    
    raw_str = (char *)malloc(sizeof(char) * (len + len2));

    ptr = raw_str;

    for (int i = 0; i < len; i++)
        *raw_str++ = *s1++;

    for (int i = len2; i < len + len2; i++)
        *raw_str++ = *s2++;

    raw_str = ptr;

    tmp = nstring(raw_str);
    
    return tmp;
}

// Can we, and should we get rid off the int num?
NAGSTR *njoin(int num, ...)
{
    NAGSTR *tmp;
    char *raw_str;
    int tlen = 0;

    va_list largs;
    va_start(largs, num);

    // Get total string length
    for (int i = 0; i < num; i++)
    {
        char *s = va_arg(largs, char *);
        tlen += _nlen(s);
    }

    va_end(largs);

    raw_str = (char *)malloc(sizeof(char) * tlen);

    // Join all string args
    va_start(largs, num);
    for (int i = 0; i < num; i++)
    {
        char *s = va_arg(largs, char *);
        strcat(raw_str, s);
    }
    va_end(largs);

    tmp = nstring((const char *)raw_str);

    return tmp;
}

NBOOL ncontains(char *s1, char *s2)
{
    NBOOL result = NFALSE;

    if (strstr(s1, s2) != NULL)
        result = NTRUE;

    return result;
}

NBOOL nends_width(char *s1, char *s2);

NBOOL nequals(char *s1, char *s2)
{
    NBOOL result = NFALSE;

    if (strcmp(s1, s2) == 0)
        result = NTRUE;

    return result;
}

int nindex_of(char *s1, char *s2)
{
    int index = -1;
    char *ptr = strstr(s1, s2); 

    if (ptr  != NULL)
        index = ptr - s1;

    return index;
}

NAGSTR *nto_lower(char *s1)
{
    NAGSTR *tmp;
    int len = _nlen(s1);
    char *raw_str = (char *)malloc(sizeof(char) * len);
    char *ptr = raw_str;

    strcpy(raw_str, s1);

    /* if current char is within CAPS
     * range on ascii table then 
     * add 32 to it to shift it to the 
     * lower char equivalent on the
     * ascii table.  */
    for (int i = 0; i < len; i++)
    {
        int d = *raw_str;

        if (d >= ASCII_CAPS_START && d <= ASCII_CAPS_END)
            *raw_str = d + ASCII_CAPS_LOW_DIST;

        raw_str++;
    }

    raw_str = ptr;
    tmp = nstring((const char *)raw_str);

    return tmp;
}

NAGSTR *nto_upper(char *s1)
{
    NAGSTR *tmp;
    int len = _nlen(s1);
    char *raw_str = (char *)malloc(sizeof(char) * len);
    char *ptr = raw_str;

    strcpy(raw_str, s1);

    /* if current char is within lower char
     * range on ascii table then subtract 
     * 32 from it to shift it to the 
     * upper char equivalent on the
     * ascii table.  */
    for (int i = 0; i < len; i++)
    {
        int d = *raw_str;

        if (d >= ASCII_LOW_START && d <= ASCII_LOW_END)
            *raw_str = d - ASCII_CAPS_LOW_DIST;

        raw_str++;
    }

    raw_str = ptr;
    tmp = nstring((const char *)raw_str);

    return tmp;
}

NAGSTR *ninsert(char s1, char *s2);
int nlast_index_of(char *s1, char *s2);

inline int nlength(char *s1)
{
    return _nlen(s1);
}

NAGSTR *nremove(char *s1, int i)
{
    NAGSTR *result;
    int len = _nlen(s1);
    char *raw_str = (char *)malloc(sizeof(char) * len);
    char *ptr = raw_str;

    strcpy(raw_str, s1);

    for (int k = 0; k < i - 1; k++)
        raw_str++;

    *raw_str = '\0';
    raw_str = ptr;

    result = nstring(raw_str);
    free(raw_str);
    free(ptr);

    return result;
}

NAGSTR *nsplit(char *s1, char *s2);

NBOOL nstarts_with(char *s1, char *s2)
{
    NBOOL result = NFALSE;
    int len = _nlen(s1);
    int len2 = _nlen(s2);
    int count = 0;
    

    while (*s1 == *s2)
    {
        s1++;
        s2++;
        count++;
    }

    if (count >= len2)
        result = NTRUE;

    return result; 
}

NAGSTR *nsubstring(char *s1, int si, int ei)
{
    NAGSTR *sub_str;
    char *raw_str;

    int len = _nlen(s1);

    for (int i=0; i <= si; i++)
        s1++;

    

    return sub_str;
}

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