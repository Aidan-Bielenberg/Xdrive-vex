/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       aidan                                                     */
/*    Created:      Mon Jan 17 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// MotorUL              motor         9
// MotorUR              motor         2
// MotorLL              motor         10
// MotorLR              motor         1
// Controller1          controller
// GPS                  gps           12
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int display() {
  while (true) {
    Controller1.Screen.clearLine();
    Controller1.Screen.print("%f", GPS.heading());
    wait(0.5, seconds);
  }
}

int driveLoop() {
  while (true) {
    int axisX = Controller1.Axis4.position();
    int axisY = Controller1.Axis3.position();
    int axisR = Controller1.Axis1.position();

    int dblimit = 5;

    if (axisX <= dblimit && axisX >= -1 * dblimit) {
      axisX = 0;
    }
    if (axisY <= dblimit && axisY >= -1 * dblimit) {
      axisY = 0;
    }
    if (axisR <= dblimit && axisR >= -1 * dblimit) {
      axisR = 0;
    }

    MotorUL.setVelocity(axisR + axisY + axisX, percent);
    MotorLL.setVelocity(axisR + axisY - axisX, percent);
    MotorUR.setVelocity(axisR - axisY + axisX, percent);
    MotorLR.setVelocity(axisR - axisY - axisX, percent);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  //=====INIT=====
  MotorUL.setVelocity(100, percent);
  MotorUR.setVelocity(100, percent);
  MotorLL.setVelocity(100, percent);
  MotorLR.setVelocity(100, percent);

  MotorUL.spin(forward);
  MotorUR.spin(forward);
  MotorLL.spin(forward);
  MotorLR.spin(forward);
  //==============

  GPS.calibrate();
  task t1(display);
  driveLoop();
}