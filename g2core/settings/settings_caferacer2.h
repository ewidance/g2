/*
 * settings_proxxon.h - Proxxon KT150 150mm table
 * This file is part of the TinyG project
 *
 * Copyright (c) 2010 - 2015 Alden S. Hart, Jr.
 * Adapted to Shapeoko Caferacer by jp.civade@labsud.org
 *
 * This file ("the software") is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2 as published by the
 * Free Software Foundation. You should have received a copy of the GNU General Public
 * License, version 2 along with the software.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, you may use this file as part of a software library without
 * restriction. Specifically, if other files instantiate templates or use macros or
 * inline functions from this file, or you compile this file and link it with  other
 * files to produce an executable, this file does not by itself cause the resulting
 * executable to be covered by the GNU General Public License. This exception does not
 * however invalidate any other reasons why the executable file might be covered by the
 * GNU General Public License.
 *
 * THE SOFTWARE IS DISTRIBUTED IN THE HOPE THAT IT WILL BE USEFUL, BUT WITHOUT ANY
 * WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
 * SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
 
 /* For Using GTwo shield, pinout must be modified to activate Spindle Dir 
    on TinyG2/platform/atmel_sam/board/due/gShield-pinout.h :
    	pin_number kSpindle_DirPinNumber            =  -1;//13;
    	pin_number kSpindle_DirPinNumber            =  13;//-1;
    Remement to add on Makefile
    	SETTINGS_FILE="settings_proxxon.h"
 */
/***********************************************************************/
/**** Proxxon KT 150 profile ******************************************/
/***********************************************************************/

// ***> NOTE: The init message must be a single line with no CRs or LFs
#define INIT_MESSAGE "Initializing configs to Proxxon profile"

//**** GLOBAL / GENERAL SETTINGS ******************************************************

#define JUNCTION_ACCELERATION       2000000					// $ja centripetal acceleration around corners - larger is faster
#define CHORDAL_TOLERANCE           0.01					// $ct chordal tolerance, accuracy for arc drawing (in mm)

#define SOFT_LIMIT_ENABLE           0						// $sl 0=off, 1=on
#define HARD_LIMIT_ENABLE           0						// $lim 0=off, 1=on
#define SAFETY_INTERLOCK_ENABLE     0						// $saf 0=off, 1=on

#define SPINDLE_ENABLE_POLARITY     0                       // $spep 0=active low, 1=active high
#define SPINDLE_DIR_POLARITY        0  	                    // $spdp 0=clockwise is low, 1=clockwise is high
#define SPINDLE_PAUSE_ON_HOLD       true					// $spph 0=no 1=pause
#define SPINDLE_DWELL_TIME          1.0						// $spdw Wait for Spindle Dwell before start (in seconds)

#define COOLANT_MIST_POLARITY       1                       // $comp 0=active low, 1=active high
#define COOLANT_FLOOD_POLARITY      1                       // $cofp 0=active low, 1=active high
#define COOLANT_PAUSE_ON_HOLD       false					// $coph 0=no, 1=pause on hold


// Feed rate usage : https://github.com/synthetos/g2/wiki/Feed-Rate-Override
//    Set master override enable to ON {m48e:1} (default = true, aloows to override feed and speed)
//    Set manual feed rate override ON {mfoe:1}
//    Enter / adjust manual feed rate override factor {mfo:N} where 0.05 < N < 2.00
#define MANUAL_FEEDRATE_OVERRIDE_ENABLE     true			// $mfoe 1=enable
#define MANUAL_FEEDRATE_OVERRIDE_PARAMETER  1.00			// $mfo Manual feed override value [0.05 < mfo < 2]

// Communications and reporting settings

#define TEXT_VERBOSITY              TV_VERBOSE              // $TV  one of: 0=TV_SILENT, 1=TV_VERBOSE
#define COMM_MODE                   JSON_MODE               // $EJ one of: 0=TEXT_MODE, 1=JSON_MODE

#define XIO_EXPAND_CR               false                   // $EC serial IO settings (AVR only)
#define XIO_ENABLE_ECHO             false					// $EE
#define XIO_ENABLE_FLOW_CONTROL     FLOW_CONTROL_XON        // $EX FLOW_CONTROL_OFF, FLOW_CONTROL_XON, FLOW_CONTROL_RTS

#define JSON_VERBOSITY              JV_MESSAGES             // $JV one of: 0=JV_SILENT, 1=JV_FOOTER, 3=JV_CONFIGS, 2=JV_MESSAGES, 4=JV_LINENUM, 5=JV_VERBOSE
#define JSON_SYNTAX_MODE            JSON_SYNTAX_STRICT      // $JS one of 0=JSON_SYNTAX_RELAXED, 1=JSON_SYNTAX_STRICT

#define QUEUE_REPORT_VERBOSITY		QR_OFF		            // $QV one of: 0=QR_OFF, 1=QR_SINGLE, 2=QR_TRIPLE

#define STATUS_REPORT_VERBOSITY     SR_FILTERED             // $SV one of: 0=SR_OFF, 1=SR_FILTERED, 2=SR_VERBOSE
#define STATUS_REPORT_MIN_MS        100                     // milliseconds - enforces a viable minimum
#define STATUS_REPORT_INTERVAL_MS   250                     // $SI milliseconds - set $SV=0 to disable
// Status report can be queried from ?<CR> in multiline text mode
//#define STATUS_REPORT_DEFAULTS "line","posx","posy","posz","posa","feed","vel","unit","coor","dist","admo","frmo","momo","stat"
// Alternate SRs that report in drawable units
//#define STATUS_REPORT_DEFAULTS "line","vel","mpox","mpoy","mpoz","mpoa","coor","ofsa","ofsx","ofsy","ofsz","dist","unit","stat","homz","homy","homx","momo"
// Mine
#define STATUS_REPORT_DEFAULTS "line","mpox","mpoy","mpoz","mpoa","posx","posy","posz","posa","feed","vel","unit","coor","dist","admo","frmo","momo","stat","homz","homy","homx", "in1", "in2", "in3", "in4", "in5", "in6", "in7", "in8"

// Gcode startup defaults
#define GCODE_DEFAULT_UNITS         MILLIMETERS             // $GUN 0=G20=MILLIMETERS or 1=G21=INCHES
#define GCODE_DEFAULT_PLANE         CANON_PLANE_XY          // $GPL 0=G17=CANON_PLANE_XY, 1=G18=CANON_PLANE_XZ, or 2=G19=CANON_PLANE_YZ
#define GCODE_DEFAULT_COORD_SYSTEM  G54                     // $GCO 1=G54, 2=G55, 3=G56, 4=G57, 5=G58 or 6=G59
#define GCODE_DEFAULT_PATH_CONTROL  PATH_CONTINUOUS			// $gpa 0=G61=exact path, 1=G61.1=exact stop, 2=G64continous 
#define GCODE_DEFAULT_DISTANCE_MODE ABSOLUTE_MODE			// $gdi 0=G90=ABSOLUTE_MODE 1=G91=INCREMENTAL_MODE

// *** motor settings ************************************************************************************

#define MOTOR_POWER_MODE            MOTOR_POWERED_IN_CYCLE  // default motor power mode (see cmMotorPowerMode in stepper.h)=
															// 0=MOTOR_DISABLED 1=MOTOR_ALWAYS_POWERED 
															// 2=MOTOR_POWERED_IN_CYCLE 3= MOTOR_POWERED_ONLY_WHEN_MOVING
#define MOTOR_POWER_TIMEOUT         10.00                   // $mt motor idle timeout in seconds, switch power off on motors
#define MOTOR_POWER_LEVEL_XY        0.375                   // default motor power level 0.00 - 1.00 (ARM only)
#define MOTOR_POWER_LEVEL_Z         0.750
#define MOTOR_POWER_LEVEL_ABC       0.000

#define M1_MOTOR_MAP                AXIS_X				    // $1ma
#define M1_STEP_ANGLE               1.8					    // $1sa
#define M1_TRAVEL_PER_REV           50                      // $1tr  
#define M1_MICROSTEPS               16                       // $1mi  1,2,4,8,16,32
#define M1_POLARITY                 0                       // $1po  0=normal, 1=reversed
#define M1_POWER_MODE               MOTOR_POWER_MODE        // $1pm  TRUE=low power idle enabled
#define M1_POWER_LEVEL              MOTOR_POWER_LEVEL_XY

