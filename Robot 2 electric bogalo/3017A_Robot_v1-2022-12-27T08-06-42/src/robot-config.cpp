#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor fly_wheelMotorA = motor(PORT11, ratio6_1, false);
motor fly_wheelMotorB = motor(PORT2, ratio6_1, true);
motor_group fly_wheel = motor_group(fly_wheelMotorA, fly_wheelMotorB);
motor Roller_mech = motor(PORT20, ratio18_1, false);
motor Intake = motor(PORT16, ratio18_1, false);
optical roler_mech_sensor = optical(PORT4);
digital_out Indexer = digital_out(Brain.ThreeWirePort.A);
digital_out Expantion = digital_out(Brain.ThreeWirePort.B);
motor leftMotorA = motor(PORT7, ratio18_1, true);
motor leftMotorB = motor(PORT9, ratio18_1, true);
motor_group LeftDriveSmart = motor_group(leftMotorA, leftMotorB);
motor rightMotorA = motor(PORT8, ratio18_1, false);
motor rightMotorB = motor(PORT12, ratio18_1, false);
motor_group RightDriveSmart = motor_group(rightMotorA, rightMotorB);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
controller Controller2 = controller(primary);
controller Controller1 = controller(partner);

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