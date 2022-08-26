#include<stdio.h>

int main()
{
    float numTotalStudents, numSatisfied;
    float satisfiedRatio;

    printf("How many students went to the new dining hall?\n");
    scanf("%f", &numTotalStudents);
    printf("How many of them are satisfied?\n");
    scanf("%f", &numSatisfied);

    satisfiedRatio = numSatisfied / numTotalStudents;
    
    // Prints different messages according to the ratio!
    if(satisfiedRatio == 0.5)
    {
        printf("Exactly half of the students are satisfied!\n");
    }
    else if(satisfiedRatio > 0.5)
    {
        printf("More students are satisfied! :)\n");
    }
    else if(satisfiedRatio < 0.5)
    {
        printf("More students are unsatisfied! :(\n");
    }
    else // In case if it divides by zero
    {
        printf("No one went to the dining hall?\n");
    }
    return 0;
}