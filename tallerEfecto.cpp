#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <map>
#define MAX(x,y) ((x) > (y) ? (x) : (y))

using namespace std;

int MisteryFunction(const char*); // 1. What is this function doing?
int GetStringLength(const char*); // 3 String length
string JoinWords(const vector<string>& Words); // 4. Complexity O(n*x)
char* concatString(const char**, int); // 5. C version
bool isUnique(const char*); // 6. isUnique
int arraysize(const char*); // 7. function to calculate array size for 7th exercise
bool isPermutation(const char*, const char*); // 7. check permutation
char* URLfy(const char*, int); //8. URLfy
bool palindromePermutation(const char*); //9. Palindrome permutation
bool levenshtein(const char*, const char*);// 10. Levenshtein distance
string stringCompression(const char*); //11. string compression
char* invertInplace(char*); //12. Invert in place
void matrixRotation(long**,int); //13. Matrix rotation
void matrixZeros(int**, int, int); //14. Zero Matrix
bool isRotation(string, string); // 15. String Rotation
int main()
{
    const char* hello = "heya!";
    int a = MisteryFunction(hello);
    int counter = GetStringLength(hello);
    int size = 5;
    const char** stringArray = new const char* [size];
    stringArray[0] = "Decoherence";
    stringArray[1] = " is ";
    stringArray[2] = "the ";
    stringArray[3] = "best ";
    stringArray[4] = "game";
    char* phrase = concatString(stringArray, size);
    const char* stringUnique = "weughpoz*.csj@,l";
    const char* stringNoUnique = "alpaca";
    const char* aa = "ewfwefw";
    const char* bb = "xwfwwef";
    const char* url = "Mr John Smith";
    char* urlfy = URLfy(url, arraysize(url));
    const char* compress = "aaabbbbccd";
    char alfa1[] = "hello!";
    char* alfa = &alfa1[0];
    int matrixSize = 4;
    int countMatrix = 0;
    int countMatrixInt = 0;
    long** matrix = new long* [matrixSize];
    for (int i = 0; i < matrixSize; ++i)
        matrix[i] = new long[matrixSize];
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            matrix[i][j] = long(countMatrix);
            countMatrix++;
        }
    }
    int** matrixInt = new int* [matrixSize];
    for (int i = 0; i < matrixSize; ++i)
        matrixInt[i] = new int[matrixSize];
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            matrixInt[i][j] = countMatrixInt;
            countMatrixInt++;
        }
    }
    cout << isPermutation("erbottlewat", "aterbottlew") << endl;
    matrixRotation(matrix, matrixSize);
    matrixZeros(matrixInt, matrixSize, matrixSize);
    cout << invertInplace(alfa) << endl;
    cout << stringCompression(compress) << endl;
    cout << levenshtein("aba", "anb") << endl;
    cout << palindromePermutation("anita lava la tina")<<endl;
    cout << urlfy << endl;
    cout << a << endl;
    cout << counter << endl;
    cout << phrase << endl;
    cout << "unique! " << isUnique(stringUnique) << endl;
    cout << "not unique! " << isUnique(stringNoUnique) << endl;
     cout << isPermutation(aa, bb) << endl;
    delete phrase;
    delete[] stringArray;
    delete[] matrix;
    delete[] matrixInt;
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

char* concatString(const char** stringArray, int size)
{
    char* sentence = new char[1024];
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        while (*stringArray[i] != 0)
        {
            sentence[counter] = *stringArray[i];
            counter++;
            stringArray[i]++;
        }
    }
    sentence[counter] = NULL;
    return sentence;
};

bool isUnique(const char* stringunique) 
{
    int counter1 = 0;
    while (stringunique[counter1] != 0)
    {
        int counter2 = counter1 + 1;
        while (stringunique[counter2] != 0) 
        {
            if (stringunique[counter1] == stringunique[counter2]) 
            {
                return false;
            }
            counter2++;
        }
        counter1++;
    }
    return true;

};

int arraysize(const char* array)
{
    int size = 0;
    while (*array != 0) 
    {
        size++;
        array++;
    }
    return size;
};


bool isPermutation(const char* a, const char* b)
{
    if (arraysize(a) == arraysize(b)) 
    {
        map<char, int> permutationChecker;
        for (int i = 0; i < arraysize(a); i++)
        {
            char aux = a[i];
            if (permutationChecker[aux] == 0)
            {
                permutationChecker[aux] = 1;
            }
            else
            {
                int aux2 = permutationChecker[aux];
                permutationChecker[aux] = aux2 + 1;
            }
        }
        for (int i = 0; i < arraysize(b); i++)
        {
            char aux = b[i];
            if (permutationChecker[aux] == 0) 
            {
                return false;
            }
            int aux2 = permutationChecker[aux];
            permutationChecker[aux] = aux2 - 1;
        }
    }
    else
    {
        return false;
    }
    
    return true;
};

