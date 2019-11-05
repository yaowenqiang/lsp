#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int return_value;
    return_value = system("ls -l");
    printf("%d\n", return_value);
    return 0;
}
