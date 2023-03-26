#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// �ְ������� 100���� ����.
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


    printf("ù ��° ���׽��� ������ �Է��ϼ���: ");
    scanf("%d", &degree1);
    printf("ù ��° ���׽��� ����� ������������ �Է��ϼ���:\n");
    for (int i = degree1; i >= 0; i--) {
        scanf("%d", &polynomial1[i]);
    }


    printf("�� ��° ���׽��� ������ �Է��ϼ���: ");
    scanf("%d", &degree2);
    printf("�� ��° ���׽��� ����� ������������ �Է��ϼ���:\n");
    for (int i = degree2; i >= 0; i--) {
        scanf("%d", &polynomial2[i]);
    }


    multiply_polynomials(degree1, polynomial1, degree2, polynomial2, result);

 
    printf("ù ��° ���׽�: ");
    print_polynomial(degree1, polynomial1);
    printf("�� ��° ���׽�: ");
    print_polynomial(degree2, polynomial2);
    printf("�� ���׽��� ��: ");
    print_polynomial(degree1 + degree2, result);

    return 0;
}

