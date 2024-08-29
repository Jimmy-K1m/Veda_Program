/* 
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
time_t* cur_time = (time_t*) malloc(sizeof(time_t));
time(cur_time);
printf("Current Time = %d\n", (int) *cur_time);
return 0;
}
*/

#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <stdlib.h>
int main(void)
{
time_t* cur_time=(time_t*) malloc(sizeof(time_t));
time(cur_time);
printf("Current Time = %d\n", (int) *cur_time);
char* cur_string;
cur_string=ctime(cur_time);
printf("Current Time String = %s\n",cur_string);
return 0;
}