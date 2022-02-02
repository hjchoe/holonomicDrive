/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       jameschoe                                                 */
/*    Created:      Wed Feb 02 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]         
// Controller1          controller         
// frontback            motor           
// frontMotor           motor         13
// backMotor            motor         17
// leftMotor            motor         14
// rightMotor           motor         16
// ---- END VEXCODE CONFIGURED DEVICES ----

// |-------------------- Library Imports --------------------|

#include <stdio.h>
#include "vex.h"
using namespace vex;

// |-------------------- Initialize Global Variables --------------------|

competition Competition;  // A global instance of competition

task driveMotors;

class driveTrain
{
  public:

  static bool rotateState;
  
  driveTrain()
  {
    refreshMotors();

    Controller1.Axis3.changed(setDirection);
    Controller1.Axis4.changed(setDirection);
    Controller1.Axis1.changed(setRotateDirection);
  }

  static void setRotateDirection()
  {
    rotateState = true;
    if (rotateState)
    {
      int rotate = Controller1.Axis1.position() ^ 3 / 20000;
      leftMotor.setVelocity(-rotate, percentUnits::pct);
      rightMotor.setVelocity(rotate, percentUnits::pct);
      frontMotor.setVelocity(rotate, percentUnits::pct);
      backMotor.setVelocity(-rotate, percentUnits::pct);
    }
    rotateState = false;
  }

  static void setDirection()
  {
    rotateState = false;
    if (!rotateState)
    {
      int updown = Controller1.Axis3.position() ^ 3 / 20000;
      int leftright = Controller1.Axis4.position() ^ 3 / 20000;

      leftrightGroup.setVelocity(updown, percentUnits::pct);
      frontbackGroup.setVelocity(leftright, percentUnits::pct);
    }
    rotateState = true;
  }

  void refreshMotors()
  {
    frontMotor.setVelocity(0, percentUnits::pct);
    backMotor.setVelocity(0, percentUnits::pct);
    leftMotor.setVelocity(0, percentUnits::pct);
    rightMotor.setVelocity(0, percentUnits::pct);
  }
};
bool driveTrain::rotateState = true;

// |-------------------- Function Definitions --------------------|

int driveMotorsCallback()
{
  while (true)
  {
    frontMotor.spin(forward);
    backMotor.spin(forward);
    leftMotor.spin(forward);
    rightMotor.spin(forward);

    wait(25, msec);
  }
  return 0;
}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void)
{
  vexcodeInit();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void)
{

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void pre_user(void)
{

}

void usercontrol(void)
{
  pre_user();

  driveTrain dt;
  driveMotors = task(driveMotorsCallback, vex::task::taskPriorityHigh);

  while (1)
  {
    wait(20, msec);
  }
}

int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}