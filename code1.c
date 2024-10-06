#include <stdio.h>

void scoring_combinations(int score) {
    // Variables that store all of the possible ways to score
    int td_0 = 6; //touchdown
    int td_1= 7; //touchdown + field goal
    int td_2 = 8; //touchdown + point conversion
    int fg = 3; //field goal
    int safety = 2; //safety

    printf("Possible combinations for score = %d:\n", score);

    // A 5 layer nested loop which checks for all of the combinations of scores
    for (int touchdown = 0; touchdown <= score / td_0; touchdown++) { //touchdown
        for (int tds_2pt = 0; tds_2pt <= score / td_2; tds_2pt++) { //touchdown + point conversion
            for (int tds_1pt = 0; tds_1pt <= score / td_1; tds_1pt++) { //touchdown + fg
                for (int FGs = 0; FGs <= score / fg; FGs++) { //field goal
                    for (int safeties = 0; safeties <= score / safety; safeties++) { //safeties

                        // Get the total score for the current combination of scores
                        int final_score = (touchdown * td_0) + (FGs * fg) + (safeties * safety) + (tds_2pt * td_2) + (tds_1pt * td_1);
                        
                        // Check the final score matches the given score
                        if (final_score == score) {
                            printf("TD: %d, FG: %d, Safety: %d, TD + 2pt: %d, TD + 1pt: %d\n", touchdown, FGs, safeties, tds_2pt, tds_1pt);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    //loop forever until the loop is broken
    while (1) {

        //Ask the user for an NFL score
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score);

        //If the given score is 1 or 0. Break the infinite loop
        if (score < 2) {
            printf("Goodbye!\n");
            break;
        }

        scoring_combinations(score); //Call scoring_combinations using the score
    }

    return 0;
}
