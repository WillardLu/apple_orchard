## cmocka测试工具介绍

这里介绍的内容是基于 Ubuntu 22.04 的。

#### 1. 安装方法

使用以下命令安装：

```shell
sudo apt install libcmocka-dev
```

#### 2. C语言代码中的头文件编写

```c
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>
```

这里要注意的是，以上头文件中，前三个标准库的头文件虽然不属于cmocka测试工具，但却是必须的。

#### 3. CMakeLists.txt文件中的配置

```cmake
target_link_libraries(${project_name}
                      cmocka)
```
