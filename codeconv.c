#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numberconverter.h"

void assreg(char name[], char* tr) {
	if (strcmp(name,"$zero")==0) {
		strcpy(tr, "0000");
	}
	else if (strcmp(name, "$imm1") == 0) {
		strcpy(tr, "0001");
	}
	else if (strcmp(name, "$imm2") == 0) {
		strcpy(tr, "0010");
	}
	else if (strcmp(name, "$v0") == 0) {
		strcpy(tr, "0011");
	}
	else if (strcmp(name, "$a0") == 0) {
		strcpy(tr, "0100");
	}
	else if (strcmp(name, "$a1") == 0) {
		strcpy(tr, "0101");
	}
	else if (strcmp(name, "$a2") == 0) {
		strcpy(tr, "0110");
	}
	else if (strcmp(name, "$t0") == 0) {
		strcpy(tr, "0111");
	}
	else if (strcmp(name, "$t1") == 0) {
		strcpy(tr, "1000");
	}
	else if (strcmp(name, "$t2") == 0) {
		strcpy(tr, "1001");
	}
	else if (strcmp(name, "$s0") == 0) {
		strcpy(tr, "1010");
	}
	else if (strcmp(name, "$s1") == 0) {
		strcpy(tr, "1011");
	}
	else if (strcmp(name, "$s2") == 0) {
		strcpy(tr, "1100");
	}
	else if (strcmp(name, "$gp") == 0) {
		strcpy(tr, "1101");
	}
	else if (strcmp(name, "$sp") == 0) {
		strcpy(tr, "1110");
	}
	else if (strcmp(name, "$ra") == 0) {
		strcpy(tr, "1111");
	}
}

void asscode(char name[], char* tr) {
	if (strcmp(name, "add") == 0) {
		strcpy(tr, "00000000");
	}
	else if (strcmp(name, "sub") == 0) {
		strcpy(tr, "00000001");
	}
	else if (strcmp(name, "mac") == 0) {
		strcpy(tr, "00000010");
	}
	else if (strcmp(name, "and") == 0) {
		strcpy(tr, "00000011");
	}
	else if (strcmp(name, "or") == 0) {
		strcpy(tr, "00000100");
	}
	else if (strcmp(name, "xor") == 0) {
		strcpy(tr, "00000101");
	}
	else if (strcmp(name, "sll") == 0) {
		strcpy(tr, "00000110");
	}
	else if (strcmp(name, "sra") == 0) {
		strcpy(tr, "00000111");
	}
	else if (strcmp(name, "srl") == 0) {
		strcpy(tr, "00001000");
	}
	else if (strcmp(name, "beq") == 0) {
		strcpy(tr, "00001001");
	}
	else if (strcmp(name, "bne") == 0) {
		strcpy(tr, "00001010");
	}
	else if (strcmp(name, "blt") == 0) {
		strcpy(tr, "00001011");
	}
	else if (strcmp(name, "bgt") == 0) {
		strcpy(tr, "00001100");
	}
	else if (strcmp(name, "ble") == 0) {
		strcpy(tr, "00001101");
	}
	else if (strcmp(name, "bge") == 0) {
		strcpy(tr, "00001110");
	}
	else if (strcmp(name, "jal") == 0) {
		strcpy(tr, "00001111");
	}
	else if (strcmp(name, "lw") == 0) {
		strcpy(tr, "00010000");
	}
	else if (strcmp(name, "sw") == 0) {
		strcpy(tr, "00010001");
	}
	else if (strcmp(name, "reti") == 0) {
		strcpy(tr, "00010010");
	}
	else if (strcmp(name, "in") == 0) {
		strcpy(tr, "00010011");
	}
	else if (strcmp(name, "out") == 0) {
		strcpy(tr, "00010100");
	}
	else if (strcmp(name, "halt") == 0) {
		strcpy(tr, "00010101");
	}
}

void assrow(char row[],char* str) {
	char coprow[100];
	strcpy(coprow, row);
	char* piece = strtok(coprow, " ");
	char tr[100]="";
	asscode(piece, tr);
	strcpy(str, tr);
	strcat(str, "\n");
	for (int i = 1; i < 7;i++){
		piece = strtok(NULL, ",");
		if (piece != NULL) {
			if (i < 5) {
				assreg(piece, tr);
				strcat(str, tr);
				strcat(str, "\n");
			}
			else {
				convert(piece, tr);
				strcat(str, tr);
				strcat(str, "\n");
			}
		}
	}
}

void labelrow() {

}

void asstxt(char txt[], char* str) {
	char* row = strtok(txt,"\n");
	char tr[50] = "";
	assrow(row,tr);
	//strcpy(str, tr);
	while (row != NULL) {
		if (row != NULL) {
			row = strtok(NULL, "\n");
			assrow(row, tr);
			//strcat(str, tr);
		}
	}
}

void main() {
	char name[] = "add $s0,$t0,$zero,$a0,18,15";
	//char number[] = "15";
	char bin[100] = "";
	assrow(name, bin);
	//convert(number, bin);
	printf("%s\n", bin);
	
}