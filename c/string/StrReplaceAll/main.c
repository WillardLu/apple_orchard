// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "str_replace_all.h"

static void StrReplaceAllTest(void **state) {
  char *test[] = {"ffabcffghjff", "abcghjff", ""};
  char *result[] = {"iiiabciiighjiii", "abcghjiii", ""};
  for (int i = 0; i <= 2; i++) {
    char ret[100]= {0};
    if (StrReplaceAll(test[i], "ff", "iii", ret) != 0) {
      printf("StrReplaceAll failed\n");
    } else {
      assert_string_equal(ret, result[i]);
    }
  }
  return;
}

int main(int argc, char *argv[]) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(StrReplaceAllTest),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