char* URLfy(const char* url, int size)
{
    int spaces = 0;
    const char* uri = "%20";
    for (int i = 0; i < size; i++)
    {
        if (url[i] == ' ')
        {
            spaces = spaces + 2;
        }
    }
    size = size + spaces;
    char* urlfy = new char[size];
    int urlcounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (*url == ' ')
        {
            i = i + 2;
            urlfy[i - 2] = uri[0];
            urlfy[i - 1] = uri[1];
            urlfy[i] = uri[2];
            url++;
        }
        else
        {
            urlfy[i] = *url;
            url++;
        }
    }
    urlfy[size] = 0;
    return urlfy;
};

bool palindromePermutation(const char* a)
{
    map<char, int> palipermutationChecker;
    for (int i = 0; i < arraysize(a); i++)
    {
        char aux = a[i];
        if (aux != ' ')
        {
            if (palipermutationChecker[aux] == 0)
            {
                palipermutationChecker[aux] = 1;
            }
            else
            {
                int aux2 = palipermutationChecker[aux];
                palipermutationChecker[aux] = aux2 + 1;
            }
        }

    }
    map<char, int>::iterator itr;
    int evenCounter = 0;
    int oddCounter = 0;
    for (itr = palipermutationChecker.begin(); itr != palipermutationChecker.end(); ++itr)
    {
        if (itr->second % 2 == 1)
        {
            oddCounter++;
        }

    }
    if (oddCounter == 1 || oddCounter == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool levenshtein(const char* a, const char* b)
{
    int asize = arraysize(a);
    int bsize = arraysize(b);
    int aindex = 0, bindex = 0, diff = 0;
    if (asize > bsize)
    {
        for (int i = 0; i < asize; i++)
        {
            if (a[aindex] == b[bindex])
            {
                aindex++;
                bindex++;
            }
            else
            {
                aindex++;
                diff++;
                if (diff > 1)
                {
                    return false;
                }
            }
        }
    }
    else if (bsize > asize)
    {
        for (int i = 0; i < bsize; i++)
        {
            if (a[aindex] == b[bindex])
            {
                aindex++;
                bindex++;
            }
            else
            {
                bindex++;
                diff++;
                if (diff > 1)
                {
                    return false;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < bsize; i++)
        {
            aindex++;
            bindex++;
            if (a[aindex] != b[bindex])
            {
                diff++;
                if (diff > 1)
                {
                    return false;
                }
            }
        }
    }
    return true;

};

string stringCompression(const char* a)
{
    int asize = arraysize(a);
    string arraycompress = "";
    int count = 1;
    for (int i = 0; i < asize; i++)
    {
        if(a[i] == a[i+1])
        {
            count++;
        }
        else
        {
            arraycompress = arraycompress + a[i];
            arraycompress = arraycompress + to_string(count);
            count = 1;
        }
    }
    if(arraycompress.size() > asize)
    {
        return string(a);
    }
    return arraycompress;

}
char* invertInplace(char* a)
{
    int size = arraysize(a);
    for (int i = 0; i < size / 2; i++)
    {
        char memoria = a[i];
        a[i] = a[size - i - 1];
        a[size - i - 1] = memoria;
    }
    return a;
};
void matrixRotation(long** matrix, int size)
{
    for (int i = 0; i < size / 2; i++) 
    {
        for (int j = i; j < size - i - 1; j++) 
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[size - 1 - j][i];
            matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];
            matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
            matrix[j][size - 1 - i] = temp;
        }
    }
     
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << '\n';
    }
    
}
void matrixZeros(int** matrix, int row, int col)
{
    bool* zeroRow = new bool[row];
    bool* zeroCol = new bool[col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                zeroRow[i] = true;
                zeroCol[j] = true;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (zeroRow[i] == true || zeroCol[j] == true)
            {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << matrix[i][j] << " ";
        cout << '\n';
    }
};

bool isRotation(string string1, string string2)
{
    int sizestring1 = string1.size();
    int sizestring2 = string2.size();
    if ( sizestring1 != sizestring2 ) 
    {
        return false;
    }
    else
    {
        string aux = string1.substr(1, sizestring1) + string1.substr(0, sizestring1 - 1);
        if (aux.find(string2) != string::npos) 
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}