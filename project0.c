#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 500000
#define IS_UTF(_byte) (_byte >= 0xC0)

#define IS_2_BYTE(_byte) (_byte >= 0xC0 && _byte <= 0xDF)
#define IS_3_BYTE(_byte) (_byte >= 0xE0 && _byte <= 0xEF)
#define IS_4_BYTE(_byte) (_byte >= 0xF0 && _byte <= 0xF7)
#define IS_5_BYTE(_byte) (_byte >= 0xF8 && _byte <= 0xFB)
#define IS_6_BYTE(_byte) (_byte >= 0xFC && _byte <= 0xFD)
#define IS_7_BYTE(_byte) (_byte == 0XFE)

typedef struct{
	int frequency;
	size_t byteLenght;
	char* character;
} char_bytes;

//sets read in character from the buffer to a created instance of the struct char_bytes
char_bytes* setCharacter(unsigned char* buffer, size_t size);
//gets the number of bytes that are in the character depending on its leading byte
size_t getByteLenght(unsigned char _byte);
//standard output for the char_byte struct
void print(char_bytes* _val);
//finds the given character within an array
int find(char_bytes* _array, char* _val, size_t size);
//compares two characters based on repetition;
int compare(char_bytes* _lhs, char_bytes* _rhs);
//prints an array of char_bytes
void printArray(char_bytes* _a, size_t size);

int main(int argc, char** argv){
	
//	printf("------PROGRAM START-------\n");

	unsigned char readByte;
	unsigned char* _byteSequence;
	unsigned int _charRead = 0;
	size_t _charSize;	

	size_t _size = 0;
	char_bytes* occurrences = malloc(MAX_SIZE*sizeof(char_bytes));

	while ( scanf("%c", &readByte) > 0){
		_charRead++;
	
//		printf("\n.... Reading Character N.%d\n", _charRead);
		_charSize = getByteLenght(readByte); 	
//		printf("\tNumber of bytes within character are.... %ld\n", _charSize);

		_byteSequence = malloc(_charSize*sizeof(char));
		_byteSequence[0] = readByte;
		int i = 1;
		for (i; i < _charSize; i++)  scanf("%c", &(_byteSequence[i]));		

//		printf("\t...Moving bytes into structure\n");
		char_bytes* _tempHolder = setCharacter(_byteSequence, _charSize);
			
		free(_byteSequence);
			
		if (_size == 0){
			occurrences[_size++] =  *_tempHolder;
//			printf("\tNew character found!!!...\n");
//			print(&occurrences[_size - 1]);
		}else {
			int index = find(occurrences, _tempHolder->character, _size);
			if (index < 0){
				occurrences[_size++] = * _tempHolder;
//				printf("\tNew character found!!!...\t");
//				print(&occurrences[_size - 1]);
			}
			else {
//				printf("\tCharacter  Found at index %d...\t", index);
				occurrences[index].frequency++;
//				print(&occurrences[index]);
				free(_tempHolder->character);
				free(_tempHolder);
			}				
		}
		
		_tempHolder = NULL;
		_byteSequence = NULL;
//		printf("\n\n");
	
	}

	qsort(occurrences, _size, sizeof(char_bytes), compare);
	printArray(occurrences, _size);
	
//	printf("Total Number of characters read: %d\n", _charRead);
//	printf("Total unique characters read: %ld\n", _size);
	int i  = 0;
	for (i; i < _size; i++) free(occurrences[i].character);
	free(occurrences);
//	printf("------PROGRAM END-------\n");
	return 0;

}

void printArray(char_bytes* _a, size_t size){
	int i = 0;
	for (i; i < size; i++) print(&_a[i]);
}

int find(char_bytes* _array, char* _val, size_t size){
	if (size == 0) return -1;

	int i = 0;
	for (i; i < size; i++) if (strcmp(_array[i].character, _val) == 0) return i;

	return -1;
}

size_t getByteLenght(unsigned char _byte){
//	printf("\tGetting number of bytes within character\n");

	if (IS_7_BYTE(_byte)) return 7;
	if (IS_6_BYTE(_byte)) return 6;
	if (IS_5_BYTE(_byte)) return 5;
	if (IS_4_BYTE(_byte)) return 4;
	if (IS_3_BYTE(_byte)) return 3;
	if (IS_2_BYTE(_byte)) return 2;

	return 1;
}

void print(char_bytes* _val){
	printf("%s->%d\n", _val->character, _val->frequency);
}

char_bytes* setCharacter(unsigned char* buffer, size_t size){

	char_bytes* _temp =  malloc(sizeof(char_bytes)) ;

	_temp->byteLenght = size;
	_temp->character = malloc((size + 1) * sizeof(char));
	
	int i = 0;
	for (i; i < size; i++)
		 _temp->character[i] = buffer[i];
	_temp->character[size] = '\0';

	_temp->frequency = 1;
	return _temp;

}

int compare(char_bytes* _lhs, char_bytes* _rhs){
	return _rhs->frequency - _lhs->frequency;
}
