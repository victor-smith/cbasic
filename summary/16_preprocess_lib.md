16章 预处理器 和 库
```mermaid
graph LR

A(预处理器和库函数)
A-->B(#define宏定义)
A-->C(其他指令)
A-->D(内联函数)
A-->E(数学库)
A-->F(通用工具库)

B-->利用宏参数创建字符串#
B-->预处理器的粘合器##
B-->可变宏...或__VAR_ARGS__
B-->宏和函数的选择

C-->#define和#undef
C-->H(条件编译)
H-->#ifdef,#else,#endif
H-->#ifndef,#else,#endif
H-->#if,#elif,#else,#endif.defined
H-->编译宏#pragma

D-->要求处理速度快于调用函数的时间
E-->三角函数,log,pow,sqrt,ceil,floor,fabs
E-->math.h

F-->exit,aexit
F-->qsort
F-->assert.h,assert
F-->string.h,memcpy-restrict标记,memmove
F-->I(stdarg.h,va_start,va_arg,va_copy,va_end)




```



``` c
#define PRNT1(X) printf("the value of " #X "*" #X " is %d\n", X*X);
#define PRNT2(X,n) printf("the value of "#X#n"is %d\n", #X##n);
#define PRNT3(X,...) printf(#X ", funcation variable args is "__VAR_ARGS__);

void assert(scalar expression);

void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
```

