#include <stdio.h>
#include "Func.h"

void proverka(char* str) {
	for (int i = 0; str[i] != '\n'; i++)
		if (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z')) || (str[i] == ' ')) continue;
		else str[i] = ' ';
}

int main() {
	printf("Vvedite stroku:");
	char str[1000];
	char str1[1000] = { 0 };
	fgets(str, 1000, stdin);
	if (str[0] == '\n') {
		printf("Error!");
		return 0;
	}
	else {
		proverka(str);
		puts(func(str, str1));
	}
	return 0;
}