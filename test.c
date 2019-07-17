#include <stdio.h>
#include "mallok.h"

struct student {
    char *name;
    int age;
};

int main(int argc, char *argv[]) {
    struct student *s = (struct student *)malloc(sizeof(struct student));
    s->name = "liubang";
    s->age = 26;
    printf("s:{name:%s, age:%d}\n", s->name, s->age);
    free(s);

    void *arr = calloc(2, sizeof(struct student));
    
    ((struct student *)(arr))->name = "liubang 1";
    ((struct student *)(arr))->age = 26;

    ((struct student *)(arr + sizeof(struct student)))->name = "liubang 2";
    ((struct student *)(arr + sizeof(struct student)))->age = 26;

    arr = realloc(arr, sizeof(struct student) * 3);

    free(arr);
    return 0;
}
