/* This function should accept the amount needed in cash 
   as input and return the number of notes per each of
   the following denominations:
   2000, 500, 100, 50, 20, 10, 5, 1
   The function can dispense a maximum of 15 notes per denomination. 
   Each hexa digit represents the number of notes for that denomination.

   Ex: 00000100 represents one 10 Rs note

   So the largest input you can accept based on the above denomination is 
   31999. Larger values than that should return 0.

  Here are some amounts and their return values
      1 0x00000001
     10 0x00000100
     39 0x00001114
    589 0x01011114
   2590 0x11012000
  31999 0xf3412014
*/

#define LIMIT 31999
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(*array))
#define DENOMINATIONS_LIST { 2000, 500, 100, 50, 20, 10, 5, 1 }
#define FOR_LOOP(startWith,condition) for (int i = startWith; i < condition; i++)

typedef unsigned short int cash;
typedef unsigned int count;
typedef int currency[];

count get_money(cash);
