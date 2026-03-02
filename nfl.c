#include <stdio.h>
int recursive_score(int score, int td, int fg, int safety, int td2, int tdfg, int minimum_play_allowed) {
    
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, tdfg, td, fg, safety);
        return 1;

    }
    if (score < 0) return 0;
    if (score >= 2 && minimum_play_allowed <= 2) recursive_score(score - 2, td, fg, safety+1, td2, tdfg, 2);
    if (score >= 3 && minimum_play_allowed <= 3) recursive_score(score - 3, td, fg+1, safety, td2, tdfg, 3);
    if (score >= 6 && minimum_play_allowed <= 6) recursive_score(score - 6, td+1, fg, safety, td2, tdfg, 6);
    if (score >= 7 && minimum_play_allowed <= 7) recursive_score(score - 7, td, fg, safety, td2, tdfg+1, 7);
    if (score >= 8 && minimum_play_allowed <= 8) recursive_score(score - 8, td, fg, safety, td2+1, tdfg, 8);
    return 0;
}
int main() {
    printf("enter 0 or 1 to stop: ");
    int score;
    printf("Enter the NFL score: ");
    scanf("%d", &score);
    if (score <= 1) {
        return 0;
    }
    recursive_score(score, 0, 0, 0, 0, 0, 2);
    while (score > 1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            return 0;
        }
        recursive_score(score, 0, 0, 0, 0, 0, 2);
    }
    return 0;
    
}