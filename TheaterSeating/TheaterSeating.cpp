// TheaterSeating.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "Theater.h"


int main()
{
	const int seats = 9;
	const int rows = 10;

	Theater theater = Theater(seats, rows);
	Theater theater2 = theater;
	theater.display_seating();
	theater.sell_seat(1, 1);
	theater.sell_seat(5, 5);
	Theater theater3 = theater;
	theater.display_seating();
	theater2.display_seating();
	theater3.display_seating();
	theater2 = theater3;
	theater2.display_seating();

    return 0;
}
