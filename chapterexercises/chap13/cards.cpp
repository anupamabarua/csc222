#include <string>
#include <iostream>
#include "cards.h"
using namespace std;



Card::Card() {
    suit = NONE; rank = JOKER;
}

Card::Card(Suit s, Rank r) {
    suit = s; rank = r;
}

std::string Card::to_string() const
{
    vector<string> suit_strings = {"None", "Clubs", "Diamonds", "Hearts", "Spades"};
    vector<string> rank_strings = {"Joker", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    if (rank == 0) return rank_strings[rank];
    return rank_strings[rank] + " of " + suit_strings[suit];
}

bool Card::operator==(const Card& c2) const
{
    return (rank == c2.rank && suit == c2.suit);
}


bool Card::operator>(const Card& c2) const
{
    if (suit > c2.suit) return true;
	if (suit < c2.suit) return false;
	
	if (rank > c2.rank) return true;
	if (rank < c2.rank) return false;

	return false;
}


bool Card::operator<(const Card& c2) const
{
    if (suit < c2.suit) return true;
    if (suit > c2.suit) return false;

    if (rank < c2.rank) return true;
    if (rank > c2.rank) return false;

    return false;
}

bool Card::operator>=(const Card& c2) const
{
	if (suit > c2.suit) return true;
	if (suit < c2.suit) return false;

	if (rank > c2.rank) return true;
	if (rank < c2.rank) return false;

	return true;
}

bool Card::operator<=(const Card& c2) const
{
	if (suit < c2.suit) return true;
    if (suit > c2.suit) return false;

    if (rank < c2.rank) return true;
    if (rank > c2.rank) return false;

    return true;
}


bool Card::operator!=(const Card& c2) const
{
    return (rank != c2.rank && suit != c2.suit);
}
