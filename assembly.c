#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//test

char* assimm(char name[]) {
	int base = checkbase(name);
	if (base == 16) {
		return hextobin(name);
	}
	else if (base == 10) {
		return dectobin(name);
	}
	else {
		return imm(name);
	}

}

//void readfile(char* filename, char* tr) {
	//FILE* fpointer;
	//fpointer = fopen(filename, "r");
	//char row[100];
	//while (!feof(fpointer)) {
		//fgets(row, 100, fpointer);
		//strcat(tr, row);
	//}
	//fclose(fpointer);
//}

//void writefile(char* filename, char* tr) {
//	FILE* fpointer;
//	fpointer = fopen(filename, "wb");
//	fprintf(fpointer, "%s", tr);
//	close(fpointer);
//}

//void assembler(char* asmfile,char* targetfile) {
	//char asm[1000]="";
	//readfile(asmfile, asm);
	//char bin[1000] = "";
	//convert
	//writefile(targetfile, bin);

//}

void main2() {
	//char* asmfile = "p1.asm";
	//char* targetfile = "dmemin";
	//char* file = "imemin";
	//assembler(asmfile, targetfile);
}
