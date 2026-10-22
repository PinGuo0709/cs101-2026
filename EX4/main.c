#include <stdio.h>

int main() {
    FILE* fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    int ra[3];
    char rb[4]; // 包含字串結尾的 '\0' 空間
    float rc[3];

    // 1. 以寫入二進位模式 ("wb") 開啟檔案
    fp = fopen("a.bin", "wb");
    if (fp == NULL) {
        printf("檔案開啟失敗！\n");
        return 1;
    }

    // 2. 將 3 個陣列以二進位寫入檔案
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 4, fp); // 寫入 "ABC" 連同結束字元
    fwrite(c, sizeof(float), 3, fp);
    
    fclose(fp); // 關閉檔案

    // 3. 以讀取二進位模式 ("rb") 重新開啟檔案
    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        printf("檔案開啟失敗！\n");
        return 1;
    }

    // 4. 從檔案中讀取資料到接收變數中
    fread(ra, sizeof(int), 3, fp);
    fread(rb, sizeof(char), 4, fp);
    fread(rc, sizeof(float), 3, fp);

    fclose(fp); // 關閉檔案

    // 5. 輸出 3 個陣列的內容
    for (int i = 0; i < 3; i++) {
        printf("%d ", ra[i]);
    }
    printf("\n");

    printf("%s\n", rb);

    for (int i = 0; i < 3; i++) {
        printf("%f ", rc[i]);
    }
    printf("\n");

    return 0;
}
