#include "ImageHandler.h"


int FindMistakes(const Image original, const Image negative, int n, int m)
{
	int mistakes = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (original[i][j] == negative[i][j])mistakes++;
	return mistakes;
}
