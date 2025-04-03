#include <stdio.h>
#pragma warning(disable:4996)  // 4996 경고만 무시
#include <stdlib.h>

#define MAX_SIZE 100  // 배열 최대 크기

int main() {
    FILE* inputFile, * outputFile;
    int array1[2], array2[MAX_SIZE], array3[MAX_SIZE]; 

    // 파일 열기
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 첫 번째 행 입력 → array1 저장
    fscanf(inputFile, "%d %d", &array1[0], &array1[1]); //자료구조과제 첫번째 행부분 -> [number_of_exponents]\t[number_of_exponents]\n
    int n = 0, i;

    // 나머지 행 입력 →  array2, array3            [coef]는 array2 에 [exp]는 array3에 저장
   /*                    [coef]\t[exp]\n
                         [coef]\t[exp]\n
                         [coef]\t[exp]\n
                         [coef]\t[exp]\n
                          …
        가장 첫줄은 두 다항식의 지수(exponents)의 수를 의미
        두번째 줄부터는 다항식의 계수와 지수를 의미*/

    while (fscanf(inputFile, "%d %d", &array2[n], &array3[n]) == 2) {  //2행부터 아래행까지 쭉[coef], [exp]을 array2, array3에 저장.. 
        n++;  // 행 개수 증가
    }

    fclose(inputFile);  // 파일 닫기

    // ✅ 결과 출력 (콘솔)
    printf("array1: %d %d\n", array1[0], array1[1]);
    printf("array2: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array2[i]);
    }
    printf("\narray3: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array3[i]);
    }
    printf("\n");

    // ✅ 결과 출력 (output.txt)
    fprintf(outputFile, "array1: %d %d\n", array1[0], array1[1]);
    fprintf(outputFile, "array2: ");
    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", array2[i]);
    }
    fprintf(outputFile, "\narray3: ");
    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", array3[i]);
    }
    fprintf(outputFile, "\n");

    fclose(outputFile);  // 파일 닫기
    printf("배열이 output.txt에 저장되었습니다.\n");

    return 0;
}
