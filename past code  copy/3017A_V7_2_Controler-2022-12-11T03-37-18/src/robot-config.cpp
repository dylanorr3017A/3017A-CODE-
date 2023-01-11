#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FL = motor(PORT11, ratio18_1, true);
motor FR = motor(PORT19, ratio18_1, true);
motor RL = motor(PORT10, ratio18_1, true);
motor RR = motor(PORT1, ratio18_1, true);
controller Controller1 = controller(primary);
digital_out Indexer = digital_out(Brain.ThreeWirePort.A);
motor FlywheelMotorA = motor(PORT13, ratio6_1, false);
motor FlywheelMotorB = motor(PORT17, ratio6_1, true);
motor_group Flywheel = motor_group(FlywheelMotorA, FlywheelMotorB);
motor RollerMech = motor(PORT8, ratio18_1, false);
motor Intake = motor(PORT16, ratio18_1, false);
digital_out Expantion = digital_out(Brain.ThreeWirePort.H);
controller Controller2 = controller(partner);
optical Roller_sensor = optical(PORT9);

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