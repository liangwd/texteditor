/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Mozilla Communicator client code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "../nsSBCharSetProber.h"

/********* Language model for: Thai *********/

/**
 * Generated by BuildLangModel.py
 * On: 2015-12-04 03:05:06.182099
 **/

/* Character Mapping Table:
 * ILL: illegal character.
 * CTR: control character specific to the charset.
 * RET: carriage/return.
 * SYM: symbol (punctuation) that does not belong to word.
 * NUM: 0 - 9.
 *
 * Other characters are ordered by probabilities
 * (0 is the most common character in the language).
 *
 * Orders are generic to a language. So the codepoint with order X in
 * CHARSET1 maps to the same character as the codepoint with the same
 * order X in CHARSET2 for the same language.
 * As such, it is possible to get missing order. For instance the
 * ligature of 'o' and 'e' exists in ISO-8859-15 but not in ISO-8859-1
 * even though they are both used for French. Same for the euro sign.
 */
static const unsigned char Tis_620_CharToOrderMap[] =
{
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,RET,CTR,CTR,RET,CTR,CTR, /* 0X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 1X */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* 2X */
  NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,SYM,SYM,SYM,SYM,SYM,SYM, /* 3X */
  SYM, 66, 70, 67, 80, 78, 87, 85, 73, 79, 93, 88, 84, 68, 77, 81, /* 4X */
   75,101, 74, 61, 71, 86, 96, 90,103,100, 99,SYM,SYM,SYM,SYM,SYM, /* 5X */
  SYM, 35, 64, 48, 52, 32, 60, 65, 54, 36, 97, 76, 46, 56, 41, 40, /* 6X */
   59,104, 43, 45, 44, 55, 72, 82, 94, 57, 92,SYM,SYM,SYM,SYM,CTR, /* 7X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 8X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 9X */
  ILL,  3, 23,105, 15,106, 89,  5, 21, 63, 26, 31,102, 42, 69, 58, /* AX */
   49, 91, 83, 34,  9, 17, 30, 12, 39,  1, 16, 19, 33, 62, 22, 47, /* BX */
   38,  7, 10,  2, 50, 11,107,  8, 28, 37, 13, 18, 98,  4, 53, 95, /* CX */
   14,SYM,  0, 29,SYM,SYM,SYM,SYM,SYM,SYM,SYM,ILL,ILL,ILL,ILL,SYM, /* DX */
    6, 20, 27, 24, 25,108, 51,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,109, /* EX */
  NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,110,111,ILL,ILL,ILL,ILL, /* FX */
};
/*X0  X1  X2  X3  X4  X5  X6  X7  X8  X9  XA  XB  XC  XD  XE  XF */

static const unsigned char Iso_8859_11_CharToOrderMap[] =
{
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,RET,CTR,CTR,RET,CTR,CTR, /* 0X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 1X */
  SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM, /* 2X */
  NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,SYM,SYM,SYM,SYM,SYM,SYM, /* 3X */
  SYM, 66, 70, 67, 80, 78, 87, 85, 73, 79, 93, 88, 84, 68, 77, 81, /* 4X */
   75,101, 74, 61, 71, 86, 96, 90,103,100, 99,SYM,SYM,SYM,SYM,SYM, /* 5X */
  SYM, 35, 64, 48, 52, 32, 60, 65, 54, 36, 97, 76, 46, 56, 41, 40, /* 6X */
   59,104, 43, 45, 44, 55, 72, 82, 94, 57, 92,SYM,SYM,SYM,SYM,CTR, /* 7X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 8X */
  CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR,CTR, /* 9X */
  SYM,  3, 23,112, 15,113, 89,  5, 21, 63, 26, 31,102, 42, 69, 58, /* AX */
   49, 91, 83, 34,  9, 17, 30, 12, 39,  1, 16, 19, 33, 62, 22, 47, /* BX */
   38,  7, 10,  2, 50, 11,114,  8, 28, 37, 13, 18, 98,  4, 53, 95, /* CX */
   14,SYM,  0, 29,SYM,SYM,SYM,SYM,SYM,SYM,SYM,ILL,ILL,ILL,ILL,SYM, /* DX */
    6, 20, 27, 24, 25,115, 51,SYM,SYM,SYM,SYM,SYM,SYM,SYM,SYM,116, /* EX */
  NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,NUM,117,118,ILL,ILL,ILL,ILL, /* FX */
};
/*X0  X1  X2  X3  X4  X5  X6  X7  X8  X9  XA  XB  XC  XD  XE  XF */