#define M2_MOTOR_MAP                AXIS_Y
#define M2_STEP_ANGLE               1.8
#define M2_TRAVEL_PER_REV           50
#define M2_MICROSTEPS               16
#define M2_POLARITY                 0
#define M2_POWER_MODE               MOTOR_POWER_MODE
#define M2_POWER_LEVEL              MOTOR_POWER_LEVEL_XY

#define M3_MOTOR_MAP                AXIS_Y
#define M3_STEP_ANGLE               1.8
#define M3_TRAVEL_PER_REV           50
#define M3_MICROSTEPS               16
#define M3_POLARITY                 1
#define M3_POWER_MODE               MOTOR_POWER_MODE
#define M3_POWER_LEVEL              MOTOR_POWER_LEVEL_Z

#define M4_MOTOR_MAP                AXIS_Z
#define M4_STEP_ANGLE               1.8
#define M4_TRAVEL_PER_REV           1.25
#define M4_MICROSTEPS               16
#define M4_POLARITY                 0
#define M4_POWER_MODE               MOTOR_POWER_MODE
#define M4_POWER_LEVEL              MOTOR_POWER_LEVEL_ABC

#define M5_MOTOR_MAP                AXIS_B
#define M5_STEP_ANGLE               1.8
#define M5_TRAVEL_PER_REV           360
#define M5_MICROSTEPS               16
#define M5_POLARITY                 0
#define M5_POWER_MODE               MOTOR_POWER_MODE
#define M5_POWER_LEVEL              MOTOR_POWER_LEVEL_ABC

#define M6_MOTOR_MAP                AXIS_C
#define M6_STEP_ANGLE               1.8
#define M6_TRAVEL_PER_REV           360
#define M6_MICROSTEPS               16
#define M6_POLARITY                 0
#define M6_POWER_MODE               MOTOR_POWER_MODE
#define M6_POWER_LEVEL              MOTOR_POWER_LEVEL_ABC

// *** axis settings **********************************************************************************
// See JUNCTION_ACCELERATION 

#define JUNCTION_DEVIATION_XY       0.1                     // larger is faster
#define JUNCTION_DEVIATION_Z        0.01                    // larger is faster
#define JUNCTION_DEVIATION_ABC      0.5                     // larger is faster

#define X_AXIS_MODE                 AXIS_STANDARD           // xam  see canonical_machine.h cmAxisMode for valid values
#define X_VELOCITY_MAX              10000                     // xvm  G0 max velocity in mm/min
#define X_FEEDRATE_MAX              X_VELOCITY_MAX          // xfr  G1 max feed rate in mm/min
#define X_TRAVEL_MIN                0                       // xtn  minimum travel for soft limits
#define X_TRAVEL_MAX                285                     // xtm  travel between switches or crashes
#define X_JERK_MAX                  3500                     // xjm  yes, that's "5 billion" mm/(min^3)
#define X_JERK_HIGH_SPEED           7500                    // xjh
#define X_JUNCTION_DEVIATION        JUNCTION_DEVIATION_XY   // xjd
#define X_HOMING_INPUT              1                       // xhi  input used for homing or 0 to disable
#define X_HOMING_DIR                0                       // xhd  0=search moves negative, 1= search moves positive
#define X_SEARCH_VELOCITY           (X_VELOCITY_MAX * 0.1)  // xsv  Homing speed during search phase (drive to switch)
#define X_LATCH_VELOCITY            50                     // xlv  mm/min in backoff switch during latch phase (drive off switch)
#define X_LATCH_BACKOFF             2                       // xlb  mm Max distance to back off switch during latch phase
#define X_ZERO_BACKOFF              1                       // xzb  mm Distance to back off switch before setting axis zero position

#define Y_AXIS_MODE                 AXIS_STANDARD
#define Y_VELOCITY_MAX              10000
#define Y_FEEDRATE_MAX              Y_VELOCITY_MAX
#define Y_TRAVEL_MIN                0
#define Y_TRAVEL_MAX                290
#define Y_JERK_MAX                  3500
#define Y_JERK_HIGH_SPEED           7500
#define Y_JUNCTION_DEVIATION        JUNCTION_DEVIATION_XY
#define Y_HOMING_INPUT              3
#define Y_HOMING_DIR                0
#define Y_SEARCH_VELOCITY           (Y_VELOCITY_MAX * 0.1)
#define Y_LATCH_VELOCITY            50
#define Y_LATCH_BACKOFF             2
#define Y_ZERO_BACKOFF              1

