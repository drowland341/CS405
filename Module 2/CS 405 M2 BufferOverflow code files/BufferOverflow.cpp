// Douglas Rowland
// CS-405
// Module 2 Buffer Overflow
// 
// 
// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <limits>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_number
  //  variable, and its position in the declaration. It must always be directly before the variable used for input.
  //  You must notify the user if they entered too much data.

  const std::string account_number = "CharlieBrown42";
  char user_input[21]; // Changed to allow for 20 characters + null terminator

  std::cout << "Enter a value (up to 20 characters): ";

  // Safely read up to 20 characters (leaving space for null terminator)
  std::cin.get(user_input, sizeof(user_input));

  // Read up to 20 characters and ensure no overflow
  if (!std::cin.eof() && std::cin.peek() != '\n') {
      std::cin.clear(); // Clear the input stream
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard extra input
      std::cout << "Warning: Input exceeded 20 characters!! Excess characters discarded." << std::endl;
  }

  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
