#include <stdio.h>
#include <cs50.h>


int main(void)
{
	long long credit_number;
	long long credit_number_copy;

	do
	{
		credit_number = get_long_long("Number: ");
  } while (credit_number <= 0);

  // copying credit cards number
	credit_number_copy = credit_number;

  int residue1;
	int residue2;
	int iteration_number = 0;
	int product = 0;
	int sum_digits_from_product = 0;
	int final_sum = 0;
	int sum_digits_not_multiplied_by_2 = 0;
	int residue1_copy;

  while (credit_number > 0) 
  {

		iteration_number = iteration_number + 1;
		residue1 = credit_number % 10;

		if (iteration_number % 2 == 0)
		{
			// calculate residue
			product = residue1 * 2;

      while (product > 0)
			{
      // calculate residue
				residue2 = product % 10;
				// adding digits resulting from product1
				sum_digits_from_product = sum_digits_from_product + residue2;
				product = (product - residue2) / 10;
			}
    }
		else
		{
			// adding digits which are 1, 3, 5,... in the string credit number, counting from the beginning
			sum_digits_not_multiplied_by_2 = sum_digits_not_multiplied_by_2 + residue1;
    }
		credit_number = (credit_number - residue1) / 10;
  }

	final_sum = sum_digits_from_product + sum_digits_not_multiplied_by_2;

  int iter = 0;
	int first_number;
	int second_number;

  while (credit_number_copy > 0)
	{

		iter = iter + 1;
		residue1_copy = credit_number_copy % 10;
		if (iter == (iteration_number - 1))
		{
			second_number = residue1_copy;
		}
		if (iter == iteration_number)
		{
			first_number = residue1_copy;
		}
		credit_number_copy = (credit_number_copy - residue1_copy) / 10;
	}

	if (final_sum % 10 == 0)
	{
		if (iteration_number == 15)
		{

      if (first_number == 3 && (second_number == 4 || second_number == 7))
			{
				printf("AMEX\n");
			}
			else
			{
				printf("INVALID\n");
			}
    }

		else if (iteration_number == 13)
		{
      if (first_number == 4)
			{
				printf("VISA\n");
			}
			else
			{
				printf("INVALID\n");
			}
    }

    else if (iteration_number == 16)
		{

      if (first_number == 5 && (second_number == 1 || second_number == 2  || second_number == 3  || second_number == 4  || second_number == 5))
			{
				printf("MASTERCARD\n");
			}
			else if (first_number == 4)
			{
				printf("VISA\n");
			}

			else
			{
				printf("INVALID\n");
			}
    }

		else
		{
			printf("INVALID\n");
		}
  }

  else
	{
		printf("INVALID\n");
	}

  return 0;
}