#define Z_AXIS_MODE                 AXIS_STANDARD
#define Z_VELOCITY_MAX              400
#define Z_FEEDRATE_MAX              Z_VELOCITY_MAX
#define Z_TRAVEL_MAX                0
#define Z_TRAVEL_MIN                -100
#define Z_JERK_MAX                  250                 // was 100
#define Z_JERK_HIGH_SPEED           500
#define Z_JUNCTION_DEVIATION        JUNCTION_DEVIATION_Z
#define Z_HOMING_INPUT              6
#define Z_HOMING_DIR                1
#define Z_SEARCH_VELOCITY           (Z_VELOCITY_MAX * 0.2)
#define Z_LATCH_VELOCITY            50
#define Z_LATCH_BACKOFF             2
#define Z_ZERO_BACKOFF              1

#define A_AXIS_MODE                 AXIS_STANDARD
#define A_VELOCITY_MAX              36000				//sets A to 100 revolutions per minute (360 * 100)
#define A_FEEDRATE_MAX              48000
#define A_TRAVEL_MIN                -1					// degrees
#define A_TRAVEL_MAX                -1					// same value means infinite, no limit
#define A_JERK_MAX                  24000				// yes, 24 billion
#define A_JERK_HIGH_SPEED           A_JERK_MAX
#define A_JUNCTION_DEVIATION        JUNCTION_DEVIATION_ABC
#define A_RADIUS                    1.0					// $aRA
#define A_HOMING_INPUT              0					
#define A_HOMING_DIR                0
#define A_SEARCH_VELOCITY           6000
#define A_LATCH_VELOCITY            1000
#define A_LATCH_BACKOFF             5
#define A_ZERO_BACKOFF              2

#define B_AXIS_MODE                 AXIS_DISABLED
#define B_VELOCITY_MAX              3600
#define B_FEEDRATE_MAX              B_VELOCITY_MAX
#define B_TRAVEL_MAX                -1
#define B_TRAVEL_MIN                -1
#define B_JERK_MAX                  20
#define B_JERK_HIGH_SPEED           B_JERK_MAX
#define B_JUNCTION_DEVIATION        JUNCTION_DEVIATION_ABC
#define B_RADIUS                    1
#define B_HOMING_INPUT              0
#define B_HOMING_DIR                0
#define B_SEARCH_VELOCITY           6000
#define B_LATCH_VELOCITY            1000
#define B_LATCH_BACKOFF             5
#define B_ZERO_BACKOFF              2

#define C_AXIS_MODE                 AXIS_DISABLED
#define C_VELOCITY_MAX              3600
#define C_FEEDRATE_MAX              C_VELOCITY_MAX
#define C_TRAVEL_MAX                -1
#define C_TRAVEL_MIN                -1
#define C_JERK_MAX                  20
#define C_JERK_HIGH_SPEED           C_JERK_MAX
#define C_JUNCTION_DEVIATION        JUNCTION_DEVIATION_ABC
#define C_RADIUS                    1
#define C_HOMING_INPUT              0
#define C_HOMING_DIR                0
#define C_SEARCH_VELOCITY           6000
#define C_LATCH_VELOCITY            1000
#define C_LATCH_BACKOFF             5
#define C_ZERO_BACKOFF              2

//*** Input / output settings ***
/*
    IO_MODE_DISABLED
    IO_ACTIVE_LOW    aka NORMALLY_OPEN
    IO_ACTIVE_HIGH   aka NORMALLY_CLOSED

    INPUT_ACTION_NONE
    INPUT_ACTION_STOP
    INPUT_ACTION_FAST_STOP
    INPUT_ACTION_HALT
    INPUT_ACTION_RESET

    INPUT_FUNCTION_NONE
    INPUT_FUNCTION_LIMIT
    INPUT_FUNCTION_INTERLOCK
    INPUT_FUNCTION_SHUTDOWN
    INPUT_FUNCTION_PANIC
*/
// See config pins for limits : https://github.com/synthetos/g2/wiki/Homing-g2#configuring-digital-inputs-for-homing
// See config axis for homing; https://github.com/synthetos/g2/wiki/Homing-g2#configuring-axes-for-homing
// See homing G2 : https://github.com/synthetos/g2/wiki/Homing-g2

