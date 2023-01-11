/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       dylanorr                                                  */
/*    Created:      Thu Sep 29 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FL                   motor         19              
// FR                   motor         11              
// RL                   motor         10              
// RR                   motor         1               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
void stopall(){
  FL.stop();
  FR.stop();
  RR.stop();
  RL.stop();
}
void drivereverse(){
FL.spin(forward);
FR.spin(reverse);
RL.spin(reverse);
RR.spin(forward);

}
void driveforward(){
  FL.spin(reverse);
  FR.spin(forward);
  RL.spin(forward);
  RR.spin(reverse);
}

void turnright(){
FL.spin(forward);
FR.spin(forward);
RL.spin(reverse);
RR.spin(reverse);
}
void turnleft(){
FL.spin(reverse);
FR.spin(reverse);
RL.spin(forward);
RR.spin(forward);


}
void streyleft(){
FL.spin(forward);
FR.spin(forward);
RR.spin(forward);
RL.spin(forward);
}
void streyright(){
FL.spin(reverse);
FR.spin(reverse);
RR.spin(reverse);
RL.spin(reverse);
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  streyleft();
  wait(1,seconds);
  stopall();
  streyright();
  wait(1,seconds);
  stopall();
  turnright();
  wait(1,seconds);
  stopall();
  turnleft();
  wait(1,seconds);
  stopall();
  driveforward();
  wait(5,seconds);
  stopall();
  drivereverse();
  wait(5, seconds);
  };

  
