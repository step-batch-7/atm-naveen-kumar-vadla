#include "atm.h"

count get_money(cash money)
{
  int denominations[] = DENOMINATIONS_LIST;
  count note_count = 0x00000000;
  cash remaining_balance = money;

  if (remaining_balance > LIMIT)
  {
    return note_count;
  }

  for (int index = 0; index < ARRAY_SIZE(denominations); index++)
  {
    note_count = note_count << 4;
    note_count = note_count + (remaining_balance / denominations[index]);
    remaining_balance = remaining_balance % denominations[index];
  }

  return note_count;
}
