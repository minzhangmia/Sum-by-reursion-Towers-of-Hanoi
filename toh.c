//***************************************************************************************
//
 //! \file     toh.c
 //! \brief    Three-pillar Hanno tower with n plates
 //! \details  Details is implemented recursively
 //! \author   MIN ZHANG
 //! \version  1
 //! \date     2020-10-20
//
//***************************************************************************************

#include<stdio.h>

void move(int i, char a, char b);				  /* function prototype */
void Hanoi(int i, char a, char b, char c);		  /* function prototype */

//***************************************************************************************
//
//!\brief        main function
//!\details      program unique entry
//!\param argc   command number of arguments
//!\param argv   command parameter pointer array
//!\return       program execution successful or not
//!     \retval  0 program executed successfully
//!     \retval  1 failed to execute
//
//***************************************************************************************

int main(int argc, char* argv[])
{
	Hanoi(4, 'A', 'B', 'C');

	return 0;
}

//***************************************************************************************
//
 //! \brief       print tray movement information
 //! \param i     ith plate
 //! \param a,b   moves from A to B
//
//***************************************************************************************

void move(int i, char a, char b)
{
	printf("Move disk %d from %c to %c\n", i, a, b);
}

//***************************************************************************************
//
 //!\brief       resolution of the Tower of Hannock
 //!\details     recursively prints out the steps to solve the Tower of Hannot
 //!\param i     have a total i plates
 //!\param a,b,c The pillars are called A, B, and C
 //!\attention   Since this is implemented recursively, the I should not be too large
 //
//***************************************************************************************

void Hanoi(int i, char a, char b, char c)
{
	if (i == 1)
		move(i, a, c);
	else
	{
		Hanoi(i - 1, a, c, b);
		move(i, a, c);
		Hanoi(i - 1, b, a, c);
	}
}