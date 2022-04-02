#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printRow(int row[9])
{
    char chars[9];
    for (int i = 0; i < 9; i++)
    {
        if (row[i] != 0)
            chars[i] = (char)(row[i] + 48);
        else
            chars[i] = '.';
    }

    cout << chars[0] << chars[1] << chars[2] << "|" << chars[3] << chars[4] << chars[5] << "|" << chars[6] << chars[7] << chars[8] << endl;
}

void printNumbers(int nums[9][9])
{

    printRow(nums[0]);
    printRow(nums[1]);
    printRow(nums[2]);
    cout << "-----------" << endl;
    printRow(nums[3]);
    printRow(nums[4]);
    printRow(nums[5]);
    cout << "-----------" << endl;
    printRow(nums[6]);
    printRow(nums[7]);
    printRow(nums[8]);
}

int main()
{
    string text;
    fstream MyReadFile("puzzle.txt");

    int numbers[9][9];
    int row = 0;

    while (getline(MyReadFile, text))
    {

        if (text == "-----------")
        {
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
        row++;
    }

    MyReadFile.close();

    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
            if (numbers[row][col] == -16)
                numbers[row][col] = 0;

    printNumbers(numbers);

    return 0;
}
