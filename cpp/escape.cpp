#include <iostream>
using namespace std;

char *write_chars(char *dest, const char *st)
{
    for (int i = 0; st[i] != '\0'; i++)
    {
        *dest = st[i];
        dest++;
    }

    return dest;
}

void escape(char *src, char *dest)
{
    for (; *src != '\0'; src++)
    {
        switch (*src)
        {
        case '>':
            dest = write_chars(dest, "&gt;");
            break;                 
        case '"':
            dest = write_chars(dest, "&quot;");
            break;      
		case '<':
            dest = write_chars(dest, "&lt;");
            break;


        default:
            *dest = *src;
            dest++;
            break;
        }
    }
}

int main()
{
    char st[1000];
    char out[1000];
    int l;

    cin.getline(st, 1000);
    escape(st, out);

    cout << out << endl;
}