// Xmin = D14, cablée sur fin de course
#define DI1_MODE                    IO_ACTIVE_LOW
#define DI1_ACTION                  INPUT_ACTION_STOP
#define DI1_FUNCTION                INPUT_FUNCTION_LIMIT

// Xmax = D15, non cablee
#define DI2_MODE                    IO_ACTIVE_HIGH
#define DI2_ACTION                  INPUT_ACTION_NONE
#define DI2_FUNCTION                INPUT_FUNCTION_NONE

// Ymin = D16, cablée sur fin de course
#define DI3_MODE                    IO_ACTIVE_LOW
#define DI3_ACTION                  INPUT_ACTION_STOP
#define DI3_FUNCTION                INPUT_FUNCTION_LIMIT

// Ymax = D17, non cablee
#define DI4_MODE                    IO_ACTIVE_HIGH
#define DI4_ACTION                  INPUT_ACTION_NONE
#define DI4_FUNCTION                INPUT_FUNCTION_NONE

// Zmin = D18						// Z probe, cablée sur detecteur lng outil
// G38.2 Z-30.00 F30; descend de 30mm pour recherche le probe, à 30mm/min
// G92 Z19.90 ; puis fait l'origine du Z : Zplate = 19.90
#define DI5_MODE                    IO_ACTIVE_LOW   
#define DI5_ACTION                  INPUT_ACTION_NONE
#define DI5_FUNCTION                INPUT_FUNCTION_NONE

// Zmax = D19, cablee sur fin de course
#define DI6_MODE                    IO_ACTIVE_LOW
#define DI6_ACTION                  INPUT_ACTION_STOP
#define DI6_FUNCTION                INPUT_FUNCTION_LIMIT

// Amin = D58
//#define DI7_MODE                    IO_MODE_DISABLED
//#define DI7_ACTION                  INPUT_ACTION_NONE
//#define DI7_FUNCTION                INPUT_FUNCTION_NONE

// Amin  = D58                      // External ESTOP
#define DI7_MODE                    IO_ACTIVE_HIGH
#define DI7_ACTION                  INPUT_ACTION_HALT
#define DI7_FUNCTION                INPUT_FUNCTION_SHUTDOWN

// Amax = D59
#define DI8_MODE                    IO_MODE_DISABLED
#define DI8_ACTION                  INPUT_ACTION_NONE
#define DI8_FUNCTION                INPUT_FUNCTION_NONE

// Hardware interlock input = D60
//#define DI9_MODE                    IO_MODE_DISABLED
//#define DI9_ACTION                  INPUT_ACTION_NONE
//#define DI9_FUNCTION                INPUT_FUNCTION_NONE

// Hardware interlock input = D60
#define DI9_MODE                    IO_ACTIVE_HIGH
#define DI9_ACTION                  INPUT_ACTION_NONE
#define DI9_FUNCTION                INPUT_FUNCTION_INTERLOCK // (hold is performed by Interlock function)

