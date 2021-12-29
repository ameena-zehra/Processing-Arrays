/* CS2211a 2021 */
/* Assignment 02 */
/* Ameena Naqvi */
/* 251173552 */
/* anaqvi23 */
/* Date Completed: October 5, 2021 */

#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#define ITERATION_NUMBER 3
#undef DEBUG

int main()
{   printf("Assignment Two\n\n");
    // STEP #1: Determine the size of the array
    // This size of the array is randomly selected based on the lower and upper boundaries described below
    int lower = 50, upper = 50 * ITERATION_NUMBER; // These variables set out the lower and upper range of the array size based on the number of iterations
    srand(time(NULL));
    int arraysize = (rand() % (upper-lower+1))+lower; // This variable sets out the size of the array calculated within the set range using the random number generator
    int originalsize= arraysize; // This variable records the array size to ensure it does not change during execution
    int newarray[arraysize];
    printf("Value of random size of array : %d\n", arraysize+1);
    printf("Size of array: %lu bytes\n\n", sizeof(newarray) );
    for (int i=1; i<=ITERATION_NUMBER; i++){
        printf("\n-----------------------------------------------------------------------\n");
        arraysize = originalsize; 
        printf("\n\nTHIS IS ITERATION NUMBER %d of %d\n", i, ITERATION_NUMBER);
        
        // STEP #2: Establishing a range of numbers
        // The upper range of numbers is determined based on the current iteration number  
        int upperboundaryforrange = 1; // This variable records the upper boundary for the range based on the iteration number
        for (int j=i; j<= ITERATION_NUMBER; j++){
            upperboundaryforrange*=10;
        }
        // DEBUG #1 Upper Range Values
        #if defined (DEBUG)
            printf("Upper Range Value: %d\n", upperboundaryforrange);
        #endif
        
        // STEP #3: Populate the array
        // The array is populated using a random selection of numbers between 1 and the upper range determined from step 2
        for (int k=0; k<=arraysize; k++){
           if (k==0){
                srand(time(NULL));
            }
            int numbertoinsert = (rand() % (upperboundaryforrange))+1; // This variable randomly selects a number within the range of 1 to the upper boundary 
            newarray[k]= numbertoinsert; // This number is then inserted into the array
        }
        
        printf("\nThis is the original array populated with values in range 1 to %d\n", upperboundaryforrange);
        
        printf("\nNumber of elements in the original array is : %d \n", arraysize+1);
         for (int k=0; k<=arraysize; k++){
             if ((k%10)==0){
                 printf("\n");
             }
             if (((k-1)%10)==0){
                printf("%6d",newarray[k]);
             }
            else{
                printf(" %6d",newarray[k]);
            }
        }
        printf("\n\nThis is the current state of the array with all duplicate values removed\n");
        
        // STEP #4: Removing all duplicates
        // Starting at index 0 the for loop structure removes all duplicates from the array adding a zero for any duplicates found
        for (int k=0; k<=arraysize; k++){
            int numberofduplicates = 0; // This variable is used to track the number of duplicates of each variable in the list 
            for (int j=0; j<=arraysize; j++){
                if ((newarray[k]!=0)&&(newarray[k]==newarray[j])&&(k!=j)){
                    numberofduplicates++; // If a duplicate is found the counter is added
                }
            }
            for (int z=0; z<=numberofduplicates; z++){
                for (int j=0; j<=arraysize; j++){
                    if ((newarray[k]!=0)&&(newarray[k]==newarray[j])&&(k!=j)){
                        // DEBUG #2: Displays each time when matching values are found along with the indexes of matching values
                        #if defined (DEBUG)
                            printf("The value of %d at array index [%d] and the value of %d at array index [%d] are the same.\n", newarray[k], k, newarray[j], j);
                        #endif
                        for (int m=j; m<=arraysize; m++){
                            newarray[m]=newarray[m + 1];
                            // The new array is shifted to the left by one anytime a duplicate is found
                        }
                        newarray[arraysize] = 0;
                        // Once the shift to the left occurs the last spot of the array is filled with a zero
                    }
                }
            }
        }
    
    
        // STEP #5: Removal of zeroes
        // In this step all zeroes placed at the end of the array in step 4 are removed from the array 
        for (int k=0; k<=arraysize; k++){
            for (int j=k ; j<=arraysize; j++){
                if (newarray[k]==0){
                    for (int m=j; m<=arraysize; m++){
                        newarray[m]=newarray[m + 1];
                        
                    }
                    arraysize--;
                    j--;
                }
            }
        }
        printf("\nNumber of unique (non-zero, non-duplicate) elements in the array is : %d \n", arraysize+1);

        for (int k=0; k<=arraysize; k++){
             if ((k%10)==0){
                 printf("\n");
             }
             if (((k-1)%10)==0){
                printf("%6d",newarray[k]);
             }
            else{
                printf(" %6d",newarray[k]);
            }
        }

        
        printf("\n\nThese are the unique, non-zero elements in the array sorted in ascending order :\n");


        // STEP #6: Ordering Array in Ascending Order
        // Using the for loop structure below the array is ordered from lowest to highest 
        for(int a=0; a<arraysize; a++)
        {
            for(int j=a+1; j<=arraysize; j++)
            {
                if(newarray[j] <newarray[a])
                {
                    int tmp = newarray[a];
                    newarray[a] = newarray[j];
                    newarray[j] = tmp;
                }
            }
        }


        for (int k=0; k<=arraysize; k++){
             if ((k%10)==0){
                 printf("\n");
             }
             if (((k-1)%10)==0){
                printf("%6d",newarray[k]);
             }
            else{
                printf(" %6d",newarray[k]);
            }
        }
        
    }
    

    return 0;
}
