# include <stdio.h>

int main()
{
    int speed,diff,limit;
    printf("Enter the speed limit: ");
    scanf("%d",&limit);
    printf("Enter the recorded speed of the car: ");
    scanf("%d",&speed);
    diff = speed - limit;
    if(diff <= 0)
        printf("Congratulations, you are within the speed limit");
    else if(diff>=1 && diff <= 20)
        printf("You are speeding and your fine is $ 100");
    else if(diff>=21 && diff <= 30)
        printf("You are speeding and your fine is $ 270");
    else
        printf("You are speeding and your fine is $ 500");

    return 0;
}
