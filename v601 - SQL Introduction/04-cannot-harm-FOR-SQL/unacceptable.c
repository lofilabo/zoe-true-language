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



int unacceptable_basis3(char* j){

/*
back-end of
isunacceptableWrapper3
and therefore
zoeSQL
*/

/*
SQL Job Marker
*/

	printf ("Number 3 --- This Is Unacceptable! (No.1 - The very first!!)\n");
	printf ("ACCEPTING SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL\n");
	printf ("ACCEPTING SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL\n");
	printf ("ACCEPTING SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL SQL\n");
	printf("%s\n","You Are Now Inside ZoeSQL - step 2");
	printf("%s\n","......and the next part is Coming In!!");
	
	//once again: j is the piece of SQL
	//check it here
	// it should be:
	// SELECT * from SQLtable.....
	// it comes from TTT-SQL.zoe
	printf(j);
/*
Do the SQL work from here
We already....
ACCEPT the SQL from TTT-SQL.zoe (it is j)
REPEAT: SQL is j
*/
	
	return 3;/* ARE YOU SEEING 3 ??  Returning 3. If we pencil in the zoe code, it will show on screen*/
}
int unacceptable_basis4(int j){

	j=000;
	printf ("Step 2\n");
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
	l - 3 - front or back (0 for back, other number for front)
	*/
	char strWorkingCopy1[4012];
	strcpy(strWorkingCopy1, j);	
	char strWorkingCopy2[4012];
	strcpy(strWorkingCopy2, j);

	//char devChar[20];
	char *token = "Contents of Token";
	//printf("\n");


	char *filename = "zoejamie.txt";/*Open file*/

	int q=01;
//	FILE *fp = fopen(filename, "w");

	if( l == 0 ){
		/* AFTER - i.e.  something;THIS */
		// Extract the Rest token -- NOT the 'before' chunk
		// i.e.  something;THIS
		char *ptr;
		ptr = strchr(strWorkingCopy1, *k);
		memmove(ptr, ptr+1, strlen(ptr));
/*		printf("ZRO (left-over) 0 >   %s\n",ptr);	*/
//		fprintf(fp,  ptr);/*write into file*/
//		fclose(fp);/*Close file*/

		return ptr;

	}else{
		/* BEFORE i.e. THIS;something */
	   	//char stringz[512] = "";
	   	// Extract the first token -- The 'Before the Marker'
	   	// i.e. THIS;something
	   	char * tokenz = strtok(strWorkingCopy2, k);
/*	   	printf( "ONE (selected ) 1>   %s\n", tokenz ); //printing the token */
//		fprintf(fp,  tokenz);/*write into file*/
//		fclose(fp);/*Close file*/

		return tokenz;
	}


/*
But....
This workes on No.2!! [ unacceptable_basis2 ----- top of this file]


	char* str = "Blurgh.";
	return str;


*/

}


