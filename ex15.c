#include <stdio.h>

int main(int argc, char *argv[])
{
  // create two arrays
  int ages[] = {23, 43, 12, 89, 2};
  char *names[] = {
    "Alan", "Frank", "Mary", "John", "Lisa"
  };

  // safely get size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // Use indexing
  for(i = 0; i < count; i++) {
    printf("%s has %d years alive\n", names[i], ages[i]);
  }

  printf("-----\n");

  // setup pointers to the start of the array
  int *cur_age = ages;
  char **cur_name = names;

  // use pointers
  for(i = 0; i < count; i++) {
    printf("%s is %d years old\n", *(cur_name + i), *(cur_age + i));
  }

  printf("-----\n");

  // using pointers as arrays
  for(i = 0; i < count; i++) {
    printf("%s is %d years old again\n", cur_name[i], cur_age[i]);
  }

  printf("----\n");

  // finally using crazy pointers
  for(cur_name = names, cur_age = ages; 
        (cur_age - ages) < count;
        cur_name++, cur_age++)
  {
    printf("%s lived %d years so far\n",*cur_name, *cur_age);
  }

  return 0;
}



