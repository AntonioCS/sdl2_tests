
#include <stdio.h>
#include <stdlib.h>
#include "uthash/src/uthash.h"

#define ARRAY_LENGTH(a) (sizeof(a)/sizeof((a)[0]))

struct vector {
    int x;
    int y;
};

struct my_struct {
    char key[150];
    struct vector *vec;
    UT_hash_handle hh; /* makes this structure hashable */
};

int main(int argc, char** argv) {

    struct my_struct *test = NULL;

    struct vector vec1 = {.x = 10, .y = 20};
    struct vector vec2 = {.x = 55, .y = 11};
    struct my_struct *s;   

    s = malloc(sizeof (struct my_struct));
    strncpy(s->key, "vec1", 10);
    s->vec = &vec1;

    HASH_ADD_STR(test, key, s);
    
    s = malloc(sizeof (struct my_struct));
    strncpy(s->key, "vec2", 10);
    s->vec = &vec2;

    HASH_ADD_STR(test, key, s);

    
    HASH_FIND_STR(test, "vec1", s);
    
    printf("X: %d - Y: %d", s->vec->x, s->vec->y);





    return (EXIT_SUCCESS);
}

