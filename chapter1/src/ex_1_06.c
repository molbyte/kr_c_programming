// 验证 C 的关系表达式结果是不是只有0和1
#include <stdio.h>

int main()
{
    int value;

    // ASCII 码表中，EOF 的值为 -1，而正常输入的字符的 ASCII 码值都在 0~127 之间
    // 因此，getchar() != EOF 的结果要么是 0（当输入结束时），要么是 1（当输入正常时）
    // Ctrl + D 向终端发送EOF信号表示输入结束
    value = (getchar() != EOF);

    printf("%d\n", value);

    return 0;
}