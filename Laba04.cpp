#include <stdio.h>
#include "Func.h"

int main() {
	printf("Vvedite stroku:");
	char str[1000];
	char str1[1000] = { 0 };
	fgets(str, 1000, stdin);
	if (str[0] == '\n') {
		printf("Error!");
		return 0;
	}
	else puts(func(str, str1));
	return 0;
}