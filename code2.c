#include <stdio.h>

//Function to convert celcius to farenheit
float celcius_to_farenheit(float user_temp) {
    return (9 * user_temp) / 5 + 32;
}


//function to convert celcius to kelvin
float celcius_to_kelvin(float user_temp) {
    return user_temp + 273.15;
}

//function to convert farenheit to celcius
float fahrenheit_to_celsius(float user_temp) {
    return (5 * (user_temp - 32)) / 9;
}


//function to convert kelvin to celcius
float kelvin_to_celsius(float user_temp) {
    return user_temp - 273.15; // Corrected from 273.1 to 273.15
}


//Function which converts all temperatures into celcius
float all_to_celcius(float user_temp, int user_scale) {
    switch(user_scale) {
        //The given temperature is in celcius
        case 1:
            return user_temp; // Just return celsius
        //The given temperature is in farenheit
        case 2:
            return fahrenheit_to_celsius(user_temp); // Fahrenheit to Celsius
        //The given temperature is in kelvin
        case 3:
            return kelvin_to_celsius(user_temp); // Kelvin to Celsius
    }
}

//Function which takes in a temperature and advises the user on what to do if they go outside
void categorize(float temp, int user_scale) {
    float final_temp = all_to_celcius(temp, user_scale); //Convert the given temperature to celcius
    
    //Below freezing
    if (final_temp < 0) {
        printf("Temperature Category: Freezing\nAdvisory: Stay indoors!\n");
    //Chilly
    } else if (final_temp >= 0 && final_temp <= 10) {
        printf("Temperature Category: Cold\nAdvisory: Please wear a jacket\n");
    //Comfortable
    } else if (final_temp > 10 && final_temp <= 25) {
        printf("Temperature Category: Comfortable\nAdvisory: You should be comfortable\n");
    //Hot
    } else if (final_temp > 25 && final_temp <= 35) {
        printf("Temperature Category: Warm\nAdvisory: Drink lots of water\n");
    //Very hoy
    } else {
        printf("Temperature Category: Extreme Heat\nAdvisory: Stay indoors!\n");
    }
}

int main() {
    int loop_num = 1; //variable that keeps the loop going

    //keep looping forever
    while (loop_num == 1) {
        float user_temp; //stores the user's input for temperature
        int user_scale; //stores the temperature scale the user is initally using
        int convert_to; //The temperature scale that the user want to convert to

    //Asks the user for a temperature
    printf("Please input a temperature: ");
        while (scanf(" %f", &user_temp) != 1) { //Makes sure that the temperature is a valid number
            printf("Invalid input. Please enter a valid NUMBER: "); //ask the user to input another temperature if theirs was invalid
            while (getchar() != '\n'); //Clear the input so there is no infinite loops
        }

        //Ask the user what temperature system their temperature uses
        printf("Choose the scale you are using (1 = Celsius, 2 = Fahrenheit, 3 = Kelvin): ");
        scanf(" %d", &user_scale);

        //Lastly, ask what they would like to convert their temperature into
        printf("Now what would you like to convert it into? (1 = Celsius, 2 = Fahrenheit, 3 = Kelvin): ");
        scanf(" %d", &convert_to);

        //switch that takes the user's initial temperature scale
        switch (user_scale) {

            case 1: // Celsius
                switch (convert_to) {
                    case 1: //The user may not convert celsius to celsius
                        printf("Invalid input\n");
                        break;
                    case 2://Celcius to farenheit
                        printf("\nConverted Temperature: %.2f°F\n", celcius_to_farenheit(user_temp));
                        categorize(user_temp, user_scale);
                        break;
                    case 3://Celcius to kelvin
                        printf("\nConverted Temperature: %.2f K\n", celcius_to_kelvin(user_temp));
                        categorize(user_temp, user_scale);
                        break;
                    default: //Break if the input is invalid
                        printf("Could not Convert!\n");
                        break;
                }
                break;

            case 2: // Fahrenheit
                switch (convert_to) {
                    case 1: //farenheit to celcius
                        printf("\nConverted Temperature: %.2f°C\n", fahrenheit_to_celsius(user_temp));
                        categorize(user_temp, user_scale);
                        break;
                    case 2: //Cannot convert farenheit to farenheit
                        printf("Invalid input\n");
                        break;
                    case 3://farenheit to kelvin
                        printf("\nConverted Temperature: %.2f K\n", celcius_to_kelvin(fahrenheit_to_celsius(user_temp)));
                        categorize(user_temp, user_scale);
                        break;
                    default://Break if the input is invalid
                        printf("Could not convert!\n");
                        break;
                }
                break;

            case 3: // Kelvin (The user's input may not be below 0. Otherwise it breaks)
                switch (convert_to) {
                    case 1: //convert kelvin to celcius
                        if (user_temp >=0){
                        printf("\nConverted Temperature: %.2f°C\n", kelvin_to_celsius(user_temp));
                        categorize(user_temp, user_scale);}
                        break;
                    case 2://convert kelvin to farenheit
                     if (user_temp >=0){
                        printf("\nConverted Temperature: %.2f°F\n", celcius_to_farenheit(kelvin_to_celsius(user_temp)));
                        categorize(user_temp, user_scale);}
                        break;
                    case 3: //Cannot convert kelvin into kelvin
                     if (user_temp >=0){
                        printf("Invalid input\n");
                        break;}
                    default: //Break if the input is invalid
                        printf("Invalid conversion\n");
                        break;
                }
                break;

            default:
                printf("--Bad Scale--\n"); //Break if the user's scale is not valid
                break;
        }
    }

    return 0;
}
