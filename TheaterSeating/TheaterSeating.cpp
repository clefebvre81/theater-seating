// TheaterSeating.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

#include "Menu.h"
#include "Theater.h"


// Prototypes
void SellSeat(Theater &theater);
void SellGroup(Theater &theater);


int main()
{
	// Constant variables
	const int seats = 9;
	const int rows = 10;

	bool keep_going = true;

	// Create theater
	Theater theater = Theater(seats, rows);

	// Create Menu
	Menu menu = Menu();
	
	while (keep_going)
	{
		menu.GetUserChoice();
		system("cls");
		switch (menu.GetMenuChoice())
		{
			case Menu::MenuOptions::kShowSeating:
			{
				theater.DisplaySeating();
				break;
			}
			case Menu::MenuOptions::kSellSeat:
			{
				// TODO: Sell Seat
				SellSeat(theater);
				break;
			}
			case Menu::MenuOptions::kSellGroup:
			{
				// TODO: Sell Group of seats
				SellGroup(theater);
				break;
			}
			case Menu::MenuOptions::kStats:
			{
				// TODO: Show stats
				puts("Comming Soon!");
				break;
			}
			case Menu::MenuOptions::kExit:
			{
				puts("Exiting...");
				puts("Please Come Again Soon!");
				keep_going = false;
				break;
			}
		}
	}

    return 0;
}


//
// Sell Seats
void SellSeat(Theater &theater)
{
	theater.DisplaySeating();

	char row = '\0';
	std::cout << "Enter Row: ";
	std::cin >> row;

	int seat = 0;
	std::cout << "Enter Seat Number: ";
	std::cin >> seat;
	seat -= 1;

	int introw = theater.ConvertRowToInt(row);
	if (theater.ValidateSeat(introw, seat))
	{
		if (theater.SeatAvailible(introw, seat))
		{
			theater.DisplaySeating(introw, seat, seat + 1);
			char correct = '\n';
			std::cout << "Is this selection correct (y,n): ";
			std::cin >> correct;
			if (correct == 'y')
			{
				theater.SellSeat(introw, seat);
			}
		}
		else
		{
			std::cout << "Seat Unavailible!\n";
		}
	}
	else
	{
		std::cout << "Invalid Seat Selected!\n";
	}
}


//
// Sell Group of seats
void SellGroup(Theater &theater)
{
	theater.DisplaySeating();

	char row = '\0';
	std::cout << "Enter Row: ";
	std::cin >> row;

	int seat_start = 0;
	std::cout << "Enter Starting Seat Number: ";
	std::cin >> seat_start;
	seat_start -= 1;

	int ticket_count = 0;
	std::cout << "How Many Seats: ";
	std::cin >> ticket_count;

	int introw = theater.ConvertRowToInt(row);
	if (theater.ValidateGroup(introw, seat_start, seat_start))
	{
		if (theater.GroupAvailible(introw, seat_start, ticket_count))
		{
			theater.DisplaySeating(introw, seat_start, seat_start + ticket_count);
			char correct = '\n';
			std::cout << "Is this selection correct (y,n): ";
			std::cin >> correct;
			if (correct == 'y')
			{
				theater.SellGroup(introw, seat_start, ticket_count);
			}
		}
		else
		{
			std::cout << "Group Unavailible!\n";
		}
	}
	else
	{
		std::cout << "Invalid Seat Selected!\n";
	}
}
