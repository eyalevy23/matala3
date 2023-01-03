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
        //check if the word is substring of the keyword with one strikes
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

//print the line if the keyword is substring of the line
void userChoice_A(char line[], char *keyword){
    if (strstr(line, keyword) != NULL){
        printf("%s", line);
    }
}

//check if the word end with new line
int endWithNewLine(char *word){
    if (strcmp(word + strlen(word) - 1, "\n") == 0)
    {
        return 1;
    }
    return 0;
}

//get line and split to array of strings
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

//check if keywords is substring of the compare word so much of subtracting one letter
int isSubStringWithStrikes(char *keyword, char *compare)
{
    int keywordLen = strlen(keyword);
    int compareLen = strlen(compare);
    int strikes = 0;
    int j = 0;

    //check if the length of the compare word is in the range of the keyword
    if(endWithNewLine(compare))
    {
        compareLen --;
    }
    if((compareLen > keywordLen+1) || (compareLen < keywordLen))
    {
        return 0;
    }
    if(compareLen == keywordLen)
    {
        strikes++;
    }

    //check if the compare word is substring of the keyword with one strikes
    for(int i = 0; i < compareLen && strikes < 2; i++){
        if(compare[i] != keyword[j]){
            strikes++;
        } else
        {
            j++;
        }
    }
    return strikes <= 1; //if strikes in [0,1] return True
}

int main ()
{
    char *array[20] = {0};
    char letter[WORD];
    char keyword[WORD];
    int line = 1;
    char strLine[LINE];
    char copyLine[LINE];
    int len;
    char* b = "b\n";
    char* a = "a\n";
    
    while(fgets(strLine, LINE , stdin) != NULL)//read input by line
    {   
        strcpy(copyLine, strLine); //copy line to string
        len = splitLine(strLine,array); //split the input to array of string

        if(line == 1){ //find the keyword and the user letter choice
            strcpy(keyword, array[0]);
            strcpy(letter, array[1]);
        }

        if(strcmp(letter, b) == 0 && line > 2){ //case user choose b
            userChoice_B(array, keyword, len);
        }

        if(strcmp(letter, a) == 0 && line > 2){//case user choose a
            userChoice_A(copyLine, keyword);
        }
        bzero(strLine, sizeof(strLine));//reset the line
        line++;
        
    }    
    return 0;
}