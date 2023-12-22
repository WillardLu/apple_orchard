// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "test_main.h"

#include "ao_string.h"

static void AOStrCpyTest(void **state) {
  // 测试数据
  struct OneStringTestData TestData[5] = {
      {"海上升明月", 0},
      {"", 0},
      {"1234567890123456789", 0},
      {"12345678901234567890123456", -1},
      {NULL, -1},
  };
  char str[20] = {0};
  int result = 0;
  for (int i = 0; i < 5; i++) {
    result = AOStrCpy(str, 20, TestData[i].str);
    assert_int_equal(result, TestData[i].result);
  }
  return;
}

static void AOStrCatTest(void **state) {
  // 测试数据
  struct TwoStringTestData TestData[5] = {
      {"海上升明月", "天涯共此时", 0},
      {"", "", 0},
      {"", "123456789012345678901234567890123456789", 0},
      {"hello world dfsasaas", "123456789012345678901234567890123456789", -1},
      {NULL, NULL, -1}};
  char str[40] = {0};
  int result = 0;
  for (int i = 0; i < 5; i++) {
    result = AOStrCat(str, 40, TestData[i].str1, TestData[i].str2);
    assert_int_equal(result, TestData[i].result);
  }
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
