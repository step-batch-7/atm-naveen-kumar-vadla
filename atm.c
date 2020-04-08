#include "atm.h"

unsigned int get_money(unsigned short int money)
{
  int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  int denominations_count = sizeof(denominations) / sizeof(*denominations);
  
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
