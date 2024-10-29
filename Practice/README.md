## Questions

1. Why do I get "%" in the terminal output when its not present in printf statement?
   Input:
   `printf("My name is Adarsh");`
   <br> Output:
   `My name is Adarsh%`

   - If you're seeing a % symbol appear at the end of your output without putting it in printf, it’s likely due to your terminal or IDE rather than the code itself. Some terminals or IDEs display a % symbol at the end of output as an indicator of the end of the output line, especially in some Unix-based systems. <br> This is unrelated to your code itself, and if you run the same code in another environment or terminal, you likely won’t see the %.

2. Declaration of a float and a double: <br> `float myFloat = 3.14159f;`<br>
   `double myDouble = 3.141592653589793;`<br>
   Why do we add a `f` while declaring a float?

   - In C, adding an f after a number (e.g., 3.14159f) tells the compiler that the literal should be treated as a float rather than the default double. <br>
     Default Type for Decimal Literals: When you write a decimal literal like 3.14159 without any suffix, C treats it as a double by default. <br> Explicit float Declaration: By adding the f suffix (e.g., 3.14159f), you explicitly tell the compiler, "This number is a float." This is useful because assigning a double to a float would normally require an implicit conversion, which can result in a small performance penalty or unintended precision loss. <br>
     Example: <br>
     `float myFloat = 3.14159;` Warning: assigning double to float<br>
     `float myFloat = 3.14159f;` Correct: explicitly a float
