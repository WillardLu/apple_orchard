/// @copyright Copyright 2023 Willard Lu
///
/// Use of this source code is governed by an MIT-style
/// license that can be found in the LICENSE file or at
/// https://opensource.org/licenses/MIT.
///
/// @version 1.0.0

#include "sub_str.h"

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