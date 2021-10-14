#include <stdio.h>
#include <stdlib.h>


#define IS_UTF_8(_byte) (_byte >= 0xC0)


int main(int argc, char** argv){

	unsigned char readChar;
	unsigned int byteVal;	

	scanf("%c", &readChar);

	byteVal = (unsigned int) readChar;
	if (IS_UTF_8(byteVal)) printf("UTF!!!\n");
	else printf("Boooo!!");

	printf("%d\n", readChar);


	return 0;

}
