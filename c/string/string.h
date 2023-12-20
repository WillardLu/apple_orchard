// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
//
// @version 1.0.0

#ifndef STRING_STRING_H_
#define STRING_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StrReplaceAll(char *str, char *old, char *new, char *ret);
int SubStr(char *str, char *substr, int start, int end);

#endif  // STRING_STRING_H_
