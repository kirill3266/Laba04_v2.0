#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void proverka(char* str) {
	for (int i = 0; str[i] != '\n'; i++)
		if (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z')) || (str[i] == ' ')) continue;
		else str[i] = ' ';
}

int strlen(char* str) {
	int i = 0;
	for (i = 0; str[i] != '\n'; i++);
	return i;
}


char* func1(char* str, char* str1, char* glasn) {
	int boo = 0;
	int boo1 = 0;
	int j = 0;
	int count = 0;
	int i = 0;
	for (i = 0; str[i] != '\n'; i++) {
		if (((str[i + 1] == ' ') || (str[i + 1] == '\n')) && (str[i] != ' ')) {
			for (int a = i - j; a != i; a++)
				for (int b = a + 1; b != i + 1; b++) {
					if (str[b] == str[a]) {
						for (int k=0;k<strlen(glasn);k++) if (str[b]==glasn[k])
						boo = 1;
					}
				}
			if (boo == 0) {
				for (i - j; (i - j) != i + 1; j--) {
					str1[count] = str[i - j];
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

char* func2(char* str, char* str1, char* soglasn) {
	int boo = 0;
	int j = 0;
	int count = 0;
	int i = 0;
	for (i = 0; str[i] != '\n'; i++) {
		if (((str[i + 1] == ' ') || (str[i + 1] == '\n')) && (str[i] != ' ')) {
			for (int a = i - j; a != i; a++)
				for (int b = a + 1; b != i + 1; b++) {
					if (str[b] == str[a]) {
						for (int k = 0; k < strlen(soglasn); k++) if (str[b] == soglasn[k])
						boo = 1;
					}
				}
			if (boo == 0) {
				for (i - j; (i - j) != i + 1; j--) {
					str1[count] = str[i - j];
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

int main() {
	printf("Vvedite stroku:");
	char str[1000];
	char str1[1000] = { 0 };
	char glasn[] = "AaEeIiOoUuYy";
	char soglasn[] = "BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxYyZz";
	fgets(str, 1000, stdin);
	printf("Vvedite proverku: (0 for glasn; 1 for soglasn)\n");
	int prov = 5;
	scanf("%d", &prov);
	if (str[0] == '\n') {
		printf("Error!");
		return 0;
	}
	else if (prov == 0) {
		proverka(str);
		puts(func1(str, str1, glasn));
	}
	else if (prov == 1) {
		proverka(str);
		puts(func2(str, str1, soglasn));
	}
	else printf ("Error!");
	return 0;
}