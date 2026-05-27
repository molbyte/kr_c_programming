// 验证 C 的关系表达式结果是不是只有0和1
#include <stdio.h>

int main()
{
    int value;

    value = (getchar() != EOF);

    printf("%d\n", value);

    return 0;
}