#include <iostream>
using namespace std;

string caesar_cipher(string message, int s)
{
	string encrypted_message = "";

	for (int i = 0; i < message.length(); i++) {
		if (isupper(message[i])) //for uppercase letters
			encrypted_message += char(int(message[i] + s - 65) % 26 + 65);

		else //for lowercase letters
			encrypted_message += char(int(message[i] + s - 97) % 26 + 97);
	}

	return encrypted_message;
}

// Driver program to test the above function
int main()
{
	string message; int s;
    cout<<"Enter a string to be encrypted- ";
    cin>>message;
    cout<<"Enter shift number- ";
    cin>>s;
	cout << "Original Message : " << message;
	cout << "\nShift: " << s;
	cout << "\nCaesar Cipher encypted message: " << caesar_cipher(message, s);
	return 0;
}
