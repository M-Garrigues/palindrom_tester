#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef struct StringS{
    int nbChar;
    int tailleMax;
    char * string;
}String;

void initString (String * str);
void ajoutString(String * str, char c);
void freeString (String * str);
int checkPalyndromeStp(String * str);


int main()
{
	FILE * texte = NULL;
    String strChar;
    char caractereActuel = 0;
    int i;

    initString(&strChar);

    texte = fopen("perec.txt", "r");

    if(texte == NULL)
    {
        printf("Fichier introuvable, vérifiez le chemin d'accès. \n");
        return EXIT_FAILURE;
    }


    while (caractereActuel != EOF)
    {
        caractereActuel = fgetc(texte);

        if (caractereActuel <= 'z' && caractereActuel >= 'a')
        {
            ajoutString(&strChar,caractereActuel);
        }

    }
    fclose(texte);


    printf("\n\nTexte condense:  ");

    for (i = 0; i < strChar.nbChar; ++i)
    {
        printf("%c", strChar.string[i]);
    }

    if (checkPalyndromeStp(&strChar)==1)
        printf("\n\nC'est un palindrome.\n\n");
    else
        printf("\n\nCe n'est pas un palindrome\n\n");

    freeString(&strChar);
    return 0;
}





void initString(String * str)
{
    str->nbChar = 0;
    str->tailleMax = 2;
    str->string = malloc((str->tailleMax)*sizeof(char));
    assert(str->string != NULL);
}

void ajoutString(String * str, char c)
{
    if(str->nbChar == str->tailleMax)
    {
    	char * temp;
        int i;

        str->tailleMax *= 2;

        temp = str->string;

        str->string = malloc(str->tailleMax*(sizeof(char)));


        for(i=0; i<str->nbChar; i++)
        {
            str->string[i] = temp[i];
        }

        free(temp);
    }

    str->string[str->nbChar] = c;

    str->nbChar++;
}


void freeString (String * str)
{
    str->nbChar = 0;
    str->tailleMax = 0;
    free(str->string);
}


int checkPalyndromeStp(String * str)
{
    int i;
    int poulet = (str->nbChar - (str->nbChar%2))/2;

    for(i=0; i<poulet; i++)
    {
        printf("%c  %c\n", str->string[i], str->string[str->nbChar - i -1]);
        if(str->string[i] != str->string[str->nbChar-i-1])
            return 0;
    }
    return 1;
}


/*Code par Mathieu GARRIGUES, pendant une journée très chiante.*/
