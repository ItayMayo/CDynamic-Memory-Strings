#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ReverseInputString();
int string_compare(const char* a, const char* b);
char** split(const char* str, int* output_count);

int main()
{
	ReverseInputString();

	int outputCount = -1;
	char** splitArray = split("Hello World I'm Great", &outputCount);
	printf("[");

	for (int i = 0; i < outputCount; i++)
	{
		printf("%s, ", splitArray[i]);
	}

	printf("]");
}

void ReverseInputString()
{
	char inputBuffer[255];
	printf("Enter string. Max length 255 characters\n");
	scanf_s("%s", inputBuffer, sizeof(inputBuffer));
	int inputLength = strlen(inputBuffer);

	for (int i = 1; i <= inputLength; i++)
	{
		char value = inputBuffer[inputLength - i];
		printf("%c", value);
	}

	printf("\n");
}

int string_compare(const char* a, const char* b)
{
	if (strcmp(a, b) == 0)
	{
		return 0;
	}

	int index = 0;

	for (index = 0; a[index] == b[index]; index++)
	{}

	if (a[index] > b[index])
	{
		return 1;
	}

	return -1;
}

char** split(const char* str, int* output_count)
{
	char* inputString = _strdup(str);
	char** splitStrArray = NULL;
	char* next_token;
	char* token = strtok_s(inputString, " ", &next_token);
	*output_count = 0;

	while (token != NULL) {
		int newSize = *output_count + 1;
		splitStrArray = realloc(splitStrArray, newSize * sizeof(char*));
		splitStrArray[*output_count] = token;
		*output_count += 1;
		token = strtok_s(NULL, " ", &next_token);
	}

	return splitStrArray;
}