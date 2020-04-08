#include <stdio.h>
#include "atm.h"

int display_notes(unsigned int notes);
int display_notes(unsigned int notes)
{
  unsigned int divisor = 0x10000000;
  int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  for (int index = 0; index < ARRAY_SIZE(denominations); index++)
  {
    int note_count = notes / divisor;
    notes = notes << 4;
    note_count &&printf("%2d %s of Rs. %d\n", note_count, note_count > 1 ? "notes" : "note ", denominations[index]);
  }
  printf("\n");
  return 0;
}

int main(void)
{
  unsigned short int amounts[] = {1, 10, 39, 589, 2590, 31999};
  for (int i = 0; i < ARRAY_SIZE(amounts); i++)
  {
    unsigned int notes = get_money(amounts[i]);
    printf("Amount: Rs. %u\n", amounts[i]);
    display_notes(notes);
  }

  return 0;
}
