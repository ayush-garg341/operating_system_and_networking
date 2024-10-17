#include<stdio.h>
#include<string.h>
#include<stdlib.h>

static size_t count_segment(char const *s, char c)
{
    size_t counter = 0;
    int i = 0;
    while (s[i])
    {
        if(s[i] == c)
        {
            i++;
            continue;
        }
        counter++;

        while(s[i] && s[i] != c)
            i++;
    }

    return counter;
}

char **split(char const *s, char c)
{

    char **strs;
    size_t tab_counter;
    size_t i;
    size_t j;

    if (s==NULL)
        return (NULL);

    tab_counter = count_segment(s, c);
    printf("tab counter is %zu\n", tab_counter);
    if ((strs = (char**)malloc(sizeof(char*) * (tab_counter + 1))) == NULL)
        return (NULL);
    tab_counter = 0;
    j = -1;
    while (s[++j])
    {
        if (s[j] == c)
            continue;
        i = 0;
        while (s[j + i] && s[j + i] != c)
            i++;
        printf("i and j is %zu , %zu respectively \n", i, j);
        if ((strs[tab_counter++] = strndup(&s[j], i)) == NULL)
            return NULL;
        j += i - 1;
    }
    strs[tab_counter] = NULL;
    return strs;

}

int main(void) {
    // It does not handle empty fields. like "1,2,,,3,4,5"
    char const *s = "222,2,,,3,4,5";
    char **parts = split(s, ',');
    for(int i = 0; parts[i] != NULL; i++) {
        printf("%s\n", parts[i]);
    }
    printf("\n");
    printf("s is %s\n", s);
    printf("\n");

    // String that is modifiable:- array of characters or malloced string
    // This below method modifies the original string.
    // It does not handle empty fields. like "1,2,,,3,4,5"
    char t[] = "1,2,3,,,,4,5";
    char *token = strtok(t, ",");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    printf("\n");
    printf("t is %s\n", t);
    printf("\n");


    // String that is modifiable:- array of characters or malloced string
    // This below method modifies the original string.
    // It handles empty fields. like "1,2,,,3,4,5"
    char u[] = "1,2,3,,,4,5";
    char *u_ptr = u;
    char *utoken;
    while((utoken = strsep(&u_ptr, ",")) != NULL)
        printf("%s\n", utoken);

    printf("\n");

    printf("u is %s\n", u);

    return 0;
}
