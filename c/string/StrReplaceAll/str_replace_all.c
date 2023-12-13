// @copyright Copyright 2023 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
//
// @version 1.0.0

#include "str_replace_all.h"

/// @brief 替换所有指定字符
/// @param raw 原始字符串
/// @param old 被替换的字符串
/// @param new 用于替换的字符串
/// @return 替换后的字符串
/// @warning 返回内容存放在函数内部动态申请的空间，因此需要在调用本函数后自行释放空间。
char * StrReplaceAll(char *raw, char *old, char *new) {
  int raw_len = strlen(raw); // 原始字符串长度
  int old_len = strlen(old); // 被替换的字符串长度
  int new_len = strlen(new); // 用于替换的字符串长度
  // 计算替换后的字符串可能达到的最大长度
  int max_len = (new_len > old_len ? new_len / old_len + 1 : 1) * raw_len + 1;
  // 定义并分配空间给替换后的字符串
  char *ret = (char *)calloc(max_len, sizeof(char));
  if (ret == NULL) {
    printf("StrReplaceAll(): memory allocation failed!\n");
    return NULL;
  }
  char *str1 = raw;  // 用于字符串的中转
  char *str2 = raw;  // 用于字符串的中转
  int copy_len = 0;  // 用于保存复制字符串的长度
  // 设置有限的循环来逐步匹配处理
  for (int i = 0; i < raw_len; i++) {
    // 匹配要被替换的字符串
    str1 = strstr(str1, old);
    // 如果没有找到匹配内容，就进行收尾处理
    if (str1 == NULL) {
      // 把剩下的内容全部追加到ret
      strncat(ret, str2, strlen(str2));
      return ret;
    }
    copy_len = str1 - str2;
    // 把匹配内容前面的内容追加到ret
    strncat(ret, str2, copy_len);
    // 把用于替换的字符追加到ret
    strncat(ret, new, new_len);
    // 跳过要被替换的字符串
    str1 += old_len;
    str2 = str1;
  }
  return ret;
}