/*
 * Copyright 2018, Cypress Semiconductor Corporation or a subsidiary of 
 * Cypress Semiconductor Corporation. All Rights Reserved.
 * 
 * This software, associated documentation and materials ("Software"),
 * is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/* libFLAC - Free Lossless Audio Codec library
 * Copyright (C) 2000-2009  Josh Coalson
 * Copyright (C) 2011-2014  Xiph.Org Foundation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * - Neither the name of the Xiph.org Foundation nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FLAC__PRIVATE__BITREADER_H
#define FLAC__PRIVATE__BITREADER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h> /* for FILE */
#include "FLAC/ordinals.h"
#include "cpu.h"

/*
 * opaque structure definition
 */
struct FLAC__BitReader;
typedef struct FLAC__BitReader FLAC__BitReader;

typedef FLAC__bool (* FLAC__BitReaderReadCallback)( FLAC__byte buffer[], size_t* bytes, void* client_data );

/*
 * construction, deletion, initialization, etc functions
 */
FLAC__BitReader* FLAC__bitreader_new( void );
void             FLAC__bitreader_delete( FLAC__BitReader* br );
FLAC__bool       FLAC__bitreader_init( FLAC__BitReader* br, FLAC__BitReaderReadCallback rcb, void* cd );
void             FLAC__bitreader_free( FLAC__BitReader* br ); /* does not 'free(br)' */
FLAC__bool       FLAC__bitreader_clear( FLAC__BitReader* br );
void             FLAC__bitreader_dump( const FLAC__BitReader* br, FILE* out );

/*
 * CRC functions
 */
void         FLAC__bitreader_reset_read_crc16( FLAC__BitReader* br, FLAC__uint16 seed );
FLAC__uint16 FLAC__bitreader_get_read_crc16( FLAC__BitReader* br );

/*
 * info functions
 */
FLAC__bool FLAC__bitreader_is_consumed_byte_aligned( const FLAC__BitReader* br );
unsigned   FLAC__bitreader_bits_left_for_byte_alignment( const FLAC__BitReader* br );
unsigned   FLAC__bitreader_get_input_bits_unconsumed( const FLAC__BitReader* br );

/*
 * read functions
 */

FLAC__bool FLAC__bitreader_read_raw_uint32( FLAC__BitReader* br, FLAC__uint32* val, unsigned bits );
FLAC__bool FLAC__bitreader_read_raw_int32( FLAC__BitReader* br, FLAC__int32* val, unsigned bits );
FLAC__bool FLAC__bitreader_read_raw_uint64( FLAC__BitReader* br, FLAC__uint64* val, unsigned bits );
FLAC__bool FLAC__bitreader_read_uint32_little_endian( FLAC__BitReader* br, FLAC__uint32* val );                    /*only for bits=32*/
FLAC__bool FLAC__bitreader_skip_bits_no_crc( FLAC__BitReader* br, unsigned bits );                                 /* WATCHOUT: does not CRC the skipped data! */ /*@@@@ add to unit tests */
FLAC__bool FLAC__bitreader_skip_byte_block_aligned_no_crc( FLAC__BitReader* br, unsigned nvals );                  /* WATCHOUT: does not CRC the read data! */
FLAC__bool FLAC__bitreader_read_byte_block_aligned_no_crc( FLAC__BitReader* br, FLAC__byte* val, unsigned nvals ); /* WATCHOUT: does not CRC the read data! */
FLAC__bool FLAC__bitreader_read_unary_unsigned( FLAC__BitReader* br, unsigned* val );
FLAC__bool FLAC__bitreader_read_rice_signed( FLAC__BitReader* br, int* val, unsigned parameter );
FLAC__bool FLAC__bitreader_read_rice_signed_block( FLAC__BitReader* br, int vals[], unsigned nvals, unsigned parameter );

#if 0 /* UNUSED */
FLAC__bool FLAC__bitreader_read_golomb_signed( FLAC__BitReader* br, int* val, unsigned parameter );
FLAC__bool FLAC__bitreader_read_golomb_unsigned( FLAC__BitReader* br, unsigned* val, unsigned parameter );
#endif
FLAC__bool FLAC__bitreader_read_utf8_uint32( FLAC__BitReader* br, FLAC__uint32* val, FLAC__byte* raw, unsigned* rawlen );
FLAC__bool FLAC__bitreader_read_utf8_uint64( FLAC__BitReader* br, FLAC__uint64* val, FLAC__byte* raw, unsigned* rawlen );
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

