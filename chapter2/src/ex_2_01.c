// ex_2_01
// 编写一个程序来确定分别有signed，unsigned限定的char short int 与long类型的取值范围
// 采用打印标准头文件中的相应值以及直接计算两种方式实现
// 后一种方法实现较困难，因为要确定各种浮点类型的取值范围

#include <stdio.h>
#include <limits.h>

int main() {

    // 方法1 直接用标准头文件
    // C标准库已经算好了各类型的极值，直接使用
    printf("signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 to %d\n", UCHAR_MAX);
    printf("signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 to %d\n", USHRT_MAX);
    printf("signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: 0 to %u\n", UINT_MAX);
    printf("signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 to %lu\n", ULONG_MAX);

    // 方法2 直接计算
    // char

    int char_bits = sizeof(char) * 8;

    printf("signed char: %d ~ %d\n",

        -(1 << (char_bits - 1)),

        (1 << (char_bits - 1)) - 1

    );

    printf("unsigned char: 0 ~ %u\n\n",

        (1 << char_bits) - 1

    );

    // short

    int short_bits = sizeof(short) * 8;

    printf("short: %d ~ %d\n",

        -(1 << (short_bits - 1)),

        (1 << (short_bits - 1)) - 1

    );

    printf("unsigned short: 0 ~ %u\n\n",

        (1 << short_bits) - 1

    );

    // int

    int int_bits = sizeof(int) * 8;

    printf("int: %d ~ %d\n",

        -(1 << (int_bits - 1)),

        (1 << (int_bits - 1)) - 1

    );

    printf("unsigned int: 0 ~ %u\n\n",

        (1 << int_bits) - 1

    );

    // long

    int long_bits = sizeof(long) * 8;

    printf("long: %ld ~ %ld\n",

        -(1L << (long_bits - 1)),

        (1L << (long_bits - 1)) - 1

    );

    printf("unsigned long: 0 ~ %lu\n",

        (1UL << long_bits) - 1

    );

    return 0;

}
