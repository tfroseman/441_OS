/** CMPSC 474 /CMPEN 441
 * Lab 1
 * File Name: proj1.c
 *
 *Your Name: Thomas Roseman
 *
 *Your PSU user ID:  tfr5029
 *
 *CMPSC474 Spring 2016
 *

 *Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at:
https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines

 *Assisted by and Assisted line numbers:
 */


#include <stdio.h>
#include <assert.h>

struct numlist {
	float *list;   /* points to list of numbers in an array */
	int   len;     /* number of items in list   */
	float min,     /* the minimal value in list */
	max,     /* the maximal value in list */
	avg;     /* the mean of the numbers   */
};

void compute_stats(struct numlist *lp)
{
    lp->min = lp->list[0];
    lp->max = 0;
	for (int i = 0; i < lp->len; ++i) {
        if(lp->list[i] > lp->max){
            lp->max = lp->list[i];
        }
        if(lp->list[i] < lp->min){
            lp->min = lp->list[i];
        }
        lp->avg += lp->list[i];
	}

    lp->avg = lp->avg / lp->len;
}

/**
 * Outputs all of the data from the numlist
 */
void print_nums(struct numlist *lp)
{

    printf("numlist::list = { ");
    for (int i = 0; i < lp->len; ++i) {
        if(i == lp->len-1){
            printf("%f ", lp->list[i]);
        }else {
            printf("%f, ", lp->list[i]);
        }
    }
    printf("}\n");

    printf("numlist::len %d\n", lp->len);
    printf("numlist::min %1.6f\n", lp->min);
    printf("numlist::max %1.6f\n", lp->max);
    printf("numlist::avg %1.6f\n", lp->avg);

}

int main(int argc, char **argv)
{
	/* Build a simple numlist to test
	float data[10] = { 0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1 };
	struct numlist l;

	l.list = data;
	l.len = 10;

	compute_stats(&l);

	print_nums(&l);

	return 0;
}

/**
 *numlist::list = { 0.100000, 1.100000, 2.100000, 3.100000, 4.100000, 5.100000, 6.100000, 7.100000, 8.100000, 9.100000 }
 * numlist::len 10
 * numlist::min 0.100000
 * numlist::max 9.100000
 * numlist::avg 4.600000
*/
