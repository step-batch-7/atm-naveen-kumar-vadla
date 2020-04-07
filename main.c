#include <stdio.h>
#include "atm.h"

int main(void)
{
  unsigned short int amounts[] = {1, 10, 39, 589, 2590, 31999};
  for (int i = 0; i < sizeof(amounts) / sizeof(*amounts); i++)
  {
    unsigned int notes = get_money(amounts[i]);
    printf("Amount: Rs. %u\n", amounts[i]);
    print_denominations(notes);
  }

  return 0;
}
