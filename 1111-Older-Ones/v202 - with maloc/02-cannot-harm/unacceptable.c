#include "unacceptable.h"
#include<stdio.h>
#include <string.h>
/*
Start.
Notice:
VISIBLE I IZ MYLIB'Z ISUNACCEPTABLE1 YR 1 MKAY
-------------------------------------^^^^^ 1 value
and
VISIBLE I IZ MYLIB'Z ISUNACCEPTABLEZZZbase YR 31 AN YR 32 AN YR 33 MKAY
-------------------------------------------^^^^^^^^^^^^^^^^^^^^^^^ 3 values
*/

int unacceptable_basis(char* j){
	printf ("Number 1 --- This Is Unacceptable! (No.1 - The very first!!)\n");
	printf ("ACCEPTING\n");
	printf("%s\n",j);
	printf("Message SENT HERE  >>unacceptable.c<< TO Zoe %s\n", j);
	char greetings[] = "Hello World!";
	int rtn = 0; //this is shown 

	return rtn;
}


/*
1.
THIS ACCEPTS!
<<<<<<<<<<<<<<<--------------INTO HERE
Test Passing (accepting a char)
called like this:
VISIBLE I IZ MYLIB'Z ISUNACCEPTABLE1 YR "This text is located in >>unacceptable<<" MKAY
*/
int unacceptable_basis1(char* j){
	printf ("Number 1 --- This Is Unacceptable! (No.1 - The very first!!)\n");
	printf ("ACCEPTING\n");
	printf("%s\n",j);
	printf("Message SENT HERE  >>unacceptable.c<< TO Zoe %s\n", j);
	char greetings[] = "Hello World!";
	int rtn = 0; //this is shown 

	return rtn;
}




/*
2.
THIS SENDS!
>>>>>>>>>>>>>>---------------OUT OF HERE
Test Returning (return a char)
called like this:
VISIBLE I IZ MYLIB'Z ISUNACCEPTABLE2 YR 2 MKAY
*/
char* unacceptable_basis2(int j){
	printf ("Number 2: ENTERING unacceptable.c\n");
	printf ("RETURNING\n");
	char* str = "This is being returned from the Back End.";
	return str;
}



int unacceptable_basis3(int j){
/*
TOMORROW:
	-- accept char* j coming in
	-- use    char* to return
	-- Change unacceptable.h at the same time
	-- Change binding.h ( *isunacceptableWrapper3 ) at the same time
*/




	j=987;
	printf ("Number 3\n");
	return j;
}
int unacceptable_basis4(int j){
	j=000;
	printf ("Number 4\n");
	return j;
}

int unacceptable_basisZ(int j){
// PROTOTYPE TO COPY.  DO NOT MODIFY.
	printf("You entered: %d \n", j);
	j = j*10;
	return j;
}

/*
From here, the '2 Z's' indicate that we are passing on 2 values.

TO CALL, notice
 VISIBLE I IZ MYLIB'Z ISUNACCEPTABLEZZ1 YR 11 AN YR 12 MKAY
----------------------------------------^^^^^^^^^^^^^^ 2 values
*/

int unacceptable_basisZZ1(int j, int k){
// PROTOTYPE TO COPY.  DO NOT MODIFY.
	printf("Difficult 1 j: %d \n", j);
	printf("Difficult 1 k: %d \n", k);
	j = j*10;
	return j;
}


int unacceptable_basisZZ2(int j, int k){
// MODIFY
	printf("Difficult 2 j: %d \n", j);
	printf("Difficult 2 k: %d \n", k);
	j = j*10;
	return j;
}

int unacceptable_basisZZ3(int j, int k){
// MODIFY
	printf("Difficult 3 j: %d \n", j);
	printf("Difficult 3 k: %d \n", k);
	j = j*10;
	return j;
}


int unacceptable_basisZZZbase(int j, int k, int l){
// MODIFY
	printf("Base - 3-Base j: %d \n", j);
	printf("Base - 3-Base k: %d \n", k);
	printf("Base - 3-Base k: %d \n", l);
	j = j*10;
	return j;
}


int unacceptable_basisZZZ1(int j, int k, int l){
// MODIFY
	printf("ZZZ1 - 3-1 j: %d \n", j);
	printf("ZZZ1 - 3-1 k: %d \n", k);
	printf("ZZZ1 - 3-1 k: %d \n", l);
	j = j*10;
	return j;
}


int unacceptable_basisZZZ2(int j, int k, int l){
// MODIFY
	printf("ZZZ2 - 3-2 j: %d \n", j);
	printf("ZZZ2 - 3-2 k: %d \n", k);
	printf("ZZZ2 - 3-2 k: %d \n", l);
	j = j*10;
	return j;
}

/*
char* unacceptable_basisZZZ3(int j, int k, int l){
	printf("ZZZ3 - 3-3 j: %d \n", j);
	printf("ZZZ3 - 3-3 k: %d \n", k);
	printf("ZZZ3 - 3-3 k: %d \n", l);
	j = j*10;
	//return j;
	//printf ("NEW: Number ZZZ3: ENTERING unacceptable.c\n");
	char* str = "GENERATED IN unacceptable_basisZZZ3 but not printed there!!";
	return "A";
}
*/

char* zoe_unacceptable_basisZZZ3(char* j, char* k, int l){//<<<<<<<<<<<<<<<<<<<<<<<< int here

/*
Useful during development
	printf("ACCEPTING and RETURNING:%s\n",j);
	printf("Incoming 1:%s\n", j);
	printf("Incoming 2:%s\n", k);
	printf("Incoming 3:%d\n", l);
*/

	/*
	Do the important work
	j - 1 - line
	k - 2 - divider
	l - 3 - front or back (0 for front, other number for back)
	*/
	char strWorkingCopy1[50];
	strcpy(strWorkingCopy1, j);	
	char strWorkingCopy2[50];
	strcpy(strWorkingCopy2, j);

	//char devChar[20];
	char *token = "Contents of Token";
	printf("\n");


	char *filename = "zoejamie.txt";/*Open file*/

	int q=01;
	FILE *fp = fopen(filename, "w");

	if( l == 0 ){
		char *ptr;
		ptr = strchr(strWorkingCopy1, *k);
		memmove(ptr, ptr+1, strlen(ptr));
/*		printf("ZRO (left-over) 0 >   %s\n",ptr);	*/
		fprintf(fp,  ptr);/*write into file*/
		fclose(fp);/*Close file*/

			return ptr;
	}else{
	   	char stringz[50] = "";
	   	// Extract the first token
	   	char * tokenz = strtok(strWorkingCopy2, k);
/*	   	printf( "ONE (selected ) 1>   %s\n", tokenz ); //printing the token */
		fprintf(fp,  tokenz);/*write into file*/
		fclose(fp);/*Close file*/

			return tokenz;
	}


/*
But....
This workes on No.2!! [ unacceptable_basis2 ----- top of this file]


	char* str = "Blurgh.";
	return str;


*/

}


