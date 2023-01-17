#include <stdio.h>
#include <string.h>

int main()
{
	int values[10] = {
			123, 1899, 48266, 123456, 9876543,
			10100100, 5, 500000, 99000111, 83};

	int temp, j, idx;
	for (int i = 0; i < 10; i++)
	{
		char numStr[32], out[32];

		sprintf(numStr, "%d", values[i]);
		int count = strlen(numStr);
		int originalCount = count;
		j = idx = 0;

		do
		{
			if (count % 3 == 0)
			{
				for (int k = 0; k < 3; k++)
					out[j++] = numStr[idx++];
				if (count > 3)
					out[j++] = ',';
				count -= 3;
			}
			else if (count % 3 == 2)
			{
				for (int k = 0; k < 2; k++)
					out[j++] = numStr[idx++];
				if (count > 3)
					out[j++] = ',';
				count -= 2;
			}
			else if (count % 3 == 1)
			{
				out[j++] = numStr[idx++];
				if (count > 3)
					out[j++] = ',';
				count--;
			}

			if (idx == originalCount)
			{
				out[j] = 0;
				break;
			}
		} while (1);

		printf("%12d    --> %12s\n", values[i], out);
	}
	return (0);
}
