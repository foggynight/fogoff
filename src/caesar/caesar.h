// Copyright (C) 2021 Robert Coffey
// Released under the MIT license

#ifndef FOGOFF_CAESAR_H
#define FOGOFF_CAESAR_H

/**
 * Encrypt a string using Caesar's cipher.
 *
 * @param str  String to encrypt
 * @param key  Key to encrypt string with
 *
 * @return Non-zero indicates success
 **/
int caesar_encrypt(char *str, char *key);

#endif  // FOGOFF_CAESAR_H
