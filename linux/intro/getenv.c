#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
char *homedir, filename[80];
FILE*fp;
homedir = getenv("HOME");
printf("%s", homedir);
strcpy(filename, homedir);
strcat(filename, "/test.log");

if((fp=fopen(filename, "w"))==NULL) {
    perror("fopen");
    exit(1);
}
fwrite("getenv test\n", 12, 1, fp);
fclose(fp);
return 0;

}