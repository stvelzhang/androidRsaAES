/*  
*   Byte-oriented AES-256 implementation.
*   All lookup tables replaced with 'on the fly' calculations. 
*
*   Copyright (c) 2007-2009 Ilya O. Levin, http://www.literatecode.com
*   Other contributors: Hal Finney
*
*   Permission to use, copy, modify, and distribute this software for any
*   purpose with or without fee is hereby granted, provided that the above
*   copyright notice and this permission notice appear in all copies.
*
*   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 * coded by longdw 2015.5.21
 * http://www.longdw.com
*/


#ifndef _AES256_H_
#define _AES256_H_

#include<stdio.h>
#include<string.h>
#include<jni.h>
#include <android/log.h>
#include <stdlib.h>

#ifndef uint8_t
#define uint8_t  unsigned char
#endif

#ifdef __cplusplus
extern "C" { 
#endif

    typedef struct {
        uint8_t key[32];
        uint8_t enckey[32];
        uint8_t deckey[32];
    } aes256_context; 


    void aes256_init(aes256_context *, uint8_t * /* key */);
    void aes256_done(aes256_context *);
    void aes256_encrypt(aes256_context *, uint8_t * /* plaintext */);
    void aes256_decrypt(aes256_context *, uint8_t * ,uint8_t */* cipertext */);
	void aes256_encrypt_cbc(aes256_context *, uint8_t *, uint8_t *,  uint8_t *);
	void aes256_decrypt_cbc(aes256_context *, uint8_t *, uint8_t *,  uint8_t *);
	double GetTime();

#ifdef __cplusplus
}
#endif

#define DUMP(s, i, buf, sz)  {printf(s);                   \
                              for (i = 0; i < (sz);i++)    \
                                  printf("%02x ", buf[i]); \
                              printf("\n");}


#endif

