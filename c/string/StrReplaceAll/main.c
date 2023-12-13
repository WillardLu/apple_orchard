// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <cmocka.h>

#include "str_replace_all.h"

static void StrReplaceAllTest(void **state) {
  char *str1 = NULL;
  char *str2 = NULL;
  str1 = StrReplaceAll("ffabcffghjff", "ff", "f");
  str2 = StrReplaceAll("abcghjf", "ff", "f");
  //printf("%s\n", str1);
  if (str1 != NULL && str2 != NULL) {
    assert_string_equal(str1, "fabcfghjf");
    assert_string_equal(str2, "abcghjf");
  }
  free(str1);
  free(str2);
  
  return;
}

int main(int argc, char *argv[]) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(StrReplaceAllTest),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
