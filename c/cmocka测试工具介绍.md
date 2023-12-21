## cmocka测试工具介绍

cmocka 是一个基于 C 库的测试框架，支持模拟对象、测试夹具、异常处理和不同的输出格式。它可在 Linux、BSD、Windows 和嵌入式平台上运行，并可与各种编译器配合使用。

#### 1. 安装方法

使用以下命令安装：

```shell
sudo apt install libcmocka-dev
```

#### 2. C语言代码中的头文件编写

```c
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
```

这里要注意的是，以上头文件中，前三个标准库的头文件虽然不属于cmocka测试工具，但却是必须的。

#### 3. CMakeLists.txt文件中的配置

```cmake
target_link_libraries(${project_name}
                      cmocka)
```

#### 4. 单元测试

示例代码：

```c
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
```

在这里main主函数中的编写方法基本上是固定的，格式是：

```c
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(测试函数),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
```

测试函数的名称一般是在被函数名称后面加上Test来构成。测试函数的输入输出参数是固定的，即：

```c
static void 函数名(void **state) {
  ...
  return;
}
```

cmocka提供的断言函数有：

- 布尔型

```c
assert_true(x);
assert_false(x);
```

- 整型

```c
assert_int_equal(a, b);
assert_int_not_equal(a, b);
```

- 整形范围

```c
assert_in_range(value, minimum, maximum);
assert_not_in_range(value, minimum, maximum);
```

- 浮点型

```c
assert_float_equal(a, b);
assert_float_not_equal(a, b);
```

- 指针

```c
assert_non_null(x);
assert_null(x);
```

- 返回代码

```c
assert_return_code(rc, errno);
```

- 字符串

```c
assert_string_equal(a, b);
assert_string_not_equal(a, b);
```

- 内存比较

```c
assert_memory_equal(a, b);
assert_memory_not_equal(a, b);
```
