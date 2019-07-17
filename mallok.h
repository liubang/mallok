#ifndef MALLOK_H_R9PVWB3Y
#define MALLOK_H_R9PVWB3Y

#include <unistd.h>

typedef struct s_block *t_block;

/* open api */
void *malloc(size_t size);
void *calloc(size_t number, size_t size);
void *realloc(void *p, size_t size);
void free(void *p);

#endif /* end of include guard: MALLOK_H_R9PVWB3Y */
