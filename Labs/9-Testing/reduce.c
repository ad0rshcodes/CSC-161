/* Program to reduce fractions by calculating the greatest common denominator
 * Jerod Weinman
 *
 * In Book 7 of Euclid's Elements (ca 300 BC), Proposition 1
 * [http://aleph0.clarku.edu/~djoyce/elements/bookVII/propVII1.html] and
 * Proposition 2
 * [http://aleph0.clarku.edu/~djoyce/elements/bookVII/propVII2.html] detail a
 * method for finding the greatest common divisor of two positive integers.
 *
 * In the Art of Computer Programming (Volume 1, p. 2), Donald E. Knuth
 * describes it this way:
 *
 *    Given two positive integers m and n, find their greatest common divisor,
 *    that is, the largest positive integer that evenly divides both m and n.
 *
 *        1. [Find remainder.] Divide m by n and let r be the remainder.
 *             (We will have 0 ≤ r< n.)
 *        2. [Is it zero?] If r = 0, the algorithm terminates; n is the answer.
 *        3. [Reduce.] Set m ← n, n ← r, and go back to step 1.
 */
#include <stdio.h>
#include <assert.h>

/* gcd - Calculates the greatest common denominator of two positive integers
 *
 * Pre-conditions: n>0
 * Post-conditions:
 *    Result g>0 such that (m % g) == (n % g) == 0; no larger g has
 *       this property.
 */
unsigned long gcd(unsigned long m, unsigned long n)
{
	unsigned long remainder = m % n;

	if (remainder == 0)
		return n;

	return gcd(n, remainder);
}

/* reduce - Returns fractional entries in reduced form
 *
 * Preconditions:
 *   numerator and denominator are valid arrays with (at least) one element each
 *   numerator[0] is the numerator
 *   denominator[0] is the (positive) denominator
 *
 * Postconditions:
 *   Let g = gcd(|numerator[0]|,denominator[0]);
 *   numerator[0]AFTER == numerator[0]BEFORE / g;
 *   denominator[0]AFTER = denominator[0]BEFORE / g;
 */
void reduce(unsigned long numerator[1], unsigned long denominator[1])
{
  assert(sizeof(numerator)/sizeof(numerator[0]) >= 1 && sizeof(denominator)/sizeof(denominator[0])) >= 1);
  assert(denominator[0] > 0);

  long gcd_factor = gcd(numerator[0], denominator[0]);

  numerator[0] = numerator[0] / gcd_factor;
  denominator[0] = denominator[0] / gcd_factor;

  return;
}

/* main: Run a simple test of reduce and GCD */
int main()
{
	unsigned long top;
	unsigned long bottom;
	int numAssigned;

	/* Read values */
	printf("Enter numerator: ");
	numAssigned = scanf("%ld", &top);

	if (numAssigned == 0)
	{
		printf("Error reading numerator.");
		return 1;
	}

	printf("Enter denominator: ");
	numAssigned = scanf("%lu", &bottom);

	if (numAssigned == 0)
	{
		printf("Error reading denominator.");
		return 1;
	}

	/* Print and calculate result */
	printf("%ld/%lu", top, bottom);

	reduce(&top, &bottom);
	printf("=%ld/%lu\n", top, bottom);

	return 0;
}