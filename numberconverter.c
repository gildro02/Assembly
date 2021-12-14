#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numberconverter.h"

int checkdec(char num[]) {
	int i = 0;
	if (num[0] == '-') {
		i++;
		while (num[i] != '\0') {
			if (num[i] > '9' || num[i] < '0') {
				return 0;
			}
			i++;
		}
	}
	else {
		while (num[i] != '\0') {
			if (num[i] > '9' || num[i] < '0') {
				return 0;
			}
			i++;
		}
	}
	return 1;
}

int checkbase(char num[]) {
	if (num[0] == '0' && num[1] == 'x') {
		return 16;
	}
	if (checkdec(num) == 1) {
		return 10;
	}
	else {
		return 1;
	}
}

void reverse(char* bin) {
	int n = strlen(bin);
	char ln[20];
	for (int i = 0; i < n; i++) {
		strcat(ln, bin[n - 2 - i]);
	}
	strcat(ln, bin);
	strcpy(bin, ln);

}

void complete(char* bin, int l, int pos) {
	int n = l - strlen(bin);
	char ln[20] = "";
	if (pos == 1) {
		for (int i = 0; i < n; i++) {
			strcat(ln, "0");
		}
		strcat(ln, bin);
		strcpy(bin, ln);
	}
	else {
		strcat(ln, "1");
		for (int i = 1; i < n; i++) {
			strcat(ln, "0");
		}
		strcat(ln, bin);
		strcpy(bin, ln);
	}
}

void hextobin(char num[],char* bin) {
	int i = 2;
	while (num[i] != '\0') {
		if (num[i] == '0') {
			strcat(bin, "0000");
		}
		else if (num[i] == '1') {
			strcat(bin, "0001");
		}
		else if (num[i] == '2') {
			strcat(bin, "0010");
		}
		else if (num[i] == '3') {
			strcat(bin, "0011");
		}
		else if (num[i] == '4') {
			strcat(bin, "0100");
		}
		else if (num[i] == '5') {
			strcat(bin, "0101");
		}
		else if (num[i] == '6') {
			strcat(bin, "0110");
		}
		else if (num[i] == '7') {
			strcat(bin, "0111");
		}
		else if (num[i] == '8') {
			strcat(bin, "1000");
		}
		else if (num[i] == '9') {
			strcat(bin, "1001");
		}
		else if (num[i] == 'A') {
			strcat(bin, "1010");
		}
		else if (num[i] == 'B') {
			strcat(bin, "1011");
		}
		else if (num[i] == 'C') {
			strcat(bin, "1100");
		}
		else if (num[i] == 'D') {
			strcat(bin, "1101");
		}
		else if (num[i] == 'E') {
			strcat(bin, "1110");
		}
		else if (num[i] == 'F') {
			strcat(bin, "1111");
		}
		i++;
	}
	complete(bin, 12, 1);
}

void dectobin(char num[],char* bin) {//needs a slightly better solution.
	int number = atoi(num);
	int pos = 1;
	if (number < 0) {
		number = number + 2048;
		pos = 0;
	}
	int count = 0;
	int flag = 0;
	char st[13]="";
	char a[2]="";
	while (number != 0) {
		if (number % 2 != 0) {
			strcpy(a, "1");
		}
		else {
			strcpy(a, "0");
		}
		strcat(st, a);
		number /= 2;
	}
	
	_strrev(st);
	strcat(bin, st);
	complete(bin, 12, pos);
}


void imm(int num, char* bin) {// will change, just for now.
	char st[13];
	sprintf(st, "%d", num);
	dectobin(st,bin);
}


void convert(char num[],char* bin) {
	
	if (checkbase(num) == 16) {
		 hextobin(num,bin);
	}
	else if (checkbase(num) == 10) {
		dectobin(num, bin);
	}
}

void main6() {
	char number[] = "16";
	char bin[20]="";
	dectobin(number, bin);
	printf("%s",bin);
}