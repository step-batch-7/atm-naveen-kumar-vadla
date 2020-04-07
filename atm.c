#include <stdio.h>
#include "atm.h"

int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
int denominations_count = sizeof(denominations) / sizeof(*denominations);

unsigned int get_money(unsigned short int money)
{
  unsigned int note_count = 0x00000000;
  unsigned short int remaining_balance = money;
  if (remaining_balance > 31999)
  {
    return note_count;
  }
  for (int index = 0; index < denominations_count; index++)
  {
    note_count = note_count << 4;
    note_count = note_count + (remaining_balance / denominations[index]);
    remaining_balance = remaining_balance % denominations[index];
  }

  return note_count;
}

int print_denominations(unsigned short int money);
int print_denominations(unsigned short int money)
{
  unsigned int notes = get_money(money);
  printf("Amount: Rs. %u\n", money);

  unsigned int divisor = 0x10000000;
  for (int index = 0; index < denominations_count; index++)
  {
    int note_count = notes / divisor;
    note_count &&printf("%2d %s of Rs. %d\n", note_count, note_count > 1 ? "notes" : "note ", denominations[index]);
    notes = notes % divisor;
    divisor = divisor >> 4;
  }
  printf("\n");
  return 0;
}
