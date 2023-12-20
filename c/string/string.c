/// @copyright Copyright 2023 Willard Lu
///
/// Use of this source code is governed by an MIT-style
/// license that can be found in the LICENSE file or at
/// https://opensource.org/licenses/MIT.
///
/// @version 1.0.0

#include "string.h"

/// @brief 替换所有指定字符
/// @param raw 原始字符串
/// @param old 被替换的字符串
/// @param new 用于替换的字符串
/// @param ret 替换后的字符串
/// @return 成功：0，失败：-1
int StrReplaceAll(char *raw, char *old, char *new, char *ret) {
  if (raw == NULL || old == NULL || new == NULL || ret == NULL) {
    printf("StrReplaceAll(): invalid argument!\n");
    return -1;
  }
  char *str1 = raw;  // 用于字符串的中转
  char *str2 = raw;  // 用于字符串的中转
  // 设置有限的循环来逐步匹配处理
  for (int i = 0; i < strlen(raw); i++) {
    str1 = strstr(str1, old);  // 匹配要被替换的字符串
    // 如果没有找到匹配内容，就进行收尾处理
    if (str1 == NULL) {
      strncat(ret, str2, strlen(str2));  // 把剩下的内容全部追加到ret
      return 0;
    }
    strncat(ret, str2, str1 - str2);  // 把匹配内容前面的内容追加到ret
    strncat(ret, new, strlen(new));  // 把用于替换的字符追加到ret
    str1 += strlen(old);  // 跳过要被替换的字符串
    str2 = str1;
  }
  return 0;
}

/// @brief 通过指定起始和结束位置（包含结束位置）提取子字符串
/// @param str 原始字符串
/// @param substr 提取的子字符串
/// @param start 起始位置
/// @param end 结束位置
/// @return 成功：0，失败：-1
int SubStr(char *str, char *substr, int start, int end) {
  if (substr == NULL || str == NULL ||
      start < 0 || end >= strlen(str) || start > end) {
    return -1;
  }
  char *temp = str + start;
  if (strncpy(substr, temp, end - start + 1) != substr) {
    return -1;
  }
  substr[end - start + 1] = '\0';
  return 0;
}
