/**
 * *** Rijndael's Key Schedule ***
 *
 * Copyright (C) 2021 Robert Coffey
 * Released under the MIT license
 **/

#include <stdint.h>

/**
 * Rotate a 32-bit word to the left by 8-bits.
 *
 * EXAMPLE: 0x12345678 -> 0x34567812
 **/
uint32_t rotate_word(uint32_t word)
{
    return (word << 8) | (word >> 24);
}
