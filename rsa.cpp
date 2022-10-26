// RSA Algorithm
// 1. choose 2 prime nos p,q.
// 2. calc n=p*q.
// 3. calc phi = (p-1)+(q-1)
// 4. choose int e such that check 1 < e < phi(n) , e and phi(n) are coprime.
// 5. calc such that d*e = 1 mod phi
// 6. for encryption c=me mod n
// 7. for decryption m=cd mod n

#include <iostream>
#include <math.h>
using namespace std;

// return gcd
int gcd(int a, int b)
{
    int result = min(a, b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }
    return result;
}

int main()
{
    // 2 random prime numbers
    double p = 13;
    double q = 11;
    double n = p * q;
    double phi = (p - 1) * (q - 1);
    // public key
    double e = 7;
    double track;
    // check 1 < e < phi(n) , e and phi(n) are coprime.
    while (e < phi)
    {
        track = gcd(e, phi);
        if (track == 1)
            break;
        else
            e++;
    }
    // private key
    // choose d such that d*e = 1 mod phi
    double d1 = 1 / e;
    double d = fmod(d1, phi);

    double message;
    cout << "Enter Message in number- ";
    cin >> message;

    double c = pow(message, e); // encrypt the message
    double m = pow(c, d);

    c = fmod(c, n);
    m = fmod(m, n);

    cout << "Original Message = " << message << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "n = pq = " << n << endl;
    cout << "phi = " << phi << endl;
    cout << "e = " << e << endl;
    cout << "d = " << d << endl;
    cout << "Encrypted message = " << c << endl;
    cout << "Decrypted message = " << m << endl;
    return 0;
}