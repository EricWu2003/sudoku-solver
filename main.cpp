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
int findUniqueSolution(int r, int c, int nums[9][9])
{ // this method returns the unique solution to a certain position, 0 if there is no unique solution, and -1 if a contradiction is found (no solution at all)

    if (nums[r][c] != 0)
    {
        return nums[r][c];
    }

    bool poss[10] = {true, true, true, true, true, true, true, true, true, true}; // poss[i] will indicate whether i is a possible value at numbers[r][c]

    for (int i = 0; i < 9; i++)
    {
        poss[nums[r][i]] = false;
        poss[nums[i][c]] = false;
    }

    int gridRow = r / 3; // this will be one of 0,1,2
    int gridCol = c / 3; // this will be one of 0,1,2
    int helper[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int num = nums[helper[gridRow][i]][helper[gridCol][j]];
            poss[num] = false;
        }
    }

    int numberOfSolns = 0;
    int lastSolution = -1;
    for (int i = 1; i <= 9; i++)
    {
        if (poss[i])
        {
            lastSolution = i;
            numberOfSolns++;
        }
    }
    if (numberOfSolns > 1)
    {
        return 0;
    }
    return lastSolution;
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
    // at this point we are done getting the numbers from the file into numbers.

    printNumbers(numbers);
    cout << "------" << endl;

    for (int count = 0; count < 10; count++)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                numbers[i][j] = findUniqueSolution(i, j, numbers);
            }
        }

        printNumbers(numbers);
        cout << "------" << endl;
    }

    return 0;
}
