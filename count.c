#include "count.h"

int update_hilo_count(const int current_count, const Card card) {
    if (card >= TEN) {
        return current_count - 1;
    } else if (card <= SIX) {
        return current_count + 1;
    } else {
        return current_count;
    }
}
