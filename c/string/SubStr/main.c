// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "sub_str.h"

static void SubStrTest(void **state) {
  char substring[10] = {0};
  assert_int_equal(SubStr("abcdefgh", substring, 0, 5), 0);
  assert_int_equal(SubStr("abc", substring, 4, 5), -1);
  assert_int_equal(SubStr("abc", substring, -4, 2), -1);
  assert_int_equal(SubStr("abc234rwerewq", substring, 4, 2), -1);
  return;
}

int main(int argc, char *argv[]) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(SubStrTest),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}