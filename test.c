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
    return 0;
}
