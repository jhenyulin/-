#ifndef MY_CALC_H
#define MY_CALC_H

#define SAME 0
#define LOWER -1
#define HIGHER 1
#define TRUE 1
#include <string.h>  // For strcmp function
#undef expression 
static inline int isAddOrMinus(char* oper) {return (strcmp(oper, "+") == 0 || strcmp(oper, "-") == 0);}
int precedCmp(char* oper1, char* oper2);
int infixCalc(char** tokens, int tokenLens);
int prefixCalc(char** tokens, int tokenLens);
int postfixCalc(char** tokens, int tokenLens);
int str2Num(char* s);

#endif /* MY_CALC_H */
