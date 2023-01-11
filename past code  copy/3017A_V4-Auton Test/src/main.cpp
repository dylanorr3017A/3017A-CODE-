/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FL                   motor         11              
// FR                   motor         19              
// RL                   motor         10              
// RR                   motor         1               
// Controller1          controller                    
// Indexer              digital_out   A               
// Flywheel             motor_group   13, 17          
// RollerMech           motor         8               
// Intake               motor         15              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}
void  spinup (){
   Flywheel.setVelocity(100, percent);
    Flywheel.spin(forward);
};
 void  launchdisk(){
   Indexer.set(true);
  wait(.5,sec);
  Indexer.set(false);
  wait(1, seconds);
  Flywheel.stop();

 };
 
 void rollroller(){
RollerMech.spin(forward);
wait(2,sec);
RollerMech.stop();
 }
void stopall(){
  FL.stop();
  FR.stop();
  RL.stop();
  RR.stop();
}
void drivereverse(){
  FL.spin(reverse);
  FR.spin(forward);
  RL.spin(reverse);
  RR.spin(forward);
}
void driveforward(){
  FL.spin(forward);
  FR.spin(reverse);
  RL.spin(forward);
  RR.spin(reverse);
}
void turnright(){
  FL.spin(reverse);
  FR.spin(reverse);
  RL.spin(forward);
  RR.spin(forward);
}
void turnleft(){
  FL.spin(forward);
  FR.spin(forward);
  RL.spin(reverse);
  RR.spin(reverse);
}
void strafeleft(){
  FL.spin(forward);
  FR.spin(forward);
  RL.spin(forward);
  RR.spin(forward);
}
void straferight(){
  FL.spin(reverse);
  FR.spin(reverse);
  RL.spin(reverse);
  RR.spin(reverse);
}

void autonomous(void) {
  driveforward();//drive forward
  wait(1.3,sec);
  stopall();//stop
  wait(.1,sec);
  drivereverse();//drive back
  wait(1.4, sec);
  stopall();//stop
  wait(0.5, sec);
  drivereverse();//drive reverse
  wait(15, sec);
  stopall();//stop
  wait(0.5,sec);
  turnright();//turn right 90 degrees
  //rollrollermech
  //turn 

  // ..........................................................................
  //driveforward();// move forward 53.42"
  //start pickup mech
  //driveforward();//move forward 5"
  
  // ..........................................................................
}



void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
   Controller1.ButtonR1.pressed(spinup);
   Controller1.ButtonR2.pressed(launchdisk) ;
  
  RollerMech.setVelocity(75,percent);

  FR.spin(forward);
  FL.spin(forward);
  RL.spin(forward);
  RR.spin(forward);


   FL.setVelocity((-1.0 * Controller1.Axis1.position() + (Controller1.Axis2.position() + -1.0 * Controller1.Axis4.position())), percent);
    FR.setVelocity((-1.0 * Controller1.Axis1.position() - (Controller1.Axis2.position() - -1.0 * Controller1.Axis4.position())), percent);
    RL.setVelocity((-1.0 * Controller1.Axis1.position() + (Controller1.Axis2.position() + 1.0 * Controller1.Axis4.position())), percent);
    RR.setVelocity((-1.0 * Controller1.Axis1.position() - (Controller1.Axis2.position() - 1.0 * Controller1.Axis4.position())), percent);

    wait(20, msec); 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
