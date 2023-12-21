/// @copyright Copyright 2023 Willard Lu
///
/// Use of this source code is governed by an MIT-style
/// license that can be found in the LICENSE file or at
/// https://opensource.org/licenses/MIT.

#include "ao_string.h"

/// @brief 复制字符串
/// @param dest 目标字符串
/// @param dest_size 目标字符串缓冲区大小
/// @param src 源字符串
/// @return 成功：0，失败：-1
int AOStrCpy(char *dest, size_t dest_size, const char *src) {
  if (dest == NULL || src == NULL) {
    printf("AOStrCpy: Invalid argument.\n");
    return -1;
  }
  if (strlen(src) > dest_size - 1) {
    printf("AOStrCpy: Destination buffer is too small.\n");
    return -1;
  }
  for (int i = 0; i < strlen(src); i++) {
    dest[i] = src[i];
  }
  dest[strlen(src)] = '\0';
  return 0;
}

/// @brief 连接字符串
/// @param dest 目标字符串
/// @param dest_size 目标字符串缓冲区大小
/// @param left_src 左边的字符串
/// @param right_src 右边的字符串
/// @return 成功：0，失败：-1
int AOStrCat(char *dest, size_t dest_size, const char *left_src,
             const char *right_src) {
  if (dest == NULL || left_src == NULL || right_src == NULL) {
    printf("AOStrCat: Invalid argument.\n");
    return -1;
  }
  if (strlen(left_src) + strlen(right_src) > dest_size - 1) {
    printf("AOStrCat: Destination buffer is too small.\n");
    return -1;
  }
  if (AOStrCpy(dest, dest_size, left_src) == -1) {
    return -1;
  }
  if (AOStrCpy(dest + strlen(left_src), dest_size, right_src) == -1) {
    return -1;
  }
  return 0;
}

/*
/// @brief 替换所有指定字符
/// @param raw 原始字符串
/// @param old 被替换的字符串
/// @param new 用于替换的字符串
/// @param ret 替换后的字符串
/// @return 成功：0，失败：-1
int StrReplaceAll(char *raw, char *old, char *new, char *ret)
{
  if (raw == NULL || old == NULL || new == NULL || ret == NULL)
  {
    printf("StrReplaceAll(): invalid argument!\n");
    return -1;
  }
  char *str1 = raw; // 用于字符串的中转
  char *str2 = raw; // 用于字符串的中转
  // 设置有限的循环来逐步匹配处理
  for (int i = 0; i < strlen(raw); i++)
  {
    str1 = strstr(str1, old); // 匹配要被替换的字符串
    // 如果没有找到匹配内容，就进行收尾处理
    if (str1 == NULL)
    {
      // 把剩下的内容（即str2）全部追加到ret
      int error = strncat_s(ret, strlen(ret), str2, strlen(str2));
      if (error != 0)
      {
        printf("strncat_s() failed!\n");
        return -1;
      }
      return 0;
    }
    strncat(ret, str2, str1 - str2); // 把匹配内容前面的内容追加到ret
    strncat(ret, new, strlen(new));  // 把用于替换的字符追加到ret
    str1 += strlen(old);             // 跳过要被替换的字符串
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
int SubStr(char *str, char *substr, int start, int end)
{
  if (substr == NULL || str == NULL || start < 0 || end >= strlen(str) ||
      start > end)
  {
    return -1;
  }
  char *temp = str + start;
  if (strncpy(substr, temp, end - start + 1) != substr)
  {
    return -1;
  }
  substr[end - start + 1] = '\0';
  return 0;
}
*/