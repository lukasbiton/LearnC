/*
Simulate a deck of cards and shuffle it.
*/

#include <stdio.h> // for printf
#include <stdlib.h> // for rand()

typedef enum suit {spade, diamond, heart, clover} suit;
typedef struct card {int pips; suit suit;} card;

void make_deck(card deck[], int total_cards, int cards_per_suit)
{
  // Fill in the deck variable with a full deck of cards
  int i;
  int j;
  card temp_card;

  for (i = 0; i < total_cards; i++)
  {
    // For different values of i, go with different
    temp_card.suit = (i < cards_per_suit * 1)? (0) : (i < cards_per_suit * 2)? \
      (1) : (i < cards_per_suit * 3)? (2) : (3);
    // count all the way for the deck, but only 1-13 for the card number
    temp_card.pips = (i % cards_per_suit) + 1; // So the ace is 1
    deck[i] = temp_card;
  };
}

void print_deck(card deck[], int total_cards)
{
  int i;

  for (i = 0; i < total_cards; i++)
  {
    if (i % 13 == 0) {printf("\n");};
    switch(deck[i].suit)
    {
      case spade: printf("%d of spade\t", deck[i].pips); break;
      case diamond: printf("%d of diamond\t", deck[i].pips); break;
      case heart: printf("%d of heart\t", deck[i].pips); break;
      case clover: printf("%d of clover\t", deck[i].pips); break;
    };
  };
}

void shuffle_deck(card deck[], int total_cards)
{
  // Use the Fisher-Yates shuffle
  // naive shuffle is unbalanced because of how rand works (rand max) since
  // the total number of possible shuffles ordered is not divisble by the
  // number of un-ordered shuffles -> can't get a uniform distribution
  int i;
  int j;
  card saved_card;

  for (i = 0; i < total_cards; i++)
  {
    j = rand() % total_cards;
    saved_card = deck[i];
    deck[i] = deck[j];
    deck[j] = saved_card;
  };
}

int max(int arr[], int len)
{
  // Return the max of an array of ints
  // Use this to obtain the max in the tracked matched pairs
  // In the case the min is 0

  int i;
  int max = 0;

  for (i = 0; i < len; i++)
  {
    if (arr[i] > max) {max = arr[i];}
  };
  return max;
}

int count_ones(int arr[], int len)
{
  // Return the number of times there is 1 in an array.

  int i;
  int count = 0;

  for (i = 0; i < len; i++)
  {
    if (arr[i] == 1) {count++;}
  };
  return count;
}

int main()
{
  int cards_per_suit = 13;
  int total_cards = 52;
  int cards_dealt = 7;
  card deck[total_cards];

  // Need longs to avoid memory errors at run time
  double how_many = 1000000;
  unsigned int i;
  int j;
  int k;
  int max_num_pair;
  int number_ones;
  int num_pair[cards_dealt];

  double no_pair = 0;
  double one_pair = 0;
  double two_pairs = 0;
  double three_of_a_kind = 0;
  double full_house = 0;
  double four_of_a_kind = 0;

  make_deck(deck, total_cards, cards_per_suit);
  print_deck(deck, total_cards);
  printf("\n\n");
  shuffle_deck(deck, total_cards);
  print_deck(deck, total_cards);
  printf("\n\n");

  // Let's assume we draw a hand by dealing it the first 7 cards before
  // reshuffling the deck
  for (i = 0; i < how_many - cards_dealt; i++)
  {
    for (k = 0; k < cards_dealt; k++)
    {
      num_pair[k] = 0;

      // Compare current card k against remaining cards only
      for (j = 1; j < cards_dealt - 1 - k; j++)
      {
        num_pair[k] += deck[k].pips == deck[k + j].pips;
      }
    }

    max_num_pair = max(num_pair, cards_dealt - 1);
    number_ones = count_ones(num_pair, cards_dealt - 1);

    switch(max_num_pair)
    {
      case 3: four_of_a_kind++; break;
      case 2:
      {
        // If there are 2 or more 1s -> there is another pair
        if (number_ones >= 2) {full_house++;}
        else {three_of_a_kind++;}
        break;
      }
      case 1:
      {
        // If there are 2 or more 1s -> there is another pair
        if (number_ones >= 2) {two_pairs++;}
        else {one_pair++;}
        break;
      }
      case 0: no_pair++; break;
    }

    max_num_pair = 0;
    number_ones = 0;
    // Shuffle before dealing the top 7 cards again
    shuffle_deck(deck, total_cards);
  }

  printf("no_pair: %lf\n", no_pair/how_many);
  printf("one_pair: %lf\n", no_pair/how_many);
  printf("two_pairs: %lf\n", two_pairs/how_many);
  printf("three_of_a_kind: %lf\n", three_of_a_kind/how_many);
  printf("full_house: %lf\n", full_house/how_many);
  printf("four_of_a_kind: %lf\n", four_of_a_kind/how_many);

  return 0;
}
