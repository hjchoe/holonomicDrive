#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

motor frontMotor = motor(PORT5, ratio18_1, true);
motor backMotor = motor(PORT7, ratio18_1, false);
motor leftMotor = motor(PORT8, ratio18_1, false);
motor rightMotor = motor(PORT9, ratio18_1, true);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}