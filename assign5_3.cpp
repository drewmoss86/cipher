/**********************************************************
 *AUTHOR         : Andrew Moss
 *Assignment #5  : Cipher Specification
 *CLASS          : CS 002
 *SECTION        : MTWR: 7:30a – 12:30p
 *Due Date       : 1/17/17
 **********************************************************/
#include <iostream>
#include <iomanip>
#include <string>
/************************************************************
 * CIPHER SPECIFICATION
 * _________________________________________________________
 * This program that can both decrypt and encrypt a single
 * word that is entered by the user. The initial choice of
 * encryption and decryption is left up to the user.
 * Additionally, the user will enter a value to be utilized
 * when determining how to translate the character.
 * _________________________________________________________
 * INPUT:
 *   method: a string value do decide cipher method -> input by user
 *   translation: a string value to decide translation method -> input by user
 *   word: a string value to be ciphered -> input by user
 *   default: a string value that will output the defaultMap =
 *   "zyxwvutsrqponmlkjihgfedcba"
 *   pos: character position in string
 *   int counter: COUNTER: for loop
 *   int inTheMap = boolean
 *   isANumber = boolean
 *
 * OUTPUT:
 *   encryption: user input word will convert to default map
 *   decrypted: user input word will revert from default map
 ************************************************************/

using namespace std;

int main()
{
    string method;
    string translation;
    string word;
    string defaultMap = "zyxwvutsrqponmlkjihgfedcba";
    int pos;
    int counter;
    bool inTheMap = false;
    bool isANumber = false;


        //INPUT: The method to perform (encryption or decryption).
    cout << "What is the method (encryption or decryption)? ";
    cin >> method;

    if (method != "encryption" && method != "decryption")
        {
        cout << "\nError: invalid method choice." << endl;
        return 0;
        }

    cout << "\nWhat is the translation map (type 'default' to use default): ";
    cin >> translation;

    if (translation.size() != 26 && translation != "default")
        {
        cout << "\nError: invalid translation map size." << endl;
        return 0;
        }

    if (translation == "default")
        {
        translation = defaultMap;
        }

    cout << "\nWhat is the single word to translate: ";
    cin >> word;

    for (int i = 0; i < word.size(); i++)
        {
        for (int k = 0; k < 10; k++)
            {
            if (((int)word.at(i) - '0') == k)
               {
                isANumber = true;
                }
            }
        for (int j = 0; j < translation.size(); j++)
            {
            if (word.at(i) == translation.at(j))
                {
                inTheMap = true;
                }
            }
        if (inTheMap == false && method == "decryption")
            {
            cout << "\nError: " << method << " cannot be performed." << endl;
            return 0;
            }
        else if (inTheMap == false && method == "encryption" && isANumber == true)
            {
            cout << "\nError: " << method << " cannot be performed." << endl;
            return 0;
            }
        }

    if (method == "encryption" && translation == "default")
        {
        for (counter = 0; counter < word.size(); counter++)
            {
            pos = word.at(counter) - 'a';
            word.at(counter) = defaultMap.at(pos);
            }
        cout << "\nEncrypted word: " << word << endl;
        return 0;
        }
    else if (method == "encryption" && translation.size() == 26 &&
             translation != "default")
        {
        for(counter = 0; counter < word.size(); counter++)
            {
            pos = word.at(counter) - 'a';
            word.at(counter) = translation.at(pos);
            }
        cout << "\nEncrypted word: " << word << endl;
        }

    if (method == "decryption" && translation == defaultMap)
        {
        for(counter = 0; counter < word.size(); counter++)
            {
            pos = defaultMap.find(word.at(counter));
            word.at(counter) = pos + 'a';
            }
        cout << "\nDecrypted word: " << word << endl;
        return 0;
        }

    else if (method == "decryption" && translation.size() == 26 && translation != defaultMap)
        {
        for(counter = 0; counter < word.size(); counter++)
            {
            pos = translation.find(word.at(counter));
            word.at(counter) = pos + 'a';
            }
        cout << "\nDecrypted word: " << word << endl;
        return 0;
        }
    return 0;
}

