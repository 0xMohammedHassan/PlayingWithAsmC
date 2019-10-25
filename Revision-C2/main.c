#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
int x = 20;
int *j;
int f1() {

	int x = 10;
	return x;


}


int f2() {
	char *result = "global value has been changed";

	//Conditional jump with determine the execution time
	clock_t start = clock();
	__asm {
		mov eax,0
		
		jmp scan
		change:
		inc eax
			scan:
		cmp eax,30
			jne change
			je ending
			ending:
			mov x,eax
			mov ebx,result
			push ebx
			call printf
			pop ebx



	}
	clock_t end = clock();
	double total = (double)(end - start);
	printf("\nExecution time is %lf", total);
	printf("\n the value of new  X is : %d ", x);
	int *kei;
	kei = &x;
	*kei = 45;
	printf("\n New value after pointer has been done %d", x);


	return;
}


int p() {
	
	printf("\n%d%", x);
	return;

}

void compareCX() {

	clock_t begin = clock();
	
	for (int i = 0; i <= 2500000000; i++) {
		int sum=0;
		sum += i;

	}
	clock_t end = clock();
	double total = (double)(end + begin);
	printf("\nExecution time for Pure C is: %lf", total);
	return;


}

int comapreAA() {
	clock_t astart = clock();
	__asm {
	

		mov eax,0
		jmp check1
		nequal:
		inc eax
			check1:
		cmp eax, 2500000000
			jne nequal

	}


	clock_t aend = clock();
	double total2 = (double)(aend - astart);
	printf("\nExecution time for Inline ASM is: %lf", total2);
	return;
}
int main() {
	/*WinExec("cmd /c echo helloworld", 0);
	f2();
	*/
	comapreAA();
	compareCX();
	//comapreAA();
	
	getch();
	return 0;

}