

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int MisteryFunction(const char*); // 1. What is this function doing?
int GetStringLength(const char*); // 3 String length
string JoinWords(const vector<string>& Words); // 4. Complexity O(n*x)
char* concatString(const char**, int); // 5. C version

int main()
{
    const char* hello = "heya!";
    int a = MisteryFunction(hello);
    int counter = GetStringLength(hello);
    int size = 5;
    const char** stringArray = new const char* [size];
    stringArray[0] = "google";
    stringArray[1] = " is ";
    stringArray[2] = "the ";
    stringArray[3] = "best ";
    stringArray[4] = "search";
    char* phrase = concatString(stringArray, size);
    cout << a <<endl; 
    cout << counter<<endl;
    cout << phrase << endl;
    //cout << phrase << endl;
    //delete phrase;
    delete phrase;
    NULL; 
}

int MisteryFunction(const char* w) // count the chars "a" in a c string
{
    int a = 0;
    while (*w != 0)
    {
        if (*w == 'a')
            a++;
        w++;
    }
    return a;

}

int GetStringLength(const char* String) //count the chars in a c string 
{
    int counter = 0;
    while (*String != NULL)
    {
        counter++;
        String++;
    }
    return counter;
}

string JoinWords(const vector<string>& Words)
{
    string Sentence;
    for (const string& w : Words)
    {
        Sentence = Sentence + w;
    }
    return Sentence;
};

char* concatString( const char** stringArray, int size)
{
    char* sentence = new char[1024];
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        while (*stringArray[i]!= 0)
        {
            sentence[counter] = *stringArray[i];
            counter++;
            stringArray[i]++;
        }
    }
    sentence[counter] = NULL;
    return sentence;
}