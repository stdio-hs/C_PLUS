#include "word.h"

void selectionSortWords(char** DATA_array, int DATA_size)
{
	for (int left = 0; left < DATA_size; left++)
	{
		int min = left;
		for (int i = left + 1; i < DATA_size; i++) // min Å½»ö
			min = (strcmp(DATA_array[i], DATA_array[min]) < 0) ? i : min;

		if (min != left) // SWAP
		{
			char temp[15];
			strcpy(temp, DATA_array[left]);
			strcpy(DATA_array[left], DATA_array[min]);
			strcpy(DATA_array[min], temp);
		}
	}
}