#ifndef DECODEBASE64_H
#define DECODEBASE64_H

#include <stdlib.h>

void BuildDecodingTable();
void Cleanup();
unsigned char *Base64Decode(const char *data,
                             size_t input_length,
                             size_t *output_length);

#endif
