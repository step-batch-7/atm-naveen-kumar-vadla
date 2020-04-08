#include "atm.h"

count get_money(cash money)
{
  currency denominations = DENOMINATIONS_LIST;
  count note_count = 0x00000000;
  cash remaining_balance = money;

  if (remaining_balance > LIMIT)
  {
    return note_count;
  }
  FOR_LOOP(0, ARRAY_SIZE(denominations))
  {
    note_count = note_count << 4;
    note_count = note_count + (remaining_balance / denominations[i]);
    remaining_balance = remaining_balance % denominations[i];
  }

  return note_count;
}
