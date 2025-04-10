#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap/heap.h"

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
    char data;
    size_t freq;
} symbol_t;

#define CHAR_TABLE_SIZE 256
#define FREQ_TABLE_SIZE 256

typedef char char_table_t[CHAR_TABLE_SIZE];
typedef size_t freq_table_t[FREQ_TABLE_SIZE];

extern char *program_invocation_name;
extern char *program_invocation_short_name;

symbol_t *symbol_create(char data, size_t freq);

#endif /* _HUFFMAN_H_ */
