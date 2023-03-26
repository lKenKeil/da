#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 최고차항을 100으로 제한.
#define MAX_DEGREE 100


void multiply_polynomials(int degree1, int* polynomial1, int degree2, int* polynomial2, int* result) {

    for (int i = 0; i <= degree1 + degree2; i++) {
        result[i] = 0;
    }

    for (int i = 0; i <= degree1; i++) {
        for (int j = 0; j <= degree2; j++) {
            result[i + j] += polynomial1[i] * polynomial2[j];
        }
    }
}


void print_polynomial(int degree, int* polynomial) {
    printf("%dx^%d", polynomial[degree], degree);
    for (int i = degree - 1; i >= 0; i--) {
        if (polynomial[i] != 0) {
            if (polynomial[i] > 0) {
                printf(" + %dx^%d", polynomial[i], i);
            }
            else {
                printf(" - %dx^%d", -polynomial[i], i);
            }
        }
    }
    printf("\n");
}

int main() {
 
    int degree1, degree2;
    int polynomial1[MAX_DEGREE + 1], polynomial2[MAX_DEGREE + 1], result[MAX_DEGREE * 2 + 1];


    printf("첫 번째 다항식의 차수를 입력하세요: ");
    scanf("%d", &degree1);
    printf("첫 번째 다항식의 계수를 내림차순으로 입력하세요:\n");
    for (int i = degree1; i >= 0; i--) {
        scanf("%d", &polynomial1[i]);
    }


    printf("두 번째 다항식의 차수를 입력하세요: ");
    scanf("%d", &degree2);
    printf("두 번째 다항식의 계수를 내림차순으로 입력하세요:\n");
    for (int i = degree2; i >= 0; i--) {
        scanf("%d", &polynomial2[i]);
    }


    multiply_polynomials(degree1, polynomial1, degree2, polynomial2, result);

 
    printf("첫 번째 다항식: ");
    print_polynomial(degree1, polynomial1);
    printf("두 번째 다항식: ");
    print_polynomial(degree2, polynomial2);
    printf("두 다항식의 곱: ");
    print_polynomial(degree1 + degree2, result);

    return 0;
}