/* Model Table:
 * Total sequences: 2324
 * First 512 sequences: 0.8815720594354438
 * Next 512 sequences (512-1024): 0.0920860122682917
 * Rest: 0.026341928296264486
 * Negative sequences: TODO
 */
static const PRUint8 ThaiLangModel[] =
{
  0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,2,3,
   0,2,3,0,0,3,2,3,0,0,2,0,0,0,0,2,0,1,1,1,0,2,0,0,0,0,1,0,0,0,1,1,
  3,3,3,3,3,2,3,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,
   0,3,0,0,0,1,3,3,0,0,1,0,0,0,0,2,0,2,1,2,0,1,0,0,0,0,0,0,0,0,2,1,
  3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,3,3,2,3,3,3,3,3,3,2,2,2,3,1,3,2,
   0,2,3,0,0,2,2,1,0,0,0,0,0,0,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,2,1,
  3,3,3,3,3,2,3,3,3,3,2,3,3,3,2,3,2,3,3,3,3,3,3,3,3,3,2,3,2,3,2,3,
   0,2,1,0,0,3,2,1,0,0,0,0,0,0,0,1,0,3,3,1,0,1,0,0,0,0,3,0,0,0,1,1,
  3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,3,2,2,2,2,3,3,2,2,1,2,2,2,
   0,2,0,0,0,0,2,2,0,0,1,0,0,0,0,2,0,0,1,1,0,1,0,0,0,0,0,0,0,0,1,1,
  3,3,3,3,3,2,3,3,3,3,3,3,3,3,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,3,2,
   0,3,0,0,0,1,2,2,0,0,1,0,0,0,0,2,0,1,1,2,0,2,0,0,0,0,0,0,0,0,2,1,
  0,3,3,3,3,2,0,3,3,3,3,3,3,3,0,3,3,3,3,3,0,3,3,3,0,0,3,0,3,0,1,3,
   0,2,0,0,0,2,2,2,0,0,0,0,0,0,0,3,0,0,0,0,0,2,0,0,0,0,0,0,0,0,1,3,
  3,3,3,3,3,2,3,3,3,3,2,3,3,3,2,3,3,3,3,3,3,2,3,3,3,3,2,2,1,0,2,1,
   0,2,2,0,1,2,2,1,0,0,1,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,1,
  3,3,3,3,3,3,3,3,2,3,3,3,3,2,2,2,3,2,2,2,3,3,3,2,2,2,2,2,2,0,2,2,
   0,1,2,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,3,1,0,1,0,0,0,0,0,0,0,0,1,1,
  3,3,3,3,3,3,3,2,3,2,3,3,3,3,0,3,2,3,2,2,3,2,2,3,3,3,2,2,1,3,2,1,
   0,1,0,0,0,0,2,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,1,
  3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,2,2,1,2,2,
   0,2,0,0,0,0,3,1,0,0,1,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,1,1,
  3,3,2,3,3,3,3,3,3,3,2,3,3,3,3,2,2,3,2,2,2,2,1,3,2,2,2,2,1,3,1,2,
   0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,1,
  3,3,3,1,2,1,2,1,2,3,3,1,1,2,2,3,2,1,2,1,1,1,2,1,1,1,1,1,3,3,0,1,
   0,0,0,0,0,1,1,3,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,3,3,2,3,3,3,3,3,3,2,3,2,2,2,2,3,3,3,2,2,1,1,1,2,2,1,2,1,3,3,2,
   0,1,0,0,0,0,2,2,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
  0,3,3,3,3,1,3,3,3,3,3,2,3,3,0,3,3,3,3,3,3,3,3,2,3,3,3,3,2,0,2,2,
   0,2,1,0,0,0,2,2,0,0,1,0,0,0,0,1,0,1,1,0,0,2,0,0,0,0,1,0,0,0,1,1,
  3,3,3,1,3,2,2,3,3,2,2,3,1,1,2,2,1,2,1,2,1,3,1,1,1,1,1,2,0,3,0,1,
   0,0,2,0,0,0,1,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,
  3,3,3,3,3,1,3,2,3,3,2,3,3,3,1,3,3,3,3,3,3,2,2,2,3,3,2,2,2,2,2,2,
   0,2,0,0,0,0,2,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1,1,
  3,3,3,3,3,1,2,1,2,1,3,2,2,2,3,1,2,2,1,1,2,1,1,2,2,1,1,2,1,3,3,1,
   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
  3,3,3,1,2,1,0,3,3,1,2,3,1,1,1,0,0,3,1,1,0,0,1,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,2,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,2,3,3,3,1,2,1,2,2,2,3,2,2,2,1,1,2,1,2,2,2,1,1,2,2,1,1,1,0,2,1,
   0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,3,0,0,0,0,0,
  0,3,3,3,3,1,0,3,2,2,2,3,3,3,0,3,3,3,3,3,0,1,2,2,0,0,1,0,0,0,3,3,
   0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,
  3,3,3,3,3,1,3,2,2,2,1,1,2,2,3,2,1,2,1,1,2,3,3,2,2,2,1,2,0,3,1,2,
   0,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
  3,1,3,2,3,1,2,2,3,2,3,3,3,2,0,1,3,1,1,1,2,2,1,2,1,1,1,1,1,1,1,0,
   0,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,3,1,1,3,0,1,1,2,1,2,1,2,1,0,1,1,2,1,1,1,1,1,1,1,1,1,1,0,1,1,1,
   0,0,3,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,3,0,3,0,0,0,0,0,2,1,0,0,2,0,1,1,3,3,1,0,3,0,0,0,0,3,0,0,0,0,0,
   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,1,3,2,2,0,0,3,3,3,0,2,3,1,0,2,2,2,2,3,0,1,1,3,0,0,1,0,0,0,1,2,
   0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,
  3,3,1,2,3,1,2,2,2,1,2,2,2,2,1,1,2,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,
   0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
  0,3,3,2,3,0,0,2,1,3,2,3,3,1,0,3,2,3,1,2,0,2,2,1,0,0,1,0,1,0,1,2,
   0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
  3,3,2,2,2,0,2,2,2,1,2,1,2,2,0,1,1,2,1,1,2,2,1,2,2,2,1,1,1,0,1,1,
   0,0,0,0,0,2,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,1,0,
  0,3,3,3,2,2,3,2,2,2,1,3,2,2,0,3,2,2,3,1,3,1,2,2,3,2,1,2,1,0,2,1,
   0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,
  3,2,1,1,2,1,2,2,2,1,1,2,2,1,1,1,2,1,1,1,2,1,1,1,2,1,1,1,1,0,1,0,
   0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
  3,3,1,1,3,2,2,1,1,1,1,2,1,0,1,1,1,2,0,1,1,0,0,0,0,1,1,1,0,0,0,1,
   0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,
   2,0,0,2,2,0,0,0,2,3,0,3,2,3,3,0,2,0,0,0,2,0,1,2,2,1,0,2,2,1,0,0,
  1,2,0,1,0,1,1,1,1,1,2,3,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,1,2,2,1,1,1,1,1,1,1,1,2,2,3,1,1,1,2,1,1,1,1,1,1,1,1,1,1,0,1,1,
   0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
   1,0,0,1,2,0,0,0,1,3,0,3,3,2,3,0,2,0,0,0,2,0,1,1,2,2,0,2,1,1,0,0,
  0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   2,0,0,3,1,0,0,0,3,3,0,2,3,3,2,0,3,0,0,0,2,0,1,1,2,0,0,1,1,0,0,0,
  3,1,1,2,1,0,1,1,1,1,2,0,2,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,
   0,1,3,0,0,1,2,0,0,0,0,0,0,0,0,1,0,2,0,0,0,0,0,0,0,0,1,0,0,0,1,0,
  3,0,2,1,1,0,0,1,0,0,1,0,2,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  3,1,3,1,2,1,1,2,1,1,1,0,1,1,0,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1,0,0,
   0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   2,0,0,1,1,0,0,0,1,3,0,3,2,2,2,0,2,0,0,0,2,0,1,2,2,1,0,2,3,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
   3,0,0,2,2,0,0,0,2,2,0,1,3,2,1,0,2,0,0,0,3,0,1,1,1,1,0,0,1,0,0,0,
  3,1,1,1,1,0,2,1,1,0,0,1,2,1,0,1,1,1,2,1,1,1,1,1,2,1,2,1,1,0,1,1,
   0,0,0,0,0,0,1,0,0,0,3,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   3,0,0,3,3,0,0,0,2,2,0,2,2,2,1,0,2,0,0,0,2,0,1,1,1,2,0,1,1,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   3,0,0,2,3,0,0,0,2,1,0,2,2,2,1,0,1,0,0,0,1,0,3,2,1,2,0,1,1,0,0,0,
  0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   2,0,0,1,2,0,0,0,2,1,0,1,3,2,1,0,2,0,0,0,1,0,2,1,1,1,0,1,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   3,0,0,2,2,0,0,0,2,2,0,0,1,1,2,0,1,0,0,0,1,0,1,1,1,1,0,1,1,0,0,0,
  1,1,3,2,2,0,2,1,1,1,1,2,1,1,0,1,1,2,1,0,1,1,1,1,1,1,1,1,0,0,0,1,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   2,0,0,2,2,0,0,0,2,0,0,1,2,1,1,0,1,0,0,0,0,0,2,1,0,1,0,0,0,0,0,0,
  3,1,1,1,2,0,1,2,1,0,0,0,1,2,0,1,2,1,1,1,1,0,0,0,1,1,0,1,1,0,0,1,
   0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
  0,0,0,3,0,0,0,0,0,2,0,0,1,0,0,1,0,2,2,0,0,1,0,0,0,0,0,0,2,0,1,0,
   0,0,0,0,0,3,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,1,1,0,1,1,1,0,0,0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   2,0,0,2,2,0,0,0,2,0,0,1,0,1,1,0,1,0,0,0,1,0,1,1,1,2,0,0,2,0,0,0,
  2,1,1,0,2,0,2,1,1,1,1,2,1,1,1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   3,0,0,2,2,0,0,0,2,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   1,0,0,1,1,0,0,0,0,2,0,2,2,2,2,0,2,0,0,0,2,0,1,0,1,1,0,1,1,1,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   2,0,0,2,2,0,0,0,2,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,2,0,1,0,0,0,0,
  0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
   1,0,0,1,1,0,0,0,1,1,0,0,1,2,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,
  1,0,1,2,1,0,1,1,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,1,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   2,0,0,2,1,0,0,0,2,0,0,2,1,1,2,0,0,0,0,0,0,0,2,1,1,2,0,1,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   2,0,0,1,2,0,0,0,2,1,0,2,1,0,0,0,0,0,0,0,0,0,0,2,0,1,0,0,2,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   1,0,0,1,1,0,0,0,1,0,0,0,2,0,0,0,2,0,0,0,0,0,1,1,1,1,0,1,1,1,0,0,
  0,1,2,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  2,1,1,0,0,0,0,1,1,1,1,2,0,0,1,0,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,
   0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};


const SequenceModel Tis_620ThaiModel =
{
  Tis_620_CharToOrderMap,
  ThaiLangModel,
  64,
  (float)0.8815720594354438,
  PR_FALSE,
  "TIS-620"
};

const SequenceModel Iso_8859_11ThaiModel =
{
  Iso_8859_11_CharToOrderMap,
  ThaiLangModel,
  64,
  (float)0.8815720594354438,
  PR_FALSE,
  "ISO-8859-11"
};
