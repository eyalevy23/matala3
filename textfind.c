#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30

int isSubStringWithStrikes(char *keyword, char *compare);
int endWithNewLine(char *word);
int splitLine(char* line, char **array);
void userChoice_B(char **array, char *keyword, int len);
void userChoice_A(char line[], char *keyword);
int endWithNewLine(char *word);

void userChoice_B(char **array, char *keyword, int len)
{
    for (int i = 0; i < len; i++)
    {
        if(isSubStringWithStrikes(keyword, array[i]))
        {
            printf("%s", array[i]);
            if (endWithNewLine(array[i]) == 0)
            {
                printf("\n");
            }
        }
    }
    
}

void userChoice_A(char line[], char *keyword){
    if (strstr(line, keyword) != NULL){
        printf("%s", line);
    }
}

int endWithNewLine(char *word){
    if (strcmp(word + strlen(word) - 1, "\n") == 0)
    {
        return 1;
    }
    return 0;
}

int splitLine(char* line, char **array)
{
    int i = 0;
    char *p = strtok (line, " ");
    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, " ");
    }
    return i;
}

int isSubStringWithStrikes(char *keyword, char *compare)
{
    int keywordLen = strlen(keyword);
    int compareLen = strlen(compare);
    int strikes = 0;
    int j = 0;

    if((compareLen > keywordLen+1) || (compareLen < keywordLen))
    {
        return 0;
    }

    for(int i = 0; i < compareLen && strikes < 2; i++){
        if(compare[i] != keyword[j]){
            strikes++;
        } else{
            j++;
        }

    }
    if(strikes > 1){
        return 0;
    } return 1;
}

int main ()
{
    char *array[8] = {0};
    char leeter[WORD];
    char keyword[WORD];
    int line = 1;
    char strLine[LINE];
    char copyLine[LINE];
    int len;
    char* b = "b\n";
    char* a = "a\n";

    while(fgets(strLine, LINE , stdin) != NULL)
    {   
        strcpy(copyLine, strLine);
        len = splitLine(strLine,array);

        if(line == 1){
            strcpy(keyword, array[0]);
            strcpy(leeter, array[1]);
        }

        if(strcmp(leeter, b) == 0 && line > 2){
            userChoice_B(array, keyword, len);
        }

        if(strcmp(leeter, a) == 0 && line > 2){
            userChoice_A(copyLine, keyword);
        }
        bzero(strLine, sizeof(strLine));
        line++;
        
    }    
    return 0;
}