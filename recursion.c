//***************************************************************************************
//
 //! \file     recursion.c
 //! \brief    Calculate the sum of squares of all integers from 1 to n, where n is not less than 1
 //! \details  Use recursion and tail recursion to implement
 //! \author   ZHANG MIN
 //! \version  1
 //! \date     2020-10-20
//
//***************************************************************************************

#include<stdio.h>

long int sum_sq_recur(const long int n);					  /* function prototype */
long int sum_sq_tail_recur(const long int n, long int sum);	  /* function prototype */

//***************************************************************************************
//
//! \brief        main function
//! \details      main function
//! \param argc   command number of arguments
//! \param argv   command parameter pointer array
//! \return       program execution successful or not
//!     \retval   0 program executed successfully
//!     \retval   1 failed to execute
//
//***************************************************************************************

int main(int argc, char* argv[])
{
	long int i = 5;
	printf("Sum of squares from 1 to %ld using recursion is %ld\n", i, sum_sq_recur(i));                   /* output information and the sum of the squares of all integers from 1 to n using recursion */
	printf("Sum of squares from 1 to %ld using tail recursion is %ld\n", i, sum_sq_tail_recur(i, 0));

	return 0;
}

//***************************************************************************************
//
 //! \brief       calculated squares and recursive version
 //! \details      this function evaluates the square of all positive integers from 1 to n by a recursive implementation
 //! \param n     calculates the square of all positive integers from 1 to n
 //! \return      program calculated results
 //!   \retval    natural number program execution normal, calculated results
 //!	 \retval    -1	passes in n as a negative number  
 //! \attention   since this is done recursively, where n should not be too large, otherwise the stack will overflow; And because long ints are used here to store data, too large an n can also cause an overflow
//
//***************************************************************************************

long int sum_sq_recur(const long int n)
{
	if (n < 0)return -1;
	if (n == 0)	return 0;
	return n * n + sum_sq_recur(n - 1);
}

//***************************************************************************************
//
 //! \brief       calculated squares and tails recursive version
 //! \details      this function computates the sum of the squares of all positive integers from 1 to n by a tail recursive implementation
 //! \param n     calculates the square of all positive integers from 1 to n
 //! \return      program calculated results
 //!   \retval    natural number program execution normal, calculated results
 //!   \retval    -1	passes in n as a negative number
 //! \attention   since long int is used here to store data, too much n will also cause overflow
//
//***************************************************************************************

long int sum_sq_tail_recur(const long int n, long int sum)
{
	if (n < 0)return -1;
	if (n == 0)	return sum;
	return sum_sq_tail_recur(n - 1, sum + n * n);
}
