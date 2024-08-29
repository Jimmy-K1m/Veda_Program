 
char** command_parse(char*);
void run_command(char** arglist);
void command_freelist(char **arglist);
int is_builtin(char** arg);
int is_background(char ** arglist);