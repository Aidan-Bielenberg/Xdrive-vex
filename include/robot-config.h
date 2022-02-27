using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor MotorUL;
extern motor MotorUR;
extern motor MotorLL;
extern motor MotorLR;
extern controller Controller1;
extern gps GPS;
extern inertial Inertial;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );