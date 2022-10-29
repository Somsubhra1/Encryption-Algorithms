// Keyword Cipher

#include <bits/stdc++.h>
using namespace std;

string keyword_cipher(string text, string key)
{
    // generaing encoded text
    string encoded_text = "";
    bool alphabets[26] = {0}; // array representing english alphabets

    for (int i = 0; i < key.size(); i++) // insert keyword at the start of en
    {
        if (key[i] >= 'A' && key[i] <= 'Z')
        {
            // // check if the letter is inserted earlier in the encoded string
            if (alphabets[key[i] - 65] == 0)
            {
                encoded_text += key[i];
                alphabets[key[i] - 65] = 1;
            }
        }
        else if (key[i] >= 'a' && key[i] <= 'z')
        {
            if (alphabets[key[i] - 97] == 0)
            {
                encoded_text += key[i] - 32;
                alphabets[key[i] - 97] = 1;
            }
        }
    }

    // // inserts the remaining characters in the encoded string.
    for (int i = 0; i < 26; i++)
    {
        if (alphabets[i] == 0)
        {
            alphabets[i] = 1;
            encoded_text += char(i + 65);
        }
    }

    string cipher_text = "";

    // creating ciphered text
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            int pos = text[i] - 97;
            cipher_text += encoded_text[pos];
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            int pos = text[i] - 65;
            cipher_text += encoded_text[pos];
        }
        else
        {
            cipher_text += text[i];
        }
    }
    return cipher_text;
}

int main()
{
    string key, plain_text;

    cout << "Enter key : ";
    cin >> key;

    cout << "Enter Plain Text : ";
    cin >> plain_text;

    cout << endl
         << "Key used : " << key << endl
         << "Plain text : " << plain_text<<endl;

    cout << "Ciphered Text : " << keyword_cipher(plain_text, key) << endl;

    return 0;
}
