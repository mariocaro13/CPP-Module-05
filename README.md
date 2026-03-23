*This project has been created as part of the 42 curriculum by mcaro-ro*

# CPP Module 05 – Exceptions & Bureaucracy
## 📖 Description
CPP Module 05 introduces structured error handling through C++ exceptions, along with the design of robust class hierarchies that enforce strict rules.
Across four exercises, you will build a small bureaucratic system:
starting with a Bureaucrat, then Forms, then executable Forms, and finally an Intern capable of generating forms dynamically.

The module focuses on writing safe, validated, exception‑aware code while practicing inheritance, abstract classes, and clean class design.

## ⚙️ Instructions
1. Clone the repository from your Git workspace.
2. Navigate into the exercise folder (ex00, ex01, ex02, or ex03).
3. Compile the project using make.
4. Each exercise has its own main.cpp to test the required functionality.
5. Clean build artifacts with:
	```
	make clean
	```
	```
	make fclean
	```
	```
	make re
	```
## 📚 Concepts Covered
1. Exception Handling
 - Throwing exceptions with throw.
 - Creating custom exception classes inheriting from std::exception.
 - Overriding what() for meaningful error messages.
 - Using try/catch blocks to handle failures.

2. Attribute Validation
 - Bureaucrat grades must stay between 1 (highest) and 150 (lowest).
 - Forms have required grades for signing and executing.
 - Any invalid grade triggers an exception immediately.

3. Abstract Classes
 - In exercise 02, Form becomes AForm, an abstract base class.
 - A pure virtual method execute() is introduced.

4. Inheritance & Polymorphism
 - Three concrete forms derive from AForm:
 - ShrubberyCreationForm
 - RobotomyRequestForm
 - PresidentialPardonForm
 - Each implements its own execution behavior.

5. Simple Factory Pattern (Intern)
 - The Intern creates forms based on a string name.
 - Avoids long if/else chains by mapping names to constructors.
 - Returns a pointer to a newly created AForm.

6. Orthodox Canonical Form
 - All classes (except exception classes) must implement:
 - Default constructor
 - Copy constructor
 - Copy assignment operator

Destructor

🧱 Exercises
 - ex00 – Bureaucrat
  - Class with a constant name and a grade between 1 and 150.
  - Methods to increment/decrement the grade.
  - Throws GradeTooHighException or GradeTooLowException.
  - Overload of operator<<.
  Focus: basic exceptions and state validation.

- ex01 – Form
 - Class Form with:
 - constant name
 - signed status
 - required grade to sign
 - required grade to execute
 - Method beSigned(Bureaucrat).
 - Bureaucrat gains signForm().
 Focus: object interaction and exception propagation.

- ex02 – AForm + concrete forms
 - Form becomes abstract → AForm.
 - Adds execute() and executeForm().
 - Concrete forms:
 - Shrubbery → writes ASCII trees to a file.
 - Robotomy → 50% success rate.
 - Presidential Pardon → prints a message.
 Focus: abstraction, polymorphism, and execution rules.

- ex03 – Intern
 - Class Intern with method makeForm(name, target).
 - Creates the appropriate form dynamically.
 - Prints a message when successful.
 - Prints an error if the form name is unknown.
 - Must avoid messy if/else chains.
 Focus: factory pattern and clean design.
