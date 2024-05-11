#ifndef MY_CONV_H
#define MY_CONV_H

#define INFIX 0
#define PREFIX 1
#define POSTFIX 2
#define SAME 0
#define LOWER -1
#define HIGHER 1

void infixToPrefix(char **tokens, int tokenLens);
void infixToPostfix(char **tokens, int tokenLens);
void postfixToInfix(char **tokens, int tokenLens);
void postfixToPrefix(char **tokens, int tokenLens);
void prefixToInfix(char **tokens, int tokenLens);
void prefixToPostfix(char **tokens, int tokenLens);

#endif /* MY_CONV_H */
