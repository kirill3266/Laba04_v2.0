#include "Func.h"
#include <stdio.h>

char* func(char* str, char* str1) {
	//переменная проверки условия
	int boo = 0;
	//счётчик букв в слове
	int j = 0;
	int i = 0;
	for (i = 0; *(str + i) != '\n'; i++) {
		printf("I: %d\n", i);
		//если следующая после i буква - пробел или конец строки
		if (((*(str + i + 1) == ' ') && (*(str + i) != ' ')) || (*(str + i + 1) == '\n')) {
			for (int a = i - j; a != i; a++)
				for (int b = a + 1; b != i + 1; b++) {
					printf("Vxod v proverku! I: %d; J: %d; A: %d; B: %d\n", i, j, a, b);
					//если есть совпадающие буквы, то условие не выполнено
					if (*(str + b) == *(str + a)) {
						printf("Sovpad! A: %d; B: %d;\n", a, b);
						boo = 1;
						//если произошло совпадение, прекращение проверки и переход к метке
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
			//обнуление счётчика кол-ва букв
		a:
			j = 0;
			//обнуление переменной проверки
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