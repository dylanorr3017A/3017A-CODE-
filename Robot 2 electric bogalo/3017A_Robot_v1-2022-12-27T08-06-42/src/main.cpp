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
// fly_wheel            motor_group   11, 2           
// Roller_mech          motor         20              
// Intake               motor         16              
// roler_mech_sensor    optical       4               
// Indexer              digital_out   A               
// Expantion            digital_out   B               
// Drivetrain           drivetrain    7, 9, 8, 12     
// Controller2          controller                    
// Controller1          controller                    
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

  
}

void contnuckey()
   {
     Controller1.Screen.setCursor(1,1 );
      Controller2.Screen.setCursor(1,1 );

     Controller1.Screen.print("EXPAND!");
     Controller2.Screen.print("EXPAND!");

     Controller1.rumble(rumbleLong);
     Controller2.rumble(rumbleLong);
     wait(1,sec);
Controller1.Screen.clearLine();
Controller2.Screen.clearLine();

   }

void Flywheelspin () {
 fly_wheel.setVelocity(100,percent);
 fly_wheel.spin(forward);
};
void  launchdisk(){
   fly_wheel.spin(forward);
 waitUntil(fly_wheel.velocity(percent) >= 95);

   Indexer.set(true);
  wait(.5,sec);
  Indexer.set(false);
  wait(1, seconds);
  fly_wheel.stop();
  
 };

void  backup_launchdisk(){
Indexer.set(true);
  wait(.5,sec);
  Indexer.set(false);
  wait(1, seconds);
  fly_wheel.stop();
};
void  expand()
{Expantion.set(true);
  wait(.5,sec);
  Expantion.set(false);
};

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  Drivetrain.drive(forward);
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

////////////////////////////
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    float a1 = Controller2.Axis1.position();
    float a3 = Controller2.Axis3.position();


 Drivetrain.arcade(a3 , a1);
 //Drivetrain.setDriveVelocity(a3,percent);
//sets velocity
Intake.setVelocity(100, percent);

//start of callback control code
Controller1.ButtonR2.pressed(Flywheelspin );
Controller1.ButtonR1.pressed(launchdisk);
Controller2.ButtonA.pressed(backup_launchdisk);
//start of if control codel
Roller_mech.stop();
Intake.stop();

if(Controller1.ButtonL1.pressing()){
  Roller_mech.spin(forward);}
if(Controller1.ButtonL2.pressing()){
  Roller_mech.spin(reverse);}

if(Controller2.ButtonR1.pressing()){
  Intake.spin(forward);}
if(Controller2.ButtonR2.pressing()){
  Intake.spin(reverse);}
//end of if code 
//start of expantion code 
  if(Controller1.ButtonUp.pressing() && Controller2.ButtonUp.pressing())
  {expand();};

  Controller1.ButtonUp.pressed(contnuckey);

  
  Controller2.ButtonUp.pressed(contnuckey);

// end of expantion code


    wait(20, msec); 
                   
  }
}

//end of all user control code 
/////////////////////////////////
////////////////////////////////
///////////////////////////////
//////////////////////////////
/////////////////////////////
////////////////////////////
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  };
};