/*** Handle optional modules that may not be in every machine ***/
/*
** P1_PWM_FREQUENCY **
This is the base frequency. You need to pick something that matches what your controller expects. 
For hobby RC controllers which respond anywhere between 50 & 400Hz I use 100Hz because it makes the 
pulse width calculations very simple.

** P1_CW_PHASE_LO **
This is an arbitrary number that represents the minimum spindle speed when rotating clockwise. 
i.e.: when you have issued an M03 command. it will be the lowest S-code you can set. It's an arbitrary unit, 
you should enable your spindle to its minimum speed and then measure the spindle with a tachometer. 
Use this value. For hobby RC controllers I like to use 1000 to represent the minimum speed, and 2000 
to represent the maximum speed. Internally, tinyG will insure that PWM mappings are clipped to stay within range.

** P1_CW_SPEED_LO **
This is the actual PWM signal width as a fraction of the frequency (unit scalar). For a hobby 
RC controller, I use 0.125, which gives me a 1250µS pulse width. This corresponds to the minimum start value 
for my ESCs. Typically, the start anywhere from 1100µS to 1350µS, and it all depends on manufacturer.

** P1_CW_PHASE_HI **
Phase high represents the maximum phase width as a unit scalar of the frequency. 1.0 is always on, 
0.0 is always off. For RC ESCs I use 0.2, which gives a 0.01sec * 0.2 = 0.002sec = 2000µS pulse width.

** P1_PWM_PHASE_OFF **
Because there is whats called "deadband" its necessary to have the value that is "spindle off." 
For a PWM controller that expects no pulse, you would set this to 0.0, for an RC ESC you would use 0.1, 
because that would generate a 1000µS pulse width which is the minimum RC PWM control timing pulse width. 
However, on some RC speed controllers, 50% phase, or 1500µS is the off position. This is common on RC car
ESC speed controllers which have reverse…

** P1_CCW_PHASE_LO **
Which is why CCW (or M04) has its own mapping as well. This allows you to use the M03/M04 codes to create 
pulse timings which run both forwards and backwards.

If you want to disable CCW M-codes, you can set the pulse high and low timings to both be the same as P1_PWM_PHASE_OFF.
Hope this helps! --mikest
*/

#define P1_PWM_FREQUENCY            100                     // in Hz
#define P1_CW_SPEED_LO              100                    // in RPM (arbitrary units)
#define P1_CW_SPEED_HI              24000
#define P1_CW_PHASE_LO              0.01                   // phase [0..1]
#define P1_CW_PHASE_HI              1.0
#define P1_CCW_SPEED_LO             0
#define P1_CCW_SPEED_HI             0
#define P1_CCW_PHASE_LO             0.1
#define P1_CCW_PHASE_HI             0.1
#define P1_PWM_PHASE_OFF            0.0

// *** DEFAULT COORDINATE SYSTEM OFFSETS ***

#define G54_X_OFFSET 0	// G54 is often set to all zeros
#define G54_Y_OFFSET 0
#define G54_Z_OFFSET 0
#define G54_A_OFFSET 0
#define G54_B_OFFSET 0
#define G54_C_OFFSET 0

#define G55_X_OFFSET 0	// use (X_TRAVEL_MAX/2) to set g55 to middle of table
#define G55_Y_OFFSET 0  // use (Y_TRAVEL_MAX/2) to set g55 to middle of table
#define G55_Z_OFFSET 0
#define G55_A_OFFSET 0
#define G55_B_OFFSET 0
#define G55_C_OFFSET 0

#define G56_X_OFFSET 0
#define G56_Y_OFFSET 0
#define G56_Z_OFFSET 0
#define G56_A_OFFSET 0
#define G56_B_OFFSET 0
#define G56_C_OFFSET 0

#define G57_X_OFFSET 0
#define G57_Y_OFFSET 0
#define G57_Z_OFFSET 0
#define G57_A_OFFSET 0
#define G57_B_OFFSET 0
#define G57_C_OFFSET 0

#define G58_X_OFFSET 0
#define G58_Y_OFFSET 0
#define G58_Z_OFFSET 0
#define G58_A_OFFSET 0
#define G58_B_OFFSET 0
#define G58_C_OFFSET 0

#define G59_X_OFFSET 0
#define G59_Y_OFFSET 0
#define G59_Z_OFFSET 0
#define G59_A_OFFSET 0
#define G59_B_OFFSET 0
#define G59_C_OFFSET 0

/*** User-Defined Data Defaults ***/

#define USER_DATA_A0 0
#define USER_DATA_A1 0
#define USER_DATA_A2 0
#define USER_DATA_A3 0
#define USER_DATA_B0 0
#define USER_DATA_B1 0
#define USER_DATA_B2 0
#define USER_DATA_B3 0
#define USER_DATA_C0 0
#define USER_DATA_C1 0
#define USER_DATA_C2 0
#define USER_DATA_C3 0
#define USER_DATA_D0 0
#define USER_DATA_D1 0
#define USER_DATA_D2 0
#define USER_DATA_D3 0

