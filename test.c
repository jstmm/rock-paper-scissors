#include <criterion/criterion.h>

#include "game.h"

Test(simple_1, test) {
    cr_assert(2 + 3 == 5, "Incorrect");
}

Test(simple_2, test) {
    cr_assert(2 + 3 == 5, "Incorrect");
}

Test(simple_3, test) {
    cr_assert(2 + 3 == 5, "Incorrect");
}

Test(simple_addition, test) {
    cr_assert(addition(2, 3) == 5, "Incorrect");
}
