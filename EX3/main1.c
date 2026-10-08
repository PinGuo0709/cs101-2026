#include <stdio.h>

int main() {
    int rows;

    // 提示使用者輸入金字塔的層數
    printf("請輸入金字塔的層數: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("請輸入一個有效的正整數！\n");
        return 1;
    }

    printf("\n");

    // 外層迴圈控制總層數（行數）
    for (int i = 1; i <= rows; i++) {
        
        // 1. 印出前導空白，讓金字塔整體置中
        for (int space = 1; space <= rows - i; space++) {
            printf("  "); // 使用兩個空格來對齊底部的數字寬度
        }

        // 2. 內層迴圈控制每行印出的數字（第 i 行印 i 個數字，數字之間多加一個空格）
        for (int j = 1; j <= i; j++) {
            printf("%d   ", i); // 數字後面接三個空格，撐開正三角形的寬度
        }

        // 換行進入下一層
        printf("\n");
    }

    return 0;
}
