// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>  // 必须放在以上头文件的后面

#include "ao_string.h"

static void AOStrCpyTest(void **state) {
  char str[20] = {0};
  int len = *(&str + 1) - str;
  char t_str1[20] = {0};
  for (int i = 0; i < 19; i++) {
    t_str1[i] = 'a';
  }
  char t_str2[30] = {0};
  for (int i = 0; i < 29; i++) {
    t_str2[i] = 'b';
  }
  // 普通测试
  assert_int_equal(AOStrCpy(str, len, "海上升明月"), 0);
  // 边界测试：空值
  assert_int_equal(AOStrCpy(str, len, ""), 0);
  // 边界测试：最大值
  assert_int_equal(AOStrCpy(str, len, t_str1), 0);
  // 失效性测试
  assert_int_equal(AOStrCpy(str, len, t_str2), -1);
  return;
}

static void AOStrCatTest(void **state) {
  char str[40] = {0};
  int len = *(&str + 1) - str;
  char t_str1[40] = {0};
  for (int i = 0; i < 39; i++) {
    t_str1[i] = 'a';
  }
  // 普通测试
  assert_int_equal(AOStrCat(str, len, "海上升明月 ", "天涯共此时"), 0);
  // 边界测试：空值
  assert_int_equal(AOStrCat(str, len, "", ""), 0);
  // 边界测试：最大值
  assert_int_equal(AOStrCat(str, len, "", t_str1), 0);
  // 失效性测试
  assert_int_equal(AOStrCat(str, len, "hello world dfsasaas", t_str1), -1);
  return;
}

int main(int argc, char *argv[]) {
  const struct CMUnitTest test1[] = {
      cmocka_unit_test(AOStrCpyTest),
  };
  const struct CMUnitTest test2[] = {
      cmocka_unit_test(AOStrCatTest),
  };
  printf("\nTest the AOStrCpy() function...\n");
  cmocka_run_group_tests(test1, NULL, NULL);
  printf("\nTest the AOStrCat() function...\n");
  cmocka_run_group_tests(test2, NULL, NULL);
  return 0;
}
