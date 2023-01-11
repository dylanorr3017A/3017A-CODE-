/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       dylanorr                                                  */
/*    Created:      Thu Dec 22 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontL               motor         1               
// FrontR               motor         10              
// BackL                motor         2               
// BackR                motor         9               
// Tapper               motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  FrontR.spin(forward);
  frontL.spin(forward);
  BackR.spin(forward);
  BackL.spin(forward);
   frontL.setVelocity(( Controller1.Axis3.position() + Controller1.Axis4.position() + Controller1.Axis1.position() ),percent);
   FrontR.setVelocity(( Controller1.Axis3.position() - Controller1.Axis4.position() - Controller1.Axis1.position() ),percent);
   BackL.setVelocity(( Controller1.Axis3.position() + Controller1.Axis4.position() + Controller1.Axis1.position() ),percent);
   BackR.setVelocity(( Controller1.Axis3.position() - Controller1.Axis4.position() - Controller1.Axis1.position() ),percent); 
}