#include<stdio.h>
#include<stdlib.h>

void main()
{
    char str[200];
    int i,vowels=0,consonants=0, spaces=0;
    int vowel_words = 0;
    int consonant_words = 0;
    
 
    printf("Enter a string\n");
    fgets(str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' ||str[i]=='o' || str[i]=='u' || str[i]=='A' ||str[i]=='E' || str[i]=='I' || str[i]=='O' ||str[i]=='U')
        {
            vowels++;
        }
        else if((str[i]>='a'&& str[i]<='z') || (str[i]>='A'&& str[i]<='Z'))
        {
            consonants++;
        }
        else if (str[i]==' ')
        {
            spaces++;
        }
    }

	for(i=0;str[i]!='\0';i++)
	    {
        if(str[i] == ' ' && (str[i + 1]=='a' || str[i + 1]=='e' || str[i + 1]=='i' ||str[i + 1]=='o' || str[i + 1]=='u' || str[i + 1]=='A' ||str[i + 1]=='E' || str[i + 1]=='I' || str[i + 1]=='O' ||str[i + 1]=='U'))
        {
            vowel_words++;
        }
        else if(str[i] == ' ' && ((str[i + 1]>='a'&& str[i + 1]<='z') || (str[i + 1]>='A'&& str[i + 1]<='Z')))
        {
            consonant_words++;
        }
    }
 
    printf("\nVowels = %d",vowels);
    printf("\nConsonants = %d",consonants);
    printf("\nWhite spaces = %d",spaces);
    printf("\nConsonant words = %d",consonant_words);
    printf("\nVowel Words = %d",vowel_words);

    
}