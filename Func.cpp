#include "Func.h"
#include <stdio.h>

char* func(char* str, char* str1) {
	int boo = 0;
	int j = 0;
	int count = 0;
	int i = 0;
	for (i = 0; str[i] != '\n'; i++) {
		if (((str[i+1] == ' ') || (str[i + 1] == '\n')) && (str[i] != ' ')) {
			for (int a = i - j; a != i; a++)
				for (int b = a + 1; b != i + 1; b++) {
					if (str[b] == str[a]) {
						boo = 1;
					}
				}
			if (boo == 0) {
				for (i - j; (i - j) != i + 1; j--) {
					str1[count] = str[i-j];
					count++;
				}
				if (str[i + 1] != '\n') {
					str1[count] = ' ';
					count++;
				}
			}
			j = 0;
			boo = 0;
		}
		else if (str[i] == ' ') {
			continue;
		}
		else {
			j++;
		}
	}
	return str1;
}