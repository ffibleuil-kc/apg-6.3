/*******************************************************************************
  Version 6.3
  APG - an ABNF Parser Generator
  Copyright (C) 2012 Coast to Coast Research, Inc.
  
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see
  <http://www.gnu.org/licenses/old-licenses/gpl-2.0.html>
  or write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
  
  author:  Lowell D. Thomas
  email:   info@coasttocoastresearch.com
  website: http://www.coasttocoastresearch.com
*******************************************************************************/
#include "Apg.h"
#include "SABNFGrammar.h"

// NOTE 1: Generator's ApgLib version number = "6.3"

// NOTE 2: The Parser's alphabet character (apg_achar) must be large enough to accommodate the grammar's largest character.
//         Grammar's largest alphabet character = 126
//         Parser's sizeof(apg_achar) must be  >= 1
//         Grammar's largest integer(*)         = 4657
//         Parser's sizeof(apg_uint) must be   >= 2
//
//    (*): sizeof(apg_uint) <= 2 should be used with caution and only for extemely small parsers.
//         The largest integer refers only to the grammar's data. Other Parser integer's may,
//         and likely will, have larger requirements. Parser may fail unpredictably.

static unsigned long int ulData[3095] = {
    1, 2, 24760, 9, 126, 4657, 20, 4, 2554, 494, 3048, 47, 24, 173, 197, 68, 0, 0, 741, 
    259, 54, 46, 51, 0, 2, 3, 4, 9, 10, 13, 14, 8, 11, 15, 6, 7, 20, 21, 17, 18, 19, 
    22, 23, 24, 25, 29, 30, 31, 27, 32, 34, 35, 41, 42, 38, 39, 46, 47, 44, 45, 53, 
    54, 50, 51, 56, 57, 58, 59, 61, 62, 64, 65, 67, 68, 70, 71, 72, 73, 74, 75, 76, 
    77, 79, 80, 81, 83, 84, 85, 90, 91, 87, 88, 92, 98, 99, 101, 102, 104, 105, 108, 
    109, 110, 112, 113, 115, 116, 107, 111, 114, 117, 118, 120, 121, 130, 131, 132, 
    133, 135, 136, 137, 138, 140, 141, 142, 143, 129, 134, 139, 127, 128, 152, 153, 
    148, 149, 150, 159, 160, 155, 156, 157, 166, 167, 162, 163, 164, 147, 154, 161, 
    145, 146, 169, 170, 172, 174, 175, 177, 178, 180, 181, 183, 184, 186, 187, 199, 
    200, 202, 203, 205, 206, 219, 220, 221, 224, 225, 228, 229, 230, 231, 223, 226, 
    237, 238, 240, 241, 242, 247, 248, 244, 245, 250, 251, 252, 255, 256, 257, 254, 
    258, 46, 1918, 4, 4, 4, 0, 0, 5, 47, 1962, 9, 9, 9, 1, 5, 11, 48, 2023, 4, 19, 4, 
    2, 16, 10, 49, 2102, 9, 24, 9, 3, 26, 7, 50, 2158, 11, 34, 11, 4, 33, 3, 51, 2198, 
    9, 46, 9, 5, 36, 1, 52, 2228, 11, 56, 11, 6, 37, 6, 53, 2282, 13, 68, 13, 7, 43, 
    5, 54, 2329, 9, 82, 9, 8, 48, 1, 55, 2356, 11, 92, 11, 9, 49, 6, 56, 2404, 10, 104, 
    10, 10, 55, 5, 57, 2446, 3, 115, 3, 11, 60, 3, 58, 2476, 3, 119, 3, 12, 63, 3, 59, 
    2506, 3, 123, 3, 13, 66, 3, 60, 2536, 7, 127, 7, 14, 69, 9, 68, 2741, 5, 135, 5, 
    15, 78, 4, 69, 2784, 6, 141, 6, 16, 82, 4, 70, 2828, 7, 148, 7, 17, 86, 7, 71, 2874, 
    9, 156, 9, 18, 93, 1, 72, 2895, 6, 166, 6, 19, 94, 1, 74, 2920, 8, 173, 8, 20, 95, 
    1, 75, 2945, 5, 182, 5, 21, 96, 1, 76, 2970, 5, 188, 5, 22, 97, 3, 77, 3012, 13, 
    194, 13, 23, 100, 3, 78, 3046, 9, 208, 9, 24, 103, 3, 79, 3080, 5, 218, 5, 25, 106, 
    13, 84, 3281, 5, 224, 5, 26, 119, 3, 85, 3307, 5, 230, 5, 27, 122, 1, 86, 3327, 
    6, 236, 6, 28, 123, 1, 87, 3348, 5, 243, 5, 29, 124, 1, 88, 3369, 5, 249, 5, 30, 
    125, 1, 89, 3390, 5, 255, 5, 31, 126, 18, 90, 3480, 5, 261, 5, 32, 144, 24, 91, 
    3597, 5, 267, 5, 33, 168, 5, 92, 3632, 7, 273, 7, 34, 173, 3, 94, 3684, 6, 281, 
    6, 35, 176, 3, 95, 3710, 6, 288, 6, 36, 179, 3, 96, 3736, 7, 295, 7, 37, 182, 3, 
    97, 3762, 7, 303, 7, 38, 185, 3, 98, 3788, 7, 311, 7, 39, 188, 1, 99, 3812, 11, 
    319, 11, 40, 189, 1, 100, 3836, 7, 331, 7, 41, 190, 1, 101, 3860, 7, 339, 7, 42, 
    191, 2, 102, 3888, 4, 347, 4, 43, 193, 1, 103, 3909, 4, 352, 4, 44, 194, 1, 104, 
    3930, 7, 357, 7, 45, 195, 1, 105, 3951, 7, 365, 7, 46, 196, 1, 106, 3972, 7, 373, 
    7, 47, 197, 1, 107, 3993, 3, 381, 3, 48, 198, 3, 108, 4022, 3, 385, 3, 49, 201, 
    3, 109, 4051, 3, 389, 3, 50, 204, 3, 110, 4079, 4, 393, 4, 51, 207, 1, 111, 4100, 
    4, 398, 4, 52, 208, 1, 112, 4121, 4, 403, 4, 53, 209, 1, 113, 4142, 4, 408, 4, 54, 
    210, 1, 114, 4163, 4, 413, 4, 55, 211, 1, 115, 4184, 4, 418, 4, 56, 212, 1, 116, 
    4205, 4, 423, 4, 57, 213, 2, 117, 4233, 4, 428, 4, 58, 215, 2, 118, 4259, 4, 433, 
    4, 59, 217, 5, 121, 4318, 8, 438, 8, 60, 222, 10, 122, 4386, 4, 447, 4, 61, 232, 
    2, 123, 4409, 3, 452, 3, 62, 234, 2, 124, 4433, 2, 456, 2, 63, 236, 3, 125, 4460, 
    5, 459, 5, 64, 239, 4, 128, 4541, 7, 465, 7, 65, 243, 6, 129, 4579, 7, 473, 7, 66, 
    249, 4, 130, 4617, 12, 481, 12, 67, 253, 6, 30, 46, 1934, 27, 1, 0, -1, 40, 46, 
    1936, 24, 0, 3, 0, 10, 46, 1936, 9, -1, 1, 0, 10, 46, 1946, 4, -1, 2, 0, 10, 46, 
    1951, 9, -1, 3, 0, 40, 47, 1978, 44, 10, 2, 0, 10, 47, 1978, 7, -1, 66, 0, 41, 47, 
    1988, 34, 7, 3, 0, 40, 47, 1989, 7, 3, 2, 0, 80, 47, 1989, 4, 0, 1, 0, 10, 47, 1994, 
    2, -1, 63, 0, 30, 47, 1998, 16, 12, 0, -1, 40, 47, 2000, 13, 5, 2, 0, 10, 47, 2000, 
    2, -1, 63, 0, 90, 47, 2005, 8, 33, 126, 0, 10, 47, 2015, 7, -1, 66, 0, 41, 48, 2039, 
    62, 14, 7, 0, 10, 48, 2039, 8, -1, 20, 0, 10, 48, 2048, 4, -1, 61, 0, 40, 48, 2054, 
    16, 12, 2, 0, 10, 48, 2054, 6, -1, 19, 0, 10, 48, 2061, 9, -1, 18, 0, 10, 48, 2072, 
    4, -1, 61, 0, 10, 48, 2077, 11, -1, 4, 0, 10, 48, 2089, 4, -1, 61, 0, 10, 48, 2094, 
    7, -1, 66, 0, 41, 49, 2118, 39, 24, 2, 0, 30, 49, 2118, 31, 28, 0, -1, 40, 49, 2120, 
    28, 21, 3, 0, 10, 49, 2120, 2, -1, 63, 0, 90, 49, 2125, 8, 33, 126, 0, 10, 49, 2136, 
    12, -1, 67, 0, 10, 49, 2150, 7, -1, 66, 0, 40, 50, 2174, 23, 26, 2, 0, 10, 50, 2174, 
    11, -1, 6, 0, 10, 50, 2188, 9, -1, 5, 0, 10, 51, 2214, 13, -1, 7, 0, 41, 52, 2244, 
    37, 30, 2, 0, 10, 52, 2244, 13, -1, 7, 0, 30, 52, 2258, 23, 40, 1, -1, 41, 52, 2261, 
    19, 28, 2, 0, 10, 52, 2261, 5, -1, 26, 0, 10, 52, 2267, 13, -1, 7, 0, 41, 53, 2298, 
    30, 34, 2, 0, 10, 53, 2298, 4, -1, 61, 0, 40, 53, 2304, 23, 32, 2, 0, 10, 53, 2304, 
    11, -1, 9, 0, 10, 53, 2318, 9, -1, 8, 0, 10, 54, 2345, 10, -1, 10, 0, 41, 55, 2372, 
    31, 38, 2, 0, 10, 55, 2372, 10, -1, 10, 0, 30, 55, 2383, 20, 52, 1, -1, 41, 55, 
    2386, 16, 36, 2, 0, 10, 55, 2386, 5, -1, 27, 0, 10, 55, 2392, 10, -1, 10, 0, 40, 
    56, 2420, 25, 40, 4, 0, 10, 56, 2420, 3, -1, 11, 0, 10, 56, 2426, 3, -1, 12, 0, 
    10, 56, 2432, 3, -1, 13, 0, 10, 56, 2438, 7, -1, 14, 0, 41, 57, 2462, 13, 44, 2, 
    0, 10, 57, 2462, 5, -1, 25, 0, 10, 57, 2468, 7, -1, 14, 0, 41, 58, 2492, 13, 46, 
    2, 0, 10, 58, 2492, 5, -1, 29, 0, 10, 58, 2498, 7, -1, 14, 0, 41, 59, 2522, 13, 
    48, 2, 0, 10, 59, 2522, 5, -1, 30, 0, 10, 59, 2528, 7, -1, 14, 0, 40, 60, 2552, 
    188, 50, 8, 0, 10, 60, 2552, 5, -1, 31, 0, 10, 61, 2578, 5, -1, 32, 0, 10, 62, 2604, 
    5, -1, 33, 0, 10, 63, 2630, 5, -1, 22, 0, 10, 64, 2655, 5, -1, 21, 0, 10, 65, 2681, 
    5, -1, 15, 0, 10, 66, 2707, 6, -1, 16, 0, 10, 67, 2733, 7, -1, 17, 0, 41, 68, 2757, 
    26, 58, 3, 0, 10, 68, 2757, 6, -1, 35, 0, 10, 68, 2765, 11, -1, 4, 0, 10, 68, 2777, 
    6, -1, 36, 0, 41, 69, 2800, 27, 61, 3, 0, 10, 69, 2800, 7, -1, 37, 0, 10, 69, 2808, 
    11, -1, 4, 0, 10, 69, 2820, 7, -1, 38, 0, 41, 70, 2844, 29, 66, 3, 0, 80, 70, 2844, 
    4, 1, 1, 0, 30, 70, 2849, 19, 89, 0, -1, 40, 70, 2851, 16, 64, 2, 0, 90, 70, 2851, 
    7, 32, 61, 0, 90, 70, 2859, 8, 63, 126, 0, 80, 70, 2869, 4, 2, 1, 0, 80, 71, 2890, 
    4, 3, 1, 0, 80, 72, 2911, 7, 4, 2, 0, 10, 74, 2936, 8, -1, 60, 0, 10, 75, 2961, 
    8, -1, 60, 0, 40, 76, 2986, 25, 69, 2, 0, 10, 76, 2986, 9, -1, 24, 0, 10, 76, 2998, 
    13, -1, 23, 0, 41, 77, 3028, 17, 71, 2, 0, 80, 77, 3028, 8, 6, 2, 0, 10, 77, 3037, 
    8, -1, 60, 0, 41, 78, 3062, 17, 73, 2, 0, 80, 78, 3062, 8, 8, 2, 0, 10, 78, 3071, 
    8, -1, 60, 0, 40, 79, 3096, 184, 82, 5, 0, 41, 79, 3097, 22, 75, 3, 0, 10, 79, 3097, 
    7, -1, 39, 0, 10, 79, 3105, 6, -1, 28, 0, 10, 79, 3112, 7, -1, 41, 0, 41, 80, 3140, 
    14, 78, 2, 0, 10, 80, 3140, 7, -1, 39, 0, 10, 80, 3148, 6, -1, 28, 0, 41, 81, 3183, 
    14, 80, 2, 0, 10, 81, 3183, 6, -1, 28, 0, 10, 81, 3190, 7, -1, 41, 0, 10, 82, 3226, 
    6, -1, 28, 0, 10, 83, 3269, 11, -1, 40, 0, 41, 84, 3297, 9, 87, 2, 0, 10, 84, 3297, 
    4, -1, 61, 0, 80, 84, 3302, 4, 10, 1, 0, 10, 85, 3323, 3, -1, 62, 0, 80, 86, 3343, 
    4, 11, 1, 0, 80, 87, 3364, 4, 12, 1, 0, 80, 88, 3385, 4, 13, 1, 0, 41, 89, 3406, 
    73, 104, 2, 0, 80, 89, 3406, 4, 14, 1, 0, 40, 89, 3412, 66, 101, 3, 0, 41, 89, 3413, 
    18, 89, 4, 0, 10, 89, 3413, 3, -1, 48, 0, 10, 89, 3417, 4, -1, 51, 0, 80, 89, 3422, 
    4, 15, 1, 0, 10, 89, 3427, 4, -1, 52, 0, 41, 89, 3436, 18, 93, 4, 0, 10, 89, 3436, 
    3, -1, 49, 0, 10, 89, 3440, 4, -1, 55, 0, 80, 89, 3445, 4, 16, 1, 0, 10, 89, 3450, 
    4, -1, 56, 0, 41, 89, 3459, 18, 97, 4, 0, 10, 89, 3459, 3, -1, 50, 0, 10, 89, 3463, 
    4, -1, 53, 0, 80, 89, 3468, 4, 17, 1, 0, 10, 89, 3473, 4, -1, 54, 0, 41, 90, 3496, 
    100, 124, 2, 0, 80, 90, 3496, 4, 18, 1, 0, 40, 90, 3502, 93, 121, 3, 0, 41, 90, 
    3503, 27, 108, 3, 0, 10, 90, 3503, 3, -1, 48, 0, 10, 90, 3507, 7, -1, 45, 0, 30, 
    90, 3515, 15, 151, 0, -1, 41, 90, 3517, 12, 106, 2, 0, 80, 90, 3517, 4, 19, 1, 0, 
    10, 90, 3522, 7, -1, 45, 0, 41, 90, 3535, 27, 113, 3, 0, 10, 90, 3535, 3, -1, 49, 
    0, 10, 90, 3539, 7, -1, 46, 0, 30, 90, 3547, 15, 158, 0, -1, 41, 90, 3549, 12, 111, 
    2, 0, 80, 90, 3549, 4, 20, 1, 0, 10, 90, 3554, 7, -1, 46, 0, 41, 90, 3567, 27, 118, 
    3, 0, 10, 90, 3567, 3, -1, 50, 0, 10, 90, 3571, 7, -1, 47, 0, 30, 90, 3579, 15, 
    165, 0, -1, 41, 90, 3581, 12, 116, 2, 0, 80, 90, 3581, 4, 21, 1, 0, 10, 90, 3586, 
    7, -1, 47, 0, 41, 91, 3613, 18, 126, 3, 0, 10, 91, 3613, 4, -1, 43, 0, 30, 91, 3618, 
    8, 171, 0, -1, 10, 91, 3619, 7, -1, 34, 0, 10, 91, 3627, 4, -1, 44, 0, 40, 92, 3648, 
    16, 129, 2, 0, 90, 92, 3648, 7, 32, 33, 0, 90, 92, 3656, 8, 35, 126, 0, 41, 94, 
    3700, 9, 131, 2, 0, 80, 94, 3700, 4, 22, 1, 0, 10, 94, 3705, 4, -1, 61, 0, 41, 95, 
    3726, 9, 133, 2, 0, 10, 95, 3726, 4, -1, 61, 0, 80, 95, 3731, 4, 23, 1, 0, 41, 96, 
    3752, 9, 135, 2, 0, 80, 96, 3752, 4, 24, 1, 0, 10, 96, 3757, 4, -1, 61, 0, 41, 97, 
    3778, 9, 137, 2, 0, 10, 97, 3778, 4, -1, 61, 0, 80, 97, 3783, 4, 25, 1, 0, 10, 98, 
    3804, 7, -1, 42, 0, 10, 99, 3828, 7, -1, 42, 0, 10, 100, 3852, 7, -1, 42, 0, 30, 
    101, 3876, 11, 192, 1, -1, 90, 101, 3879, 7, 48, 57, 0, 80, 102, 3904, 4, 26, 1, 
    0, 80, 103, 3925, 4, 27, 1, 0, 10, 104, 3946, 4, -1, 57, 0, 10, 105, 3967, 4, -1, 
    59, 0, 10, 106, 3988, 4, -1, 58, 0, 40, 107, 4010, 10, 139, 2, 0, 80, 107, 4010, 
    4, 28, 1, 0, 80, 107, 4015, 5, 29, 1, 0, 40, 108, 4039, 10, 141, 2, 0, 80, 108, 
    4039, 4, 30, 1, 0, 80, 108, 4044, 5, 31, 1, 0, 40, 109, 4068, 9, 143, 2, 0, 80, 
    109, 4068, 4, 32, 1, 0, 80, 109, 4073, 4, 33, 1, 0, 10, 110, 4095, 4, -1, 57, 0, 
    10, 111, 4116, 4, -1, 57, 0, 10, 112, 4137, 4, -1, 58, 0, 10, 113, 4158, 4, -1, 
    58, 0, 10, 114, 4179, 4, -1, 59, 0, 10, 115, 4200, 4, -1, 59, 0, 30, 116, 4221, 
    11, 214, 1, -1, 90, 116, 4224, 7, 48, 57, 0, 30, 117, 4249, 9, 216, 1, -1, 90, 117, 
    4251, 7, 48, 49, 0, 30, 118, 4275, 32, 218, 1, -1, 40, 118, 4278, 28, 145, 3, 0, 
    90, 118, 4278, 7, 48, 57, 0, 90, 118, 4288, 7, 65, 70, 0, 90, 118, 4298, 8, 97, 
    102, 0, 41, 121, 4334, 51, 154, 2, 0, 40, 121, 4335, 16, 148, 2, 0, 90, 121, 4335, 
    8, 97, 122, 0, 90, 121, 4344, 7, 65, 90, 0, 30, 121, 4353, 32, 227, 0, -1, 40, 121, 
    4355, 29, 150, 4, 0, 90, 121, 4355, 8, 97, 122, 0, 90, 121, 4364, 7, 65, 90, 0, 
    90, 121, 4372, 7, 48, 57, 0, 80, 121, 4380, 4, 34, 1, 0, 30, 122, 4402, 6, 233, 
    0, -1, 10, 122, 4403, 5, -1, 64, 0, 30, 123, 4425, 7, 235, 1, -1, 10, 123, 4427, 
    5, -1, 64, 0, 40, 124, 4449, 10, 156, 2, 0, 80, 124, 4449, 3, 35, 1, 0, 80, 124, 
    4455, 4, 36, 1, 0, 40, 125, 4476, 64, 158, 3, 0, 10, 125, 4476, 2, -1, 63, 0, 10, 
    126, 4502, 7, -1, 65, 0, 10, 127, 4528, 12, -1, 67, 0, 41, 128, 4557, 21, 163, 2, 
    0, 80, 128, 4557, 4, 37, 1, 0, 30, 128, 4562, 16, 246, 0, -1, 40, 128, 4564, 13, 
    161, 2, 0, 10, 128, 4564, 2, -1, 63, 0, 90, 128, 4569, 8, 33, 126, 0, 40, 129, 4595, 
    21, 165, 3, 0, 80, 129, 4595, 7, 38, 2, 0, 80, 129, 4605, 4, 40, 1, 0, 80, 129, 
    4612, 4, 41, 1, 0, 41, 130, 4633, 28, 171, 2, 0, 40, 130, 4634, 21, 168, 3, 0, 80, 
    130, 4634, 7, 42, 2, 0, 80, 130, 4644, 4, 44, 1, 0, 80, 130, 4651, 4, 45, 1, 0, 
    80, 130, 4657, 4, 46, 1, 0, 54, 46, 51, 0, 70, 105, 108, 101, 0, 66, 108, 97, 110, 
    107, 76, 105, 110, 101, 0, 82, 117, 108, 101, 0, 82, 117, 108, 101, 69, 114, 114, 
    111, 114, 0, 65, 108, 116, 101, 114, 110, 97, 116, 105, 111, 110, 0, 83, 105, 110, 
    103, 108, 101, 65, 108, 116, 0, 77, 117, 108, 116, 105, 112, 108, 101, 65, 108, 
    116, 0, 67, 111, 110, 99, 97, 116, 101, 110, 97, 116, 105, 111, 110, 0, 83, 105, 
    110, 103, 108, 101, 67, 97, 116, 0, 77, 117, 108, 116, 105, 112, 108, 101, 67, 97, 
    116, 0, 82, 101, 112, 101, 116, 105, 116, 105, 111, 110, 0, 82, 101, 112, 0, 65, 
    110, 100, 0, 78, 111, 116, 0, 69, 108, 101, 109, 101, 110, 116, 0, 71, 114, 111, 
    117, 112, 0, 79, 112, 116, 105, 111, 110, 0, 80, 114, 111, 115, 86, 97, 108, 0, 
    68, 101, 102, 105, 110, 101, 100, 65, 115, 0, 73, 110, 99, 65, 108, 116, 0, 82, 
    117, 108, 101, 78, 97, 109, 101, 0, 82, 110, 109, 79, 112, 0, 85, 100, 116, 79, 
    112, 0, 117, 100, 116, 45, 110, 111, 110, 45, 101, 109, 112, 116, 121, 0, 117, 100, 
    116, 45, 101, 109, 112, 116, 121, 0, 82, 101, 112, 79, 112, 0, 65, 108, 116, 79, 
    112, 0, 67, 97, 116, 79, 112, 0, 83, 116, 97, 114, 79, 112, 0, 65, 110, 100, 79, 
    112, 0, 78, 111, 116, 79, 112, 0, 84, 114, 103, 79, 112, 0, 84, 98, 115, 79, 112, 
    0, 84, 108, 115, 79, 112, 0, 84, 108, 115, 67, 104, 97, 114, 0, 76, 112, 97, 114, 
    101, 110, 0, 82, 112, 97, 114, 101, 110, 0, 76, 111, 112, 116, 105, 111, 110, 0, 
    82, 111, 112, 116, 105, 111, 110, 0, 114, 101, 112, 45, 109, 105, 110, 0, 114, 101, 
    112, 45, 109, 105, 110, 45, 109, 97, 120, 0, 114, 101, 112, 45, 109, 97, 120, 0, 
    114, 101, 112, 45, 110, 117, 109, 0, 76, 116, 108, 115, 0, 82, 116, 108, 115, 0, 
    100, 83, 116, 114, 105, 110, 103, 0, 120, 83, 116, 114, 105, 110, 103, 0, 98, 83, 
    116, 114, 105, 110, 103, 0, 68, 101, 99, 0, 72, 101, 120, 0, 66, 105, 110, 0, 100, 
    109, 105, 110, 0, 100, 109, 97, 120, 0, 98, 109, 105, 110, 0, 98, 109, 97, 120, 
    0, 120, 109, 105, 110, 0, 120, 109, 97, 120, 0, 100, 110, 117, 109, 0, 98, 110, 
    117, 109, 0, 120, 110, 117, 109, 0, 97, 108, 112, 104, 97, 110, 117, 109, 0, 111, 
    119, 115, 112, 0, 119, 115, 112, 0, 115, 112, 0, 115, 112, 97, 99, 101, 0, 99, 111, 
    109, 109, 101, 110, 116, 0, 76, 105, 110, 101, 69, 110, 100, 0, 76, 105, 110, 101, 
    67, 111, 110, 116, 105, 110, 117, 101, 0, 59, 60, 62, 61, 61, 47, 117, 95, 101, 
    95, 47, 42, 38, 33, 37, 45, 45, 45, 37, 46, 46, 46, 40, 41, 91, 93, 34, 34, 68, 
    100, 88, 120, 66, 98, 45, 9, 32, 59, 13, 10, 10, 13, 13, 10, 10, 13, 32
};

// Parser initialization data
void* vpParserInit_SABNFGrammar = (void*)&ulData[0];
