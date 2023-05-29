#!/bin/bash

# Compile your C program (replace "program.c" with the actual name of your C file)
gcc *.c -o program

# Define test cases
test_cases=(
  # Test case 1
  "ls la"
  # Test case 2
  "ls la | cat test.c && echo hello"
  # Test case 3
  "          ls la ./tmp ||         
  cat test.c vu.js && 
                 echo hello
  exit 0"

  # Test case 4
  " "

)

# Run tests
for ((i=0; i<${#test_cases[@]}; i++)); do
  input="${test_cases[i]}"
  
  # Run your C program
  ./program <<< "$input"
  
  # Check the exit code of the C program
  if [[ $? -eq 0 ]]; then
    echo "Test case $((i+1)): PASSED"
  else
    echo "Test case $((i+1)): FAILED"
    # You can add additional error handling here if needed
  fi
done



# Check memory leaks

# Run gcc command for all .c files in the grandparent directory
#gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# valgrind --tool=memcheck --leak-check=full ./program

valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes ./program

# Cleanup (optional)
rm program
