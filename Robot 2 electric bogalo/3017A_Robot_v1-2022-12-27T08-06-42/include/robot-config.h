using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor_group fly_wheel;
extern motor Roller_mech;
extern motor Intake;
extern optical roler_mech_sensor;
extern digital_out Indexer;
extern digital_out Expantion;
extern drivetrain Drivetrain;
extern controller Controller2;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );