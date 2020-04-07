#include <stdio.h>
#include "atm.h"

unsigned int get_money(unsigned short int money)
{
  unsigned int note_count = 0x0;
  unsigned short int remaining_balance = money;
  unsigned int no_of_notes = 0;

  if (money > 31999)
  {
    return note_count;
  }

  no_of_notes = remaining_balance / 2000;
  remaining_balance = remaining_balance % 2000;
  note_count = note_count + (0x10000000 * no_of_notes);

  no_of_notes = remaining_balance / 500;
  remaining_balance = remaining_balance % 500;
  note_count = note_count + (0x01000000 * no_of_notes);

  no_of_notes = remaining_balance / 100;
  remaining_balance = remaining_balance % 100;
  note_count = note_count + (0x00100000 * no_of_notes);

  no_of_notes = remaining_balance / 50;
  remaining_balance = remaining_balance % 50;
  note_count = note_count + (0x00010000 * no_of_notes);

  no_of_notes = remaining_balance / 20;
  remaining_balance = remaining_balance % 20;
  note_count = note_count + (0x00001000 * no_of_notes);

  no_of_notes = remaining_balance / 10;
  remaining_balance = remaining_balance % 10;
  note_count = note_count + (0x00000100 * no_of_notes);

  no_of_notes = remaining_balance / 5;
  remaining_balance = remaining_balance % 5;
  note_count = note_count + (0x00000010 * no_of_notes);

  no_of_notes = remaining_balance / 1;
  remaining_balance = remaining_balance % 1;
  note_count = note_count + (0x00000001 * no_of_notes);

  return note_count;
}
