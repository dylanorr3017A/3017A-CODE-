using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FL;
extern motor FR;
extern motor RL;
extern motor RR;
extern controller Controller1;
extern digital_out Indexer;
extern motor_group Flywheel;
extern motor RollerMech;
extern motor Intake;
extern digital_out Expantion;
extern controller Controller2;
extern optical Roller_sensor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );