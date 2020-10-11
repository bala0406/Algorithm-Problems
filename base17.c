#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    char input[50];
    fgets(input,sizeof input,stdin);
    int result = 0;
    int power = 0;
    for(int i = (strlen(input) - 2); i >=0; i--)
    {
        if((int)input[i] >= (int) '0' && (int)input[i] <= (int) '9')
        {
            result += ((int)input[i] - (int)'0') * ((int)pow(17,power++));
        }
        else
        {
            int number = ((int)input[i] - (int)'A') + 10;
            result += (number + ((int)pow(17,power++)));
        }
    }
    printf("%d",result);
    return 0;
}
