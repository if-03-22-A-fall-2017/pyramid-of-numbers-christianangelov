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
void copy_big_int(const struct BigInt *from, struct BigInt *to)
{

	if (from->digits_count > to->digits_count) {
		to->digits_count = from-> digits_count;
	}
	for (int i = from->digits_count -1; i < from->digits_count; i++) {
		to->digits[i] = from->digits[i];
	}
}
int strtobig_int(const char *str, int len, struct BigInt *big_int)
{
		if(len > MAX_DIGITS)
		{
			printf("Error:-1 input to long\n");
			big_int -> digits_count = -1;
			return -1;
		}
		int nextDigit= 0;
		for (int i = len-1; i >= 0; i--) {

			if (str[i] >=  '0' && str[i] <='9')
			{
				big_int->digits[nextDigit] = str[i] - '0';
				nextDigit++;
			}
			else
			{
				printf("Error= -2 invalid input\n");
				big_int->digits_count = -2;
				return nextDigit;
			}
		}
		big_int->digits_count = len;
		return len;
}

void print_big_int(const struct BigInt *big_int)
{
	for (int i = big_int->digits_count - 1; i >= 0 ; i--)
	{
		printf("%d", big_int->digits[i]);
	}
}

void multiply(const struct BigInt *big_int, int factor, struct BigInt *big_result)
{
	int uebertrag = 0;
	int len = big_int->digits_count;

	for(int bigIntNumber = 0; bigIntNumber < len ;bigIntNumber++)
	{
		int currentDigit = big_int->digits[bigIntNumber];
		int number = currentDigit * factor + uebertrag;
		big_result->digits[bigIntNumber] = number % 10;
		uebertrag = number / 10;
	}
	if (uebertrag > 0)
	{
			big_result->digits_count = len+1;
			big_result->digits[len]= uebertrag;
	}
	else
	{
		big_result->digits_count = len;
	}

}
void divide(const struct BigInt *big_int, int divisor, struct BigInt *big_result)
{
	int rest = 0;

	int len = big_int-> digits_count;
	for (int j = len; j >= 0; j--)
	{
		int currentDigit = big_result->digits[j];
		int number =(currentDigit + rest * 10) / divisor;
		if(number == 0)
		{
			rest = currentDigit % 10;
		}
		else{
			rest = (currentDigit + rest *10) -(number * divisor);
		}
		big_result->digits[j] = number % 10;
	}
	if (rest > 0) {
		big_result->digits_count = len;
		for (int i = len; i >= 0; i--) {
			int cross = big_result->digits[i];
			big_result->digits[i+1] = cross;
		}
		big_result->digits[len + 1] = rest;
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
	for(int factor = 2; factor < 10; factor++)
	{
		multiply(&big_int, factor, &result);
		print_big_int(&big_int);
		printf(" * %d = ",factor);
		print_big_int(&result);
		printf("\n");
		copy_big_int(&big_int,&result);
	}
	for (int divisor = 9; divisor >= 2; divisor--)
	{
		divide(&big_int,divisor,&result);
		print_big_int(&big_int);
		printf(" / %d = ", divisor);
		print_big_int(&result);
		printf("\n");
		copy_big_int(&big_int,&result);
	}
	return 0;
}
