# Zilch Editor代码编写规范 v3.1
## C++代码编写样式规定
### 备注
1. 本规定包含C代码编写规范.

### 标准
1. 所有的C代码使用C11标准(参考ISO/IEC 9899:2011).
1. 所有的C++代码使用C++17标准(参考ISO/IEC 14882:2017).
1. 在必要的时候, 仅允许在单独的源文件中独立使用以下实验性规范:  
库基础v2 TS(参考ISO/IEC TS 19568:2017)  
并发 TS(参考ISO/IEC TS 19571:2016)
事务性内存 TS(参考ISO/IEC TS 19841:2015)

### 文件
1. 所有的C源文件扩展名为```*.c```.
1. 所有的C头文件扩展名为```*.h```.
1. 所有的C++源文件扩展名为```*.cpp```.
1. 实现全部都在头文件内的C++头文件扩展名为```*.hpp```.
1. 其他实现有在源文件内的C++头文件扩展名为```*.h```.
1. 一个```*.h```头文件必须有一个对应的同名的源文件提供实现(如果需要的话).

### 编译
1. 确保所有的源文件都可以在GCC/G++, MSVC/MSVC++, Clang的最新的稳定版(或受到长期支持的LTS版)中编译通过.
1. 编译时必须使用编译选项将警告视为错误, 且将错误等级设为最高.

### 命名规范
1. 文件名遵循大驼峰命名法. 所有单词首字母大写, 并依次连接. 其中用以定义类的文件的文件名以类名命名. 例如文件```SampleHeader.h```, 定义了SampleClass类的头文件为```SampleClass.h```.
1. 局部变量, 自动变量, 局部常变量, 全局变量, 成员变量, 函数参数的命名遵循小写下划线命名法. 以单词为单位用下划线连接, 且所有字母为小写, 独立的连续数字作为单独的一个单词.
    ```cpp
    int global_variable;
    int variable_15;
    ```
1. 全局常变量, 编译时常量, 宏常量, 枚举常量的命名使用大写下划线命名法. 以单词为单位用下划线连接, 且所有字母大写, 独立的连续数字作为单独的一个单词.
    ```cpp
    const int GLOBAL_CONSTANT = 10;
    constexpr int COMPILE_TIME_CONSTANT = 10;
    #define MARCO_CONSTANT 10
    ```
1. 函数的命名使用小驼峰命名法.第一个单词小写, 其他单词首字母大写, 并依次连接.
    ```cpp
    int functionName();
    void getProgramInfo();
    void getHTTPRequest();
    ```
1. 类, 非内置类型别名, 数组类型别名的命名使用大驼峰命名法. 所有单词首字母大写, 并依次连接.
    ```cpp
    class SampleClass;
    typedef SampleClass ClassSample;
    typedef int IntArray[10];
    ```
1. 内置类型别名, 指针类型别名, 引用类型别名的命名使用帕斯卡命名类型规范. p表示指针类型, r表示引用类型, u表示无符号类型, 后缀数字表示需显示说明的长度, 在类型名被占用的情况下使用后缀_t.
    ```cpp
    typedef int *pint, &rint;
    typedef unsigned int uint, *puint, &ruint;
    ```

### 声明, 定义与实现
1. 所有函数（除入口函数外）, 类, 枚举类的定义必须在头文件中定义并在源文件实现.
1. 仅在本源文件中使用的函数不在头文件中声明.
1. 入口函数必须写在该源文件的最上方, 且不提前声明.
1. 内联函数必须在头文件定义并实现.
1. 所有的类模版, 函数模版必须在头文件中定义并实现.
1. 所有的全局变量必须在头文件中声明为extern, 并在对应的源文件中初始化.
    ```cpp
    // A.h
    extern int global_var;

    // A.cpp
    int global_var;
    ```
1. 编译时常量必须在头文件中声明并定义为constexpr, 不使用static修饰.

### 注释
1. 文件头注释及函数注释以```/**```开始, ```*/```结束.
1. TODO注释行首以```/// TODO:```开始.
1. 注释要求在注释开头记号后留一个空格, 文件头注释和函数注释的注释起始行和结束行不含有注释内容.

### 空格与缩进
#### TODO

### 函数
#### TODO

### 类
1. 类必须显式声明并实现构造函数和析构函数.
1. 作为非类型转换函数的只有一个非缺省参数的构造函数（复制构造函数和移动构造函数除外）必须显式地声明为explicit.
1. 抽象基类必须将析构函数定义为纯虚析构函数, 且在源文件中提供空实现.
    ```cpp
    // BaseClass.h
    class BaseClass {
    public:
        BaseClass();
        virtual ~BaseClass() = 0;
    }

    // BaseClass.cpp
    BaseClass::BaseClass {}
    BaseClass::~BaseClass {}
    ```
1. 在析构函数中必须显式地delete所有指针成员.
1. 类的声明中遵循函数在前, 变量在后.分别以public, protected, private的顺序声明, 同一个访问权限块中不能同时出现函数和变量.
1. 成员函数以构造函数, 类型转换构造函数, 析构函数, 类型转换函数, 运算符重载函数, 其他成员函数为顺序声明.
    ```cpp
    class SampleClass {
    public:
        SampleClass();
        SampleClass(int obj);
        ~SampleClass();
        operator int();
        SampleClass &operator+(SampleClass &&obj);
        getValue();
    public:
        int value;
    protected:
        int protected_member;
    private:
        int private_member;
    }
    ```
1. 类内函数在使用本类成员变量必须显式的指明this.

---
Copyright (c) 2018-2019 Alex Cui.
Licensed in *[CC-BY-NC-SA 4.0](https://creativecommons.org/licenses/by-nc-sa/4.0/)*. 
![CC-BY-NC-SA](https://upload.wikimedia.org/wikipedia/commons/1/12/Cc-by-nc-sa_icon.svg "CC-BY-NC-SA")
