#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 4096

#define TRASH
#ifdef TRASH
#undef TRASH
#endif

#define specialPrint(n) printf(#n) //把n變成字符串"n"
#define NOT_TRUE 0
#define FUNCTION_CALLED() printf("%s\n", __func__)
#define SQUARE(x) ((x) * (x))
#define strAdd(dest, src) sprintf(dest + strlen(dest), "%s", src)//將一個字符串（src）添加到另一個字符串（dest）的尾部
                          //(dest+src)+src+src...... (strlen(dest+=src))
//add some directives below
#define REMOVE_HowToRemoveME
// try to remove this include
#ifdef REMOVE_HowToRemoveME

#else
#include "HowToRemoveME??"
#endif
//add some directives above

void Hunting() {
    FUNCTION_CALLED();  // this should print the function name with a new-line character at the end
}

void MonsterRepeat() {
    FUNCTION_CALLED();  // same thing in Hunting
}

int main() {
    int tmpDigit;
    int len;
    int monsterNum;
    int blood, deducted_blood, medicineNum;
    int repeatNum;
    char tmpString[MAXLINE];
    char monsterName[MAXLINE];
    char repeatMonsterName[MAXLINE];
    char inputLine[MAXLINE];
    char *inputPtr;

    while (fgets(inputLine, MAXLINE, stdin) != NULL) {  // read until EOF
        inputPtr = inputLine;
        if (isdigit(inputPtr[0])) {  // digit situation //檢查是否為10進位 <ctype.h>
            Hunting();
            blood = 100;
            monsterNum = 0;

            sscanf(inputPtr, "%d%n", &medicineNum, &len);  // get the number and the length of the number
            blood += 50 * medicineNum;
            inputPtr += len;

            while (sscanf(inputPtr, "%s", tmpString) != EOF) {  // get the number in string type first
                sscanf(tmpString, "%d", &tmpDigit);  // convert the number into int type

                deducted_blood = SQUARE(tmpDigit % 4 + 5) + 6;  // square means x^2
                if (blood >= (deducted_blood + 30)) {
                    blood -= deducted_blood;
                    monsterNum++;
                } else {
                    break;
                }

                len = strlen(tmpString);  // to get next number, need the pointer move
                inputPtr += len;
                while (*inputPtr && isspace(*inputPtr) == NOT_TRUE) {  // to the next number
                    inputPtr++;
                }                 //檢查是否為空白字符
            }
            
            specialPrint(The total hunting Monster Number is:);  // this equals to printf("The total hunting Monster Number is")
            printf(" %d\n", monsterNum);
        } else {
            MonsterRepeat();
            sscanf(inputPtr, "%s %d", monsterName, &repeatNum); // get one string and one integer
            sscanf(monsterName, "%s", repeatMonsterName);
            for (int i = 0; i < repeatNum-1; i++) strAdd(repeatMonsterName, monsterName);  // repeatMonsterName = repeatMonsterName + monsterName
                                                                                         // hint: sprintf

            #ifdef TRASH
                printf("Ho Ho Ho, How to remove me???");  // try to remove this
            #endif
        
            specialPrint(Moooooooooonster Name:);  // this equals to printf("Moooooooooonster Name:")
            printf(" %s\n", repeatMonsterName);
        }
    }

    return 0;
}
