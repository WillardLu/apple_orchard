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
  char *test[] = {"ffabcffghjff", "abcghjff", ""};
  char *result[] = {"iiiabciiighjiii", "abcghjiii", ""};
  for (int i = 0; i < 3; i++) {
    str1 = StrReplaceAll(test[i], "ff", "iii");
    assert_string_equal(str1, result[i]);
    free(str1);
    str1 = NULL;
  }
  
  return;
}

int main(int argc, char *argv[]) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(StrReplaceAllTest),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
