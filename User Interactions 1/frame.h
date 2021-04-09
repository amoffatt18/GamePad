#include <Metro.h>

int rateD = 0;

Metro frameRate = Metro(1000);

void checkFrame () {

  if (frameRate.check()) {

    rateD = 0;
  }
  rateD = rateD + 1;
}
