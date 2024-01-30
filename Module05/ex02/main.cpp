#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  {
    std::cout << "------ Bureaucrat tests ------" << std::endl;
    try {
      std::cout << "try Bureaucrat too high ------" << std::endl;
      Bureaucrat b("Bob", 0);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat just right ------" << std::endl;
      Bureaucrat b("Bob", 50);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat too low ------" << std::endl;
      Bureaucrat b("Bob", 151);
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat 1 increment ------" << std::endl;
      Bureaucrat b("Bob", 1);
      b.incrementGrade();
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat 150 decrement ------" << std::endl;
      Bureaucrat b("Bob", 150);
      b.decrementGrade();
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
    std::cout << "try Bureaucrat 50 grade changes ----" << std::endl;
    Bureaucrat f("Fiver", 50);
    std::cout << f << std::endl;
    std::cout << "increment grade ----" << std::endl;
    f.incrementGrade();
    std::cout << f << std::endl;
    std::cout << "decrement grade two times ----" << std::endl;
    f.decrementGrade();
    f.decrementGrade();
    std::cout << f << std::endl;
    try {
      std::cout << "try Bureaucrat catch GradeTooHighException ------"
                << std::endl;
      Bureaucrat b("Bob", 0);
    } catch (Bureaucrat::GradeTooHighException& e) {
      std::cout << e.what() << std::endl;
    }
    try {
      std::cout << "try Bureaucrat catch GradeTooLowException ------"
                << std::endl;
      Bureaucrat b("Bob", 151);
    } catch (Bureaucrat::GradeTooLowException& e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    {
      std::cout << std::endl << "------ ShrubberyCreationForm tests ------" << std::endl;
      std::cout << "* test initializing without target" << std::endl;
      ShrubberyCreationForm f1("beta");
      Bureaucrat b1("Bob", 1);
      std::cout << f1 << std::endl << b1 << std::endl;
      try {
        b1.signForm(f1);
      } catch (std::exception& e) {
        std::cout << "Caught exception while signing AForm: " << e.what()
                  << std::endl;
      }
      std::cout << f1 << std::endl;
      try {
        b1.executeForm(f1);
      } catch (std::exception& e) {
        std::cout << "Caught exception while executing AForm: " << e.what()
                  << std::endl;
      }
    }
  }
}
