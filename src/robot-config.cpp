#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor MotorUL = motor(PORT9, ratio18_1, false);
motor MotorUR = motor(PORT2, ratio18_1, false);
motor MotorLL = motor(PORT10, ratio18_1, false);
motor MotorLR = motor(PORT1, ratio18_1, false);
controller Controller1 = controller(primary);
gps GPS = gps(PORT12, -2.00, -275.00, mm, 180);
inertial Inertial = inertial(PORT8);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}