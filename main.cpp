#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int ReadFromFile(string filename)
{
    string text;
    fstream MyReadFile(filename);

    int numbers[9][9];
    int row = 0;

    while (getline(MyReadFile, text))
    {
        // Output the text from the file
        cout << text << endl;

        if(text == "-----------"){
            continue;
        }
        numbers[row][0] = int(text[0]) - 48;
        numbers[row][1] = int(text[1]) - 48;
        numbers[row][2] = int(text[2]) - 48;
        numbers[row][3] = int(text[4]) - 48;
        numbers[row][4] = int(text[5]) - 48;
        numbers[row][5] = int(text[6]) - 48;
        numbers[row][6] = int(text[8]) - 48;
        numbers[row][7] = int(text[9]) - 48;
        numbers[row][8] = int(text[10]) - 48;
        row ++;
    }


    for (int row=0; row < 9; row ++)
        for (int col=0; col < 9; col ++)
            if (numbers[row][col] == -16)
                numbers[row][col] = 0;

    MyReadFile.close();
    return 0;
}

int main()
{
    ReadFromFile("puzzle.txt");

    return 0;
}
