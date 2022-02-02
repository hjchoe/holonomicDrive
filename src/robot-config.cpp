#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller1;

motor_group frontbackGroup = motor_group(frontMotor, backMotor);
motor frontMotor = motor(PORT13, ratio18_1, false);
motor backMotor = motor(PORT17, ratio18_1, true);

motor_group leftrightGroup = motor_group(leftMotor, rightMotor);
motor leftMotor = motor(PORT14, ratio18_1, true);
motor rightMotor = motor(PORT16, ratio18_1, false);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}