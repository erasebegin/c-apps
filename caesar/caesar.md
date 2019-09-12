
### Caesar's Cypher

* if argc is equal to 2, and first parameter is an integer carry out main part of function
  - can be done by checking that ascii codes of input are within certain range
* else prompt user to enter an integer value
* take parameter from argv[1] and convert it to a number:
        - for each iteration through the characters of argv\[1][i], convert to ascii integer
        - use an equation to convert ascii integer to standard integer
            - 1 = 49, 2=50 etc.
            - difference is therefore 48
            - last value in string array (argv\[1][n]) should be multiplied by 1
            - second from last value by 10
            - third from last value by 100 etc
            - then the 1s, 10s and 100s are added together in a variable called key
* Now take a string from the user
* convert the string to an array of ascii numbers
* increment through the array, increasing each number by k

