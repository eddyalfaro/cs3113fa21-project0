#include <stdio.h>
#include <stdlib.h>


#define IS_UTF(_byte) (_byte >= 0xC0)

typedef struct{

	size_t byteLenght;
	char* character;

} utf_8;

utf_8* setCharacter(char* buffer, size_t size);
size_t getByteLenght(unsigned char _byte);
void print(utf_8* _val);

int main(int argc, char** argv){

	unsigned char readChar;
	unsigned int byteVal;	

	scanf("%c", &readChar);

	byteVal = (unsigned int) readChar;
	if (IS_UTF(byteVal)) printf("UTF!!!\n");
	else printf("Boooo!!");

	printf("%d\n", readChar);


	return 0;

}

void print(utf_8* _val){
	printf("%s", _val->character);
}


utf_8* setCharacter(char* buffer, size_t size){

	utf_8* _temp =  malloc(sizeof(utf_8)) ;

	_temp->byteLenght = size;
	_temp->character = malloc((size + 1) * sizeof(char));
	
	int i = 0;
	for (i; i < size; i++)
		 _temp->character[i] = buffer[i];
	_temp->character[size] = '\0';

	return _temp;

}
