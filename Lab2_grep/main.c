/** CMPSC 474 /CMPEN 441

 *File Name: Begin with "project" and then the project number, for example, proj1.c, or proj1.h.

 *Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at:
https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines

 *Assisted by and Assisted line numbers:

 *
 *Your Name: Thomas F. Roseman
 *
 *Your PSU user ID:  924584317
 *
 *CMPSC474 Spring 2016
 *
 *Due Time: Time, Day-of-week, Month Day, Year
 *
 *Time of Last Modification: Time, Day-of-week, Month Day, Year
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int count = 0;
    char *flag = "-c";


    //We can only take 3 or 4 arguments
    if (argc < 3 || argc > 4) {
        printf("There was an incorrect number of arguments.\n");
        exit(0);
    }

    //Flag -c was passed
    if (argv[1] == flag) {

        FILE *file = fopen(argv[3], "r");

        if (!file) {
            printf("File not found.\n");
            exit(1);
        } else {
            //File is found
            char buf[100];
            while (fgets(buf, sizeof(buf), file)) {
                char *pos = strstr(argv[2], buf);
                if (pos != NULL) {
                    count++;
                }
            }
        }

        printf("%d\n", count);
        exit(0);
    } else {
        //No flag was given output the lines when found
        FILE *file = fopen(argv[2], "r");

        if (!file) {
            printf("File not found.\n");
            exit(1);
        } else {
            //File is found
            char buf[100];
            while (fgets(buf, sizeof(buf), file)) {
                char *pos = strstr(buf, argv[1]);
                if (pos != NULL) {
                    printf("%s\n", buf);
                }
            }
            exit(0);
        }
    }
}

/**
 * Hints
 * fgets(...) fopen(...) strstr(...) fprintf(...)
 */

//lab2 [word to match] [file]
//lab2 [flag(-c)] [word] [file]

