/* windchill.c
 *
 * Author: Adarsh Sharma, Judd Brau
 * Date: June 20, 2022
 * Revised: September 9, 2024
 * Purpose: to calculate the windchill based on two inputs:
 *		temperature (Fahrenheit) assumed to be an integer
 *      windspeed (miles per hour) assumed to be an integer
 *		forumula:  Twc = F - (W * 0.7)
 *      forumula from  Tom Skilling at the Chicago Tribune
 */
 
#include <stdio.h>

int main(void) {

	int temp = 0;
	int windspeed = 0;

	// tell user what to expect
	printf("This program will calculate the windchill based on still air temperature");
	printf(" and wind speed using a simplified calculation.\n");
	
	
	// prompt user for inputs, which are assumed to be two integers with no errors from the user
	printf("What is the temperature in Fahrenheit (whole number only)? \n");
	scanf("%d", &temp);
	
	printf("What is the wind speed in miles per hour (whole number only)\n");
	scanf("%d", &windspeed);
	
	// ADD your code here!
        float twc = temp - (windspeed * 0.7);

        if (twc < -30) {
          printf("TWC: %f - EXTREME DANGER\n", twc);
        } else if (twc < 0) {
          printf("TWC: %f - Moderate danger\n", twc);
        } else {
          printf("TWC: %f - your fine!\n",   twc);
        }

        // C. 
        
        if(windspeed < 1){
          printf("Calm");
        }
        else if (windspeed <= 7){
          printf("Light");
        }
        else if (windspeed <= 12){
          printf("Gentle");
        }
        else if (windspeed <= 18){
          printf("Moderate");
        }
        else if (windspeed <= 24){
          printf("Fresh");
        }
        else if (windspeed <= 38){
          printf("Strong");
        }
        else if (windspeed <= 54){
          printf("Gale");
        }
        else if (windspeed <= 75){
          printf("Whole Gale");
        }
        else {
          printf("Hurricane");
        }

        // Since we are comapring intervals with windspeed, we can't use a switch statement. It only works if you are comparing constants. 
        
	return 0;

}


