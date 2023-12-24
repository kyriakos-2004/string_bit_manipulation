#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void
randomGenerator(std::vector<int>& myArray)
{
    myArray.reserve(20);
    for (int i = 0; i < 20; ++i)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(-9999, 9999);
        myArray.push_back(dist(gen));
    }
}

int 
kadaneAlgorithm(std::vector<int>& myArray)
{
    int maximumSumSubArray =  INT_MIN;
    int maximumSumCurrPos = 0;

    for (uint8_t i = 0; i < myArray.size(); ++i)
    {
        maximumSumCurrPos = std::max(maximumSumCurrPos + myArray[i], myArray[i]);
        maximumSumSubArray = std::max(maximumSumSubArray, maximumSumCurrPos);
    }
 
    return maximumSumSubArray;
}
 
int main()
{
    int choice = 0;
    int number = 0;
    int ending = 9999;
    std::vector<int> myArray;
    std::cout << "Press 1 to enter the array manually, 2 to use built-in array: \n";
    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << "Enter the array of integers, 9999 to end and calculate maximum sum of sub-array: \n";
        while ((std::cin >> number) && number != ending)
        {
            myArray.push_back(number);
        }
    }
    else
    {
        std::cout << "Array contains 20 random integers\n";
        randomGenerator(myArray);
    }

    std::cout << "The maximum sum of a contiguous subarray is " << kadaneAlgorithm(myArray);
 
    return 0;
}
