#include <stdio.h>

extern char **environ;


int main(void)
{
    char**  var;
    for (var= environ; *var != NULL; ++var) {
       printf("%s\n", *var); 
    }
    return 0;
}
