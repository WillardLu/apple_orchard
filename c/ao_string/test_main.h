// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#ifndef AO_STRING_TEST_MAIN_H_
#define AO_STRING_TEST_MAIN_H_

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <cmocka.h>  // 必须放在以上头文件的后面

// 包含一个字符串的测试用数据结构
struct OneStringTestData {
  const char *str;
  int result;
};

// 包含两个字符串的测试用数据结构
struct TwoStringTestData {
  const char *str1;
  const char *str2;
  int result;
};

#endif  // AO_STRING_TEST_MAIN_H_