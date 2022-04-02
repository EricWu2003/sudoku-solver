#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int ReadFromFile(string filename)
{
    string text;
    fstream MyReadFile(filename);

    int numbers[9][9];

    while (getline(MyReadFile, text))
    {
        // Output the text from the file
        if(text == "-----------"){}
        cout << text << endl;
    }
    MyReadFile.close();
    return 0;
}

int main()
{
    ReadFromFile("puzzle.txt");

    return 0;
}
