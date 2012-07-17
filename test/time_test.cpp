#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "mxgame/system/time/time.hpp"

using namespace mxgame;

int main() {
    for (int i = 0; i < 100; i++) {
        printf("%d - Ticks %u\n", i, Time::GetTicks());
        Time::Delay(1000);
    }

    return 0;
}
