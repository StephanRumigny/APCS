#include <time.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//michael albornoz helped me and he explained to me all of this during tutoring
int *readFile(string fileName, int size1, int size2);  //pointer to return and int array function declaration
int linearSearch(int array[], int guess, int size1);  //linear search function declaration
int binarySearch(int array[], int guess, int size1); //binary search function declaration
int *bubbleSort(int array[], int size1); //bubble sort function declaration
int *selectionSort(int array[], int size1); //selection sort function declaration
void printArray(int array[], int size1); //print in command terminal function declaration
void printArrayFile(int array[], int size1); //print in seperate file function declaration
void menu(); //menu function declartion

int main(void)
{
    //global varibles needed in all functions
    int menuint = 0;

    int filechecker = 0;

    int *array;

    int size1;
    int size2;

    int guess;
    do
    {
        // call of the menu function
        menu();
        menuint = get_int("Your Option ----> ");

        string fileName = ("hello"); //needed to be declared globally first

        //option 1
        if (menuint == 1)
        {
        fileName=get_string("Enter File name ");

        //control of size of file
        int getsize = get_int("\nHow big is your file: \n 1) 5000 \n 2) 10000 \n 3) 50000 \n Your Choice ----> ");
        if (getsize == 1)
        {
            size1 = 5000;
            size2 = 5;
        }
        if (getsize == 2)
        {
            size1 = 10000;
            size2 = 6;
        }
        if (getsize == 3)
        {
            size1 = 50000;
            size2 = 6;
        }

        FILE* file=(fopen(fileName, "r")); //open file to read

        char line[size2]; //how many characers per line
        char options[size1][size2];//array to put all the numbers from the file

        int numbers[size1];  // file to be returned

        for (int i=0; i < size1; i++)
        {
            fscanf(file, "%s", options[i]);
            numbers[i]= atoi(options[i]);
        } //prints the data in the file into the array "numbers"

        fclose(file);

        array = numbers; //the data is now called arrays

        filechecker = 1; //a bool value to make sure that the user has read a file before they try anything else
        }

        // option 2
        if (menuint == 2 && filechecker == 1)
        {
            do
            {
                guess = get_int("give me a number in between 1-%i: ", size1);
            } while(guess < 1 || guess > size1); //do while bc the number has to be between 1 and the size they chose

            int indx = linearSearch(array, guess, size1); // call of the linear function
            printf("Your value, %i, is at %i in the file.", guess, indx + 1);
        }

        // option 3
        if (menuint == 3 && filechecker == 1)
        {
            do
            {
                guess = get_int("give me a number in between 1-%i: ", size1);
            } while(guess < 1 || guess > size1); //do while bc the number has to be between 1 and the size they chose

            int indx = binarySearch(array, guess, size1); // call of the binary function
            printf("Your value, %i, is at %i in the file.", guess, indx);
        }

        //option 4
        if (menuint == 4 && filechecker == 1)
        {
            int *sorted = selectionSort(array, size1); // call of the selection function
            int printchoice = get_int("How do you want the file printed: \n 1) Command Terminal \n 2) Seperate Text File \n Your Choice ----> ");
            if (printchoice == 1)
            {
                printArray(array, size1); // call of the print function
            }
            if (printchoice == 2)
            {
                printArrayFile(array, size1); // call of the print file function
            }
        }
        //option 5
        if (menuint == 5 && filechecker == 1)
        {
            int *sorted = bubbleSort(array, size1); // call of the bubble function
            int printchoice = get_int("How do you want the file printed: \n 1) Command Terminal \n 2) Seperate Text File \n Your Choice ----> ");
            if (printchoice == 1)
            {
                printArray(array, size1); // call of the print function
            }
            if (printchoice == 2)
            {
                printArrayFile(array, size1); // call of the print file function
            }
        }
    } while(menuint != 6); //6 exits the program
}


//option 2
int linearSearch(int array[], int guess, int size1)
{
    int i;
    for(i=0; i < size1; i++)
    {
        if (array[i]== guess)
        {
            return i;
        }
    }
    return i;
}

//option 3
int binarySearch(int array[], int guess, int size1)
{
    int max = 5000;
    int min = 0;
    int mid;

    for (int f = 0; f < 5000; f++)
    {
        mid = (max + min) / 2;

        if (guess == mid)
        {
            return guess;
            break;
        }
        else if (guess > mid)
        {
            min = mid;
        }
        else if (guess < mid)
        {
            max = mid;
        }
    }
    return guess;
}

//option4
int *selectionSort(int array[], int size1)
{
    int index;
    for (int i = 0; i < size1; i++)
    {
        int min = size1 + 1;
        for(int j = i; j < size1; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                index = j;
            }
        }
        int temp = array[i];
        array[i] =  min;
        array[index] = temp;
    }
    return array;
}

//option 5
int *bubbleSort(int array[], int size1)
{

for (int loop = 0; loop < size1 - 1; loop++) {
    for (int i = 0; i < size1 - loop - 1; ++i) {
      if (array[i] > array[i + 1]) {

        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
  return array;
}

//print fucntion in command terminal
void printArray(int array[], int size1)
{
    for (int i= 0; i < size1; i++)
    {
        printf("%i\n", array[i]);
    } //prints all the sorted arrays into the command line
}

//print fucntion in seperate file
void printArrayFile(int array[], int size1)
{
    string sortedfileName=get_string("Enter File name for sorted array to be placed in: "); //ask user for file name
    FILE* fp = fopen(sortedfileName, "w"); // creates the file for the sorted algriothrim
    for (int i= 0; i < size1; i++) //for loop to print each value in array
    {
        fprintf(fp, "%d", array[i]); //prints the data
        fprintf(fp, "\n"); //goes to a new line
    }
    fclose(fp);
}
void Menu()
{
 // make a menu
 printf("=====================================\n");
 printf("#               MENU                #\n");
 printf("#   1) Read a file                  #\n");
 printf("#   2) Sort an Array                #\n");
 printf("#   3) Search for a value in array  #\n");
 printf("#   4) Write an array to File       #\n");
 printf("#   5) Exit                         #\n");
 printf("=====================================\n");
}
void writeArray(int sorted[], int size)
{
    string name=get_string("How do you want to call your file? ");
    char filename[10];
    sprintf(filename, "%s.txt", name);
    FILE *file = fopen(filename, "w");
    for (int i=0; i < size; i++)
    {
        fprintf(file,"%d\n",sorted[i]);
    }
}
