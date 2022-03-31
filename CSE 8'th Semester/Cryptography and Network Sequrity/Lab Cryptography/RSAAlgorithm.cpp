#include <bits/stdc++.h>
using namespace std;
long long e,n;

long long IntegerLength(long long n);
long long StringToLongLong(string s);
string LongLongToString(long long n);
bool IsPrime(long long p);
long long Bigmod(long long base, long long power, long long mod);
string Encrypt(string s);
string Decrypt(string cipher, long long key);

int main()
{
    srand(time(NULL));
    string msg;
    string cipher;
    long long d;
    ifstream fin;
    fin.open("in.txt");
    getline(fin, msg);
    fin.close();

    long long p,q;
    p = 47;
    q = 71;
    n = p*q;
    e = 79;
    d = 1019;

    cout<<"Here p is = "<<p<<endl;
    cout<<"Here q is = "<<q<<endl;
    cout<<"Here n is = "<<n<<endl;
    cout<<"Here e is ="<<e<<endl;
    cout<<"Here d is ="<<d<<endl;

    cipher = Encrypt(msg);
    msg = Decrypt(cipher, d);

    ofstream fout;
    fout.open("out.txt");
    fout<<"Encrypted Text: "<<cipher<<endl;
    fout<<"Decrypted Plain Text: "<<msg<<endl;
    fout.close();

    return 0;
}

long long IntegerLength(long long n)
{
    long long len = 0;
    while(n)
    {
        n/=10;
        len++;
    }
    return len;
}

long long StringToLongLong(string s)
{
    long long n = 0;
    long long d = 1;
    for(int i=s.size()-1; i>=0; i--)
    {
        n += (s[i]-'0')*d;
        d *= 10;
    }
    return n;
}

string LongLongToString(long long n)
{
    string s = "";
    if(n == 0) s = "0";
    while(n)
    {
        s += ((n%10)+'0');
        n /= 10;
    }

    reverse(s.begin(), s.end());

    return s;
}

bool IsPrime(long long p)
{
    if(p==1) return false;
    if(p==2) return true;
    if(p%2 == 0) return false;

    for(long long i=3; i<=sqrt(p)+2; i+=2)
    {
        if(p%i == 0) return false;
    }

    return true;
}
long long Bigmod(long long base, long long power, long long mod)
{
    long long res = 1;
    for(long long i = 1; i<=power; i++)
    {
        res *= base;
        res %= mod;
    }
    return res;
}

string Encrypt(string s)
{
    string cipher = "";
    long long blockSize = IntegerLength(n)-1;

    for(long long i=0; i<s.size(); i+=blockSize)
    {
        string block = s.substr(i, blockSize);
        cipher += LongLongToString(Bigmod(StringToLongLong(block), e, n));
        cipher += " ";
    }

    return cipher;
}

string Decrypt(string cipher, long long key)
{
    string s = "";
    string block = "";

    for(long long i=0; i<cipher.size(); i++)
    {
        if(cipher[i] == ' ')
        {
            s += LongLongToString(Bigmod(StringToLongLong(block), key, n));
            block = "";
        }
        else block += cipher[i];
    }

    return s;
}
