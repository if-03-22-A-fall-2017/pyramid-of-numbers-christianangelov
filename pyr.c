/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			Pyramid of Numbers
 * Author:			<your name>
 * ----------------------------------------------------------
 * Description:
 * Calculates a pyramid of numbers, i.e., it multiplies a big
 * integer by the number 2, its result by 3, etc. and then
 * returns to the original value by subsequently dividing,
 * again starting by 2, 3, etc.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
#define MAX_DIGITS 80

struct BigInt {
	int digits_count;
  unsigned int digits[MAX_DIGITS];
};
int strtobig_int(const char *str, int len, struct BigInt *big_int)
{
		if(len > 80)
		{
			printf("Error:-1 input to long\n");
			big_int -> digits_count = -1;
			return -1;
		}
		for (int i = 0; i < len; i++) {
		{
			if (str[i] >=  '0' && str[i] <='9')
			{
				big_int->digits[i] = str[i] - '0';

			}
			else
			{
				printf("Error= -2 invalid input\n");
				big_int->digits_count = -2;
				return -2;
			}
		}
		}
		big_int->digits_count = len;
		return len;
}

void print_big_int(const struct BigInt *big_int)
{
	for (int i = 0; i < big_int->digits_count; i++) {
		printf("%d", big_int->digits[i]);
	}
}

void multiply(const struct BigInt *big_int, int factor, struct BigInt *big_result)
{
	factor = 2;
	int uebertrag = 0;
	int len = big_int->digits_count;
	int bigIntNumber = len;
	for (factor = 2; factor < 10; factor++)
	{
		for(int bigIntNumber; bigIntNumber > 0; bigIntNumber--);
		{
			big_result->digits[bigIntNumber] = ((big_int->digits[bigIntNumber] * factor) + uebertrag)%10;
			uebertrag =  ((big_int-> digits[bigIntNumber] * factor) - ((big_int -> digits[bigIntNumber] * factor) % 10))/10;
			print_big_int(big_int);
			printf(" * %d = ",factor);
			print_big_int(big_result);
			printf("\n");
		}
	}
}

void divide(const struct BigInt *big_int, int divisor, struct BigInt *big_result);
//{//**
	//faktor = 0;
	//int rest = 0;
	//int number = 0;;
	//int len = big_int-> digits_count;
	//for (int j = 0; j < count; j++)
	//{
	//	number = big_int->digits[i] * 10 + big_int->digits[i+1];
	//	number =
		//not finishe
	// faktor++;
	//}
  //}
//}
void copy_big_int(const struct BigInt *from, struct BigInt *to)
{
	to->digits_count = from -> digits_count;
	int len = to->digits_count;
	for (int i = 0; i < len; i++)
	{
		to->digits[i] = from-> digits[i];
	}
}

int main(int argc, char *argv[])
{
	struct BigInt big_int;
	struct BigInt result;
  char input[MAX_DIGITS + 1];
  printf("Enter a number:");
  scanf("%s", input);
  int len = strlen(input);
  int charsConvertet = strtobig_int(input, len, &big_int);
	printf("%d Convertet Numbers\n", charsConvertet );
	multiply(&big_int,2, &result);
	return 0;
}
