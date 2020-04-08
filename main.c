#include <stdio.h>
#include "atm.h"

void display_notes(count notes);
void display_notes(count notes)
{
  count divisor = 0x10000000;
  currency denominations = DENOMINATIONS_LIST;
  FOR_LOOP(0, ARRAY_SIZE(denominations))
  {
    count note_count = notes / divisor;
    notes = notes << 4;
    note_count &&printf("%2d %s of Rs. %d\n", note_count, note_count > 1 ? "notes" : "note ", denominations[i]);
  }
  printf("\n");
}

int main(void)
{
  cash amounts[] = {1, 10, 39, 589, 2590, 31999};
  FOR_LOOP(0, ARRAY_SIZE(amounts))
  {
    count notes = get_money(amounts[i]);
    printf("Amount: Rs. %u\n", amounts[i]);
    display_notes(notes);
  }

  return 0;
}
