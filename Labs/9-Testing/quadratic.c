/* Program to illustrate 4 functions related to the quadratic formula 
 * given a, b, and c, the formula computes solutions to
 *    a * x^2 +b * x + c = 0
 * if discriminant = sqrt (b*b - 4*a*c), a != 0, and discriminant > 0,
 * then the two real solutions of this equation are
 *   (-b + discriminant) / (2.0 * a)
 * and
 *   (-b - discriminant) / (2.0 * a)
 * 
 * This variant was created by Jerod Weinman, based on a program developed by 
 * Henry Walker. The majority of the differences are reflected in the 
 * comments explaining the quadratic equation.
 *
 * compile, linking to the math library, using the following command:
 * clang -lm -o quadratic quadratic.c
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>

/* Print a quadratic equation given the coefficients */
void printEquation(double coeff2, double coeff1, double coeff0)
{
	printf("Equation:  %lf*x^2 + %lf*x + %lf = 0\n",coeff2,coeff1,coeff0);
	return;
}

/* Compute the discriminant of a quadratic equation 
 *   r*x^2 + s*x + t = 0 given the coefficients r, s, and t.
 *  
 *  Precondition:
 *    s*s >= 4*r*t
 *  Postcondition:
 *    returns the square root of s*s - 4*r*t
 */
       
double computeDiscriminant(double r, double s, double t)
{
        assert(pow(s,2) >= 4*r*t);
	return sqrt(s * s - 4 * r * t);
}

/* Print both roots of a quadratic equation a*x^2 + b*x + c = 0.
 *
 * Preconditions:
 *   Both roots must be real
 *   a != 0
 */
void printRoots(double a, double b, double c)
{
        assert(a!=0);
	double discriminant = computeDiscriminant(a,b,c);
	double root1 = (-b + discriminant) / (2.0 * a);
	double root2 = (-b - discriminant) / (2.0 * a);

	printf("    Roots:  %lf and %lf\n",root1,root2);
	return;
}

/* Control processing for x^2 - 3*x + 2.0 = 0: prints equation and its roots */
void displayExample1()
{
	printEquation(1.0,-3.0,2.0);
	printRoots(1.0,-3.0,2.0);
        // tested 0.0 here

	return;
}

/* Control processing for 2.0*x^2 - 7.0*x - 4.0 = 0.
 * Prints equation and its roots.
 */
void displayExample2()
{
	printEquation(2.0,-7.0,-4.0);
	printRoots(2.0,-7.0,-4.0);

	return;
}

/* Main function illustrating two equations with their solution via the quadratic formula */
int main()
{
	printf("program illustrating functions and the quadratic formula\n");

	displayExample1();
	displayExample2();

	return 0;
}
