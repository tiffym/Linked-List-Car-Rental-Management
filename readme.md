


### Operations
- You will need to implement a **stack** data structure to store operands as you evaluate the expression.
- Operands are pushed onto the stack, and when an operator is encountered, the corresponding number of operands are popped from the stack, the operation is performed, and the result is pushed back onto the stack.


### Program Execution
The program should:
1. Take the postfix expression as a **command-line argument** with no spaces between the characters.
   - Example: `./a2q2 12+53-*`
   - In this example, `q2` is the name of the executable and `12+53-*` is the postfix expression.
2. **Evaluate** the postfix expression using stacks.
3. **Print** the result with exactly **two decimal places**.

### Compiling the Program
To compile and run the program for Part 2, follow these steps:

1. In the directory where the assignment files are saved, type:
	make 
This will compile all necessary files into an executable.

2. To run the program for Question 1, type:
./a2q2 <expression>


## Part 3: Assignment Guidelines

### General Requirements
For this assignment, you will complete two tasks:
1. **Question 1**: Create a car rental program using three linked lists (for available, rented, and repair cars) with operations for insertion, deletion, and transfer.
2. **Question 2**: Implement a Reverse Polish Notation (RPN) evaluator using a stack to store operands and intermediate results.

Both questions will be implemented in separate C files, and you will need to submit one `makefile` to compile both programs.

### File Structure
Your submission should contain the following files:
- **q1.c**: Contains the code for Question 1 (car rental program).
- **q2.c**: Contains the code for Question 2 (RPN evaluator).
- **q1.h** and **q2.h**: Header files containing structure definitions and function prototypes for each question.
- **q1_functions.c** and **q2_functions.c**: Contain the implementation of functions used in each question.
- **makefile**: This should compile both programs and generate two executable files (such as `a2q1` and `a2q2`).
- **README.md**: Contains a brief explanation of how to compile and run each program, sample outputs, and other required information.

### How to Build the Makefile:
- Define the overall targets: Start by listing the executables you want to create. In this example, we have two executables: a2q1 and a2q2.
- Set rules for the executables: Each executable depends on object files that are compiled from source files. Here, a2q1 depends on q1.o and q1_functions.o, and a2q2 depends on q2.o and q2_functions.o.
- Define how to compile object files: Next, you need to define the rules for creating the object files (q1.o, q1_functions.o, q2.o, and q2_functions.o). Each object file is compiled from its corresponding C source file, and you need to include any necessary header files for the dependencies.
- Add a clean rule: It's a good practice to include a clean rule to remove all the object files and executables when you're done.

### Compiling the Programs
- Make sure your makefile compiles both programs into separate executable files:
- q1 for the car rental program.
- q2 for the RPN evaluator.

### Documentation and Style
You will be graded on both the functionality and readability of your code. This includes:

- Comments:
Each file should start with a comment block containing your name, student ID, date, and the assignment name.
Every function should have a brief comment describing its purpose.
Add comments for any section of code where the functionality is not immediately apparent.

- Code Style: Follow proper indentation and code style conventions. Poor formatting will result in a deduction.

### README File Guidelines
- Use the README template provided for students.
- You can add additional information if needed, such as specific instructions or challenges faced during implementation.


### Submission and Error Handling
- Be sure to handle error conditions gracefully. For example, Question 1 should check for invalid transaction codes or attempts to return non-existent cars.
- Any compilation errors or warnings will result in a mark deduction based on the severity of the issue.
- Style, documentation, and code organization will also contribute to your overall mark.

## #Instructor and TA support

You can email [cis2520@socs.uoguelph.ca](mailto:cis2520@socs.uoguelph.ca) which will reach the entire instructional team.  Any email sent to this address will be answered by the first member of the instructional team available to respond.  You will get a response within 24 hours, and probably sooner.  Note that staff are not generally available outside of daytime working hours (for this or any course), so it is in your interest to start work early so that if you have questions you can ask them in time to get a good response.

Additional support is available during lab times when teaching staff will be available to answer lab related questions and general questions if time permits.  Note that lab exercises are designed specifically to build your skills within the focus of current and upcoming assignments.
