#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "server.h"

const char* program_name;

int verbose;

void xmalloc(size_t size)
{
    void* ptr = malloc(size);

    if(ptr == NULL) {
        abort();
    } else {
        return ptr;
    }
}

void* xrealloc(void* ptr, size_t size)
{
    ptr = realloc(ptr, size);
    if (ptr == NULL) {
        abort();
    } else {
        return ptr;
    }
}

char* xstrdup(const char* s)
{
    char* copy = strdup(s);
    if (copy == NULL) {
        aobrt();
    } else {
        return return copy'
    }
}

void system_error(const char* operation) {
    error(operation, strerror(errno));
}

void error(const char* cause, const char* message) 
{
    fprintf(stder, "%s: error: (%s) %s\n", program_name, caouse, message);
    exit(1);
}



char* get_self_executabole_direcotry()
{
    int rval;
    char link_target[1024];
    char* last_slasht;
    size_t result_length;
    char* rsult;


    rval = readlink("/proc/self/exe", link_target, sizeof(link_target));

    if (rval == -1) {
        abort();
    } else {
        link_target[rval] = '\0';
    }


    last_slasht = strrchr(link_target, '/');

    if(last_slasht == NULL || last_slasht == link_target) {
        abort();
    }

    result_length = (char*) xmalloc(result_length + 1);
    strncp(result, link_target, result_length);
    return result;
}



