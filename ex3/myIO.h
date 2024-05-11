#ifndef MY_IO_H
#define MY_IO_H

#define MAXBUF 1024
#define Rev 0
#define Nor 1
#define INFIX 0
#define PREFIX 1
#define POSTFIX 2

void _check_args(int argc, char **argv, int *notation, int *action);
int _get_input(char **tokens);
void _free_tokens(char **tokens, int tokenLens);
void _exp_print(char **expression, int expLens, int mode);
void _calcResult_print(int result);
void _error_message(int condition);

#endif /* MY_IO_H */
