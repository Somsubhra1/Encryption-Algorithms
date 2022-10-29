// Playfair Cipher
// 1. Generate a 5*5 sqaure
//    (Start filling square with unqiue letters present in the key followed by remaining letters of the albhabet lexicographically)
//    (key for enxrypting plaintext with 25 unique letters, Omit J, Replace I by J if plaintext has J in it)

// 2. Split plain text into digraphs
//    add Z to the last letter if there are odd number of letters
//    If a digraoh contains same letters, keep one letter and add a bogus letter to it.
//    If there is a letter that doesn't have its pair, then add a bogus letter with the alone letter

// 3. For encryption,
//    If both letters are in the same column, take the letter below each one
//    If they are in the same row, take the letter to the right of each one
//    If they aren't in the same row or column, form a rectangle with the two letters as opposite vertices and take letters on the horizontal opposite vertex

#include <bits/stdc++.h>
using namespace std;

void convertToLowerCase(char plain[], int ps) //convert to lower case
{
    int i;
    for (i = 0; i < ps; i++)
    {
        if (plain[i] > 64 && plain[i] < 91)
            plain[i] += 32;
    }
}

int removeSpacesFromPlainText(char *plain, int ps) //remove spaces
{
    int i, count = 0;
    for (i = 0; i < ps; i++)
        if (plain[i] != ' ')
            plain[count++] = plain[i];
    plain[count] = '\0';
    return count;
}

void generateKeyTable(char key[], int ks, char keyTable[5][5]) //generating a 5*5 square
{
    int i, j, k, flag = 0;
    int dicty[26] = {0}; //store alphabet count in hashmap

    for (i = 0; i < ks; i++)
    {
        if (key[i] != 'j')
            dicty[key[i] - 97] = 2;
    }

    dicty['j' - 97] = 1;

    i = 0; j = 0;
    
    for (k = 0; k < ks; k++)
    {
        if (dicty[key[k] - 97] == 2)
        {
            dicty[key[k] - 97] -= 1;
            keyTable[i][j] = key[k];
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }

    for (k = 0; k < 26; k++)
    {
        if (dicty[k] == 0)
        {
            keyTable[i][j] = (char)(k + 97);
            j++;
            if (j == 5)
            {
                i++;
                j = 0;
            }
        }
    }
}

void searchInTable(char keyTable[5][5], char a, char b, int arr[]) //to return the position of characters of digraph in square
{
    int i, j;

    if (a == 'j')
        a = 'i';

    else if (b == 'j')
        b = 'i';

    for (i = 0; i < 5; i++)
    {

        for (j = 0; j < 5; j++)
        {

            if (keyTable[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyTable[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int calcmod(int a) //return mod 5
{ 
    int modres = a % 5;
    return modres; 
}

void playfairCipher(char text[], char key[]) //encryption
{
    char ps, ks, keyTable[5][5];

    ks = strlen(key);
    ks = removeSpacesFromPlainText(key, ks);
    convertToLowerCase(key, ks);

    ps = strlen(text);
    ps = removeSpacesFromPlainText(text, ps);
    convertToLowerCase(text, ps);

    if (ps % 2 != 0) //making odd length string even length
    {
        text[ps++] = 'z';
        text[ps] = '\0';
    } 

    generateKeyTable(key, ks, keyTable); //creating square for encyrption

    //carrying out the actual encyrption

    int i, a[4];

    for (i = 0; i < ps; i += 2)
    {

        searchInTable(keyTable, text[i], text[i + 1], a);

        if (a[0] == a[2])
        {
            text[i] = keyTable[a[0]][calcmod(a[1] + 1)];
            text[i + 1] = keyTable[a[0]][calcmod(a[3] + 1)];
        }
        else if (a[1] == a[3])
        {
            text[i] = keyTable[calcmod(a[0] + 1)][a[1]];
            text[i + 1] = keyTable[calcmod(a[2] + 1)][a[1]];
        }
        else
        {
            text[i] = keyTable[a[0]][a[3]];
            text[i + 1] = keyTable[a[2]][a[1]];
        }
    }
}

int main()
{
    char text[30], key[30];
    cout << "Enter key : ";
    cin >> key;

    cout << "Enter plaintext for encryption : ";
    cin >> text;

    cout << endl;

    cout << "Key : " << key << "\n";
    cout << "Plain : " << text << "\n";

    playfairCipher(text, key);

    cout << "Cipher text : " << text << "\n";

    return 0;
}
