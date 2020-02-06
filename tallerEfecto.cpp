

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string JoinWords(const vector<string>& Words);
char* concatString(const char**,int);


int main()
{
    //const char* x = "holaHue";
    string josefino = "juan";
    const string& juan = josefino;
    vector<string> cachapa;
    cachapa.push_back(juan);
    const vector<string>& juanmemori = cachapa;
    int size = 5;
    const char **stringArray = new const char*[size];
    stringArray[0] = "google";
    stringArray[1] = " is ";
    stringArray[2] = "the ";
    stringArray[3] = "best ";
    stringArray[4] = "search";
    
    //char *phrase = concatString(stringArray, size);
    cout << stringArray[0] << endl;
    cout << stringArray[1] << endl;
    cout << stringArray[2] << endl;
    cout << stringArray[3] << endl;
    cout << stringArray[4] << endl;
    delete[] stringArray;
    //delete x;
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

char* concatString(const char **stringArray, int size) 
{
    char *sentence = new char(1024);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j !='\0'; j++)
        {

        }
    }
   
}
