#include "Func.h"
#include <stdio.h>

char* func(char* str, char* str1) {
	//���������� �������� �������
	int boo = 0;
	//������� ���� � �����
	int j = 0;
	int i = 0;
	for (i = 0; *(str + i) != '\n'; i++) {
		printf("I: %d\n", i);
		//���� ��������� ����� i ����� - ������ ��� ����� ������
		if (((*(str + i + 1) == ' ') && (*(str + i) != ' ')) || (*(str + i + 1) == '\n')) {
			for (int a = i - j; a != i; a++)
				for (int b = a + 1; b != i + 1; b++) {
					printf("Vxod v proverku! I: %d; J: %d; A: %d; B: %d\n", i, j, a, b);
					//���� ���� ����������� �����, �� ������� �� ���������
					if (*(str + b) == *(str + a)) {
						printf("Sovpad! A: %d; B: %d;\n", a, b);
						boo = 1;
						//���� ��������� ����������, ����������� �������� � ������� � �����
						goto a;
					}
				}
			if (boo == 0) {
				for (i - j; (i - j) != i + 1; j--) {
					printf("Prisvaivanie! Bukva: %d\n", i - j);
					*(str1 + i - j) = *(str + i - j);
				}
				if(*(str+i+1)!='\n')*(str1 + i + 1) = ' ';
			}
			//��������� �������� ���-�� ����
		a:
			j = 0;
			//��������� ���������� ��������
			boo = 0;
		}
		else if (*(str + i) == ' ') continue;
		else {
			j++;
			printf("J: %d\n", j);
		}
	}
	printf("I_final: %d\n", i);
	*(str1 + i) = '\n';
	return str1;
}