/**********************
*  Alexei Beizerov    *
* serothim@gmail.com  *
*skype name: serothim *  
**********************/


#include "vigenere_cipher.h"


/*
 * This function shift to next character in keyword
 */
static int shift(char c);


/*
 * This function encrypts incoming text
 */
string encrypt(string keyword, string str)
{
    static const int LETTER_COUNT = 26;
	
    if (str != NULL)
    {  
        int str_length = strlen(str);
        // The value_to_increase variable to store the value by which to 
        // increase the character value when encrypting.
        int value_to_increase = 0;

        // Changes characters of the plaintext into ciphertext
        for (int i = 0, j = 0; i < str_length; i++)
        {   
            // Shift is used, if only the symbol is a symbol of the alphabet
            if (isalpha(str[i]))
            {
                // Get value for value_to_increase
                for (;;)
                {   
                    if (keyword[j] == '\0')
                    {
                        j = 0;  // Return to the first character of the keyword
                        continue;
                    }
                    else
                    {
                        value_to_increase = shift(keyword[j]);
                    }
                    
                    j++;  // Next character of keyword.
                    break;
                }
            }

            if (isalpha(str[i]))
            {   
                if (isupper(str[i]) && (str[i] + value_to_increase) > 'Z')
                {
                     str[i] += value_to_increase - LETTER_COUNT;
                }
                else if (islower(str[i]) && (str[i] + value_to_increase) > 'z')
                {
                     str[i] += value_to_increase - LETTER_COUNT;
                } 
                else
                {
                     str[i] += value_to_increase;
                }
            }
        }
      
      return str;
    }

    return NULL;
}


static int shift(char c)
{
    if (isupper(c))
    {
        return c - 'A';
    }
    else
    {
        return c - 'a';
    }
}