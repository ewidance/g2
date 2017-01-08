/*
 * settings_proxxon.h - Proxxon KT150 150mm table
 * This file is part of the g2core project
 *
 * Copyright (c) 2014 - 2016 Alden S. Hart, Jr.
 * Adapted to Proxxon KT 150 by jp.civade@labsud.org
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

#define JUNCTION_INTEGRATION_TIME   1.50		// $ja centripetal acceleration around corners - larger is faster
#define CHORDAL_TOLERANCE           0.01		// $ct chordal tolerance, accuracy for arc drawing (in mm)

#define SOFT_LIMIT_ENABLE           0			// $sl 0=off, 1=on
#define HARD_LIMIT_ENABLE           0			// $lim 0=off, 1=on
#define SAFETY_INTERLOCK_ENABLE     0			// $saf 0=off, 1=on

#define SPINDLE_ENABLE_POLARITY     1                   // $spep 0=active low, 1=active high
#define SPINDLE_DIR_POLARITY        0  	                // $spdp 0=clockwise is low, 1=clockwise is high
#define SPINDLE_PAUSE_ON_HOLD       true		// $spph 0=no 1=pause
#define SPINDLE_DWELL_TIME          1.0			// $spdw Wait for Spindle Dwell before start (in seconds)

#define COOLANT_MIST_POLARITY       1                   // $comp 0=active low, 1=active high
#define COOLANT_FLOOD_POLARITY      1                   // $cofp 0=active low, 1=active high
#define COOLANT_PAUSE_ON_HOLD       false		// $coph 0=no, 1=pause on hold


// Feed rate usage : https://github.com/synthetos/g2/wiki/Feed-Rate-Override
//    Set master override enable to ON {m48e:1} (default = true, aloows to override feed and speed)
//    Set manual feed rate override ON {mfoe:1}
//    Enter / adjust manual feed rate override factor {mfo:N} where 0.05 < N < 2.00
#define MANUAL_FEEDRATE_OVERRIDE_ENABLE     true	// $mfoe 1=enable
#define MANUAL_FEEDRATE_OVERRIDE_PARAMETER  1.00	// $mfo Manual feed override value [0.05 < mfo < 2]

// Communications and reporting settings

#define COMM_MODE                   JSON_MODE           // $EJ one of: 0=TEXT_MODE, 1=JSON_MODE
#define XIO_ENABLE_FLOW_CONTROL     FLOW_CONTROL_XON    // $EX FLOW_CONTROL_OFF, FLOW_CONTROL_XON, FLOW_CONTROL_RTS

#define TEXT_VERBOSITY              TV_VERBOSE          // $TV  one of: 0=TV_SILENT, 1=TV_VERBOSE
#define JSON_VERBOSITY              JV_MESSAGES         // $JV one of: 0=JV_SILENT, 1=JV_FOOTER, 3=JV_CONFIGS, 2=JV_MESSAGES, 4=JV_LINENUM, 5=JV_VERBOSE
#define QUEUE_REPORT_VERBOSITY	    QR_OFF		// $QV one of: 0=QR_OFF, 1=QR_SINGLE, 2=QR_TRIPLE

#define STATUS_REPORT_VERBOSITY     SR_FILTERED         // $SV one of: 0=SR_OFF, 1=SR_FILTERED, 2=SR_VERBOSE
#define STATUS_REPORT_MIN_MS        100                 // milliseconds - enforces a viable minimum
#define STATUS_REPORT_INTERVAL_MS   250                 // $SI milliseconds - set $SV=0 to disable

// Status report can be queried from ?<CR> in multiline text mode
//#define STATUS_REPORT_DEFAULTS "line","posx","posy","posz","posa","bcr","feed","vel","unit","coor","dist","admo","frmo","momo","stat"
#define STATUS_REPORT_DEFAULTS "line","posx","posy","posz","bcr","feed","vel","momo","stat"

// Alternate SRs
//#define STATUS_REPORT_DEFAULTS "line","vel","mpox","mpoy","mpoz","mpoa","coor","ofsa","ofsx","ofsy","ofsz","dist","unit","stat","homz","homy","homx","momo"
//#define STATUS_REPORT_DEFAULTS "_ts1","_cs1","_es1","_xs1","_fe1","line","posx","posy","posz","vel","stat"
//#define STATUS_REPORT_DEFAULTS "line","posx","posy","posz","vel","_cs1","_es1","_xs1","_fe1","_cs2","_es2","_xs2","_fe2"
//#define STATUS_REPORT_DEFAULTS "mpox","mpoy","mpoz","mpoa","ofsx","ofsy","ofsz","ofsa","unit","stat","coor","momo","dist","home","hold","macs","cycs","mots","plan","feed"
//#define STATUS_REPORT_DEFAULTS "line","mpox","mpoy","mpoz","mpoa","ofsx","ofsy","ofsz","ofsa","stat","_cs1","_es1","_fe0","_fe1","_fe2","_fe3"
//#define STATUS_REPORT_DEFAULTS "line","mpox","mpoy","mpoz","stat","_ts2","_ps2","_cs2","_es2","_fe2"
//#define STATUS_REPORT_DEFAULTS "line","mpox","mpoy","mpoz","_cs3","_es3","_fe3","_xs3","_cs2","_es2","_fe2","_xs2","stat"
//#define STATUS_REPORT_DEFAULTS "line","posx","posy","posz","posa","feed","vel","unit","coor","dist","frmo","momo","stat","_cs1","_es1","_xs1","_fe1"

// Complete status for testing JPC with home switches
//#define STATUS_REPORT_DEFAULTS "line","mpox","mpoy","mpoz","mpoa","posx","posy","posz","posa","feed","vel","unit","coor","dist","admo","frmo","momo","stat","homz","homy","homx", "in1", "in2", "in3", "in4", "in5", "in6", "in7", "in8"

// Gcode startup defaults
#define GCODE_DEFAULT_UNITS         MILLIMETERS         // $GUN 0=G20=MILLIMETERS or 1=G21=INCHES
#define GCODE_DEFAULT_PLANE         CANON_PLANE_XY      // $GPL 0=G17=CANON_PLANE_XY, 1=G18=CANON_PLANE_XZ, or 2=G19=CANON_PLANE_YZ
#define GCODE_DEFAULT_COORD_SYSTEM  G54                 // $GCO 1=G54, 2=G55, 3=G56, 4=G57, 5=G58 or 6=G59
#define GCODE_DEFAULT_PATH_CONTROL  PATH_CONTINUOUS	// $gpa 0=G61=exact path, 1=G61.1=exact stop, 2=G64continous 
#define GCODE_DEFAULT_DISTANCE_MODE ABSOLUTE_DISTANCE_MODE	// $gdi 0=G90=ABSOLUTE_MODE 1=G91=INCREMENTAL_MODE

// *** motor settings ************************************************************************************

#define MOTOR_POWER_MODE            MOTOR_POWERED_IN_CYCLE  // default motor power mode (see cmMotorPowerMode in stepper.h)
#define MOTOR_POWER_TIMEOUT         2.00                // $mt motor idle timeout in seconds, switch power off on motors

#define MOTOR_POWER_LEVEL_XY        1.000               // default motor power level 0.00 - 1.00 (ARM only)
#define MOTOR_POWER_LEVEL_Z         1.000		// Not used on all shields. Not used on GTwo
#define MOTOR_POWER_LEVEL_ABC       1.000

#define M1_MOTOR_MAP                AXIS_X		// $1ma
#define M1_STEP_ANGLE               1.8			// $1sa
#define M1_TRAVEL_PER_REV           2.00                // $1tr  
#define M1_MICROSTEPS               8                   // $1mi  1,2,4,8,16,32
#define M1_POLARITY                 1                   // $1po  0=normal, 1=reversed
#define M1_POWER_MODE               MOTOR_POWER_MODE    // $1pm  TRUE=low power idle enabled
#define M1_POWER_LEVEL              MOTOR_POWER_LEVEL_XY

#define M2_MOTOR_MAP                AXIS_Y
#define M2_STEP_ANGLE               1.8
#define M2_TRAVEL_PER_REV           2.00
#define M2_MICROSTEPS               8
#define M2_POLARITY                 0
#define M2_POWER_MODE               MOTOR_POWER_MODE
#define M2_POWER_LEVEL              MOTOR_POWER_LEVEL_XY

#define M3_MOTOR_MAP                AXIS_Z
#define M3_STEP_ANGLE               1.8
#define M3_TRAVEL_PER_REV           2.00
#define M3_MICROSTEPS               8
#define M3_POLARITY                 1
#define M3_POWER_MODE               MOTOR_POWER_MODE
#define M3_POWER_LEVEL              MOTOR_POWER_LEVEL_Z

#define M4_MOTOR_MAP                AXIS_A
#define M4_STEP_ANGLE               1.8
#define M4_TRAVEL_PER_REV           1.25
#define M4_MICROSTEPS               16
#define M4_POLARITY                 0
#define M4_POWER_MODE               MOTOR_POWER_MODE
#define M4_POWER_LEVEL              MOTOR_POWER_LEVEL_ABC

// *** axis settings **********************************************************************************
// See JUNCTION_ACCELERATION 

#define JERK_MAX_XY    		    500
#define JERK_MAX_Z    		    200

#define X_AXIS_MODE                 AXIS_STANDARD           // xam  see canonical_machine.h cmAxisMode for valid values
#define X_VELOCITY_MAX              500                     // xvm  G0 max velocity in mm/min
#define X_FEEDRATE_MAX              X_VELOCITY_MAX          // xfr  G1 max feed rate in mm/min
#define X_TRAVEL_MIN                0                       // xtn  minimum travel for soft limits
#define X_TRAVEL_MAX                140                     // xtm  travel between switches or crashes
#define X_JERK_MAX                  JERK_MAX_XY             // xjm  yes, that's "5 billion" mm/(min^3)
#define X_JERK_HIGH_SPEED           X_JERK_MAX              // xjh
#define X_HOMING_INPUT              1                       // xhi  input used for homing or 0 to disable
#define X_HOMING_DIRECTION          0                       // xhd  0=search moves negative, 1= search moves positive
#define X_SEARCH_VELOCITY           (X_VELOCITY_MAX * 0.5)  // xsv  Homing speed during search phase (drive to switch)
#define X_LATCH_VELOCITY            (X_VELOCITY_MAX * 0.2)                      // xlv  mm/min in backoff switch during latch phase (drive off switch)
#define X_LATCH_BACKOFF             5                       // xlb  mm Max distance to back off switch during latch phase
#define X_ZERO_BACKOFF              2                       // xzb  mm Distance to back off switch before setting axis zero position

#define Y_AXIS_MODE                 AXIS_STANDARD
#define Y_VELOCITY_MAX              500
#define Y_FEEDRATE_MAX              Y_VELOCITY_MAX
#define Y_TRAVEL_MIN                0
#define Y_TRAVEL_MAX                130
#define Y_JERK_MAX                  JERK_MAX_XY
#define Y_JERK_HIGH_SPEED           Y_JERK_MAX
#define Y_HOMING_INPUT              3
#define Y_HOMING_DIRECTION          0
#define Y_SEARCH_VELOCITY           (Y_VELOCITY_MAX * 0.5)
#define Y_LATCH_VELOCITY            (X_VELOCITY_MAX * 0.2)
#define Y_LATCH_BACKOFF             5
#define Y_ZERO_BACKOFF              2

#define Z_AXIS_MODE                 AXIS_STANDARD
#define Z_VELOCITY_MAX              300
#define Z_FEEDRATE_MAX              Z_VELOCITY_MAX
#define Z_TRAVEL_MIN                -100
#define Z_TRAVEL_MAX                0
#define Z_JERK_MAX                  JERK_MAX_Z                 // was 100
#define Z_JERK_HIGH_SPEED           Z_JERK_MAX
#define Z_HOMING_INPUT              6
#define Z_HOMING_DIRECTION          1
#define Z_SEARCH_VELOCITY           (Z_VELOCITY_MAX * 0.5)
#define Z_LATCH_VELOCITY            (Z_VELOCITY_MAX * 0.2)
#define Z_LATCH_BACKOFF             5
#define Z_ZERO_BACKOFF              2
// Rotary values are chosen to make the motor react the same as X for testing
/***************************************************************************************
 * To calculate the speeds here, in Wolfram Alpha-speak:
 *
 *   c=2*pi*r, r=0.609, d=c/360, s=((S*60)/d), S=40 for s
 *   c=2*pi*r, r=5.30516476972984, d=c/360, s=((S*60)/d), S=40 for s
 *
 * Change r to A_RADIUS, and S to the desired speed, in mm/s or mm/s/s/s.
 *
 * It will return s= as the value you want to enter.
 *
 * If the value is over 1 million, the code will divide it by 1 million,
 * so you have to pre-multiply it by 1000000.0. (The value is in millions, btw.)
 *
 * Note that you need these to be floating point values, so always have a .0 at the end!
 *
 ***************************************************************************************/

#define A_AXIS_MODE             AXIS_RADIUS
#define A_RADIUS                5.30516476972984
//#define A_VELOCITY_MAX        25920.0 // ~40 mm/s, 2,400 mm/min
//#define A_FEEDRATE_MAX        25920.0/2.0 // ~20 mm/s, 1,200 mm/min
#define A_VELOCITY_MAX          77760.0 // G0 rate ~120 mm/s, 2,400 mm/min
#define A_FEEDRATE_MAX          9720.0 // 9720.0 = G1 rate ~15 mm/s, 900 mm/min
#define A_TRAVEL_MIN            0
#define A_TRAVEL_MAX            10
#define A_JERK_MAX              648000 // 1,000 million mm/min^3 = 648000
                                       // * a million IF it's over a million
                                       // c=2*pi*r, r=5.30516476972984, d=c/360, s=((1000*60)/d)
#define A_HOMING_INPUT          0
#define A_HOMING_DIRECTION      0
#define A_SEARCH_VELOCITY       2000
#define A_LATCH_VELOCITY        2000
#define A_LATCH_BACKOFF         5
#define A_ZERO_BACKOFF          2
#define A_JERK_HIGH_SPEED       A_JERK_MAX


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

// On the GTwo shield, 0.1uF caps in // with input, and a 10K pullup make inputs active low

// Xmin = D14, cablée sur fin de course
#define DI1_MODE                    IO_ACTIVE_LOW
#define DI1_ACTION                  INPUT_ACTION_NONE
#define DI1_FUNCTION                INPUT_FUNCTION_LIMIT

// Xmax = D15, non cablee
#define DI2_MODE                    IO_ACTIVE_LOW
#define DI2_ACTION                  INPUT_ACTION_NONE
#define DI2_FUNCTION                INPUT_FUNCTION_NONE

// Ymin = D16, cablee sur fin de course
#define DI3_MODE                    IO_ACTIVE_LOW
#define DI3_ACTION                  INPUT_ACTION_NONE
#define DI3_FUNCTION                INPUT_FUNCTION_LIMIT

// Ymax = D17, non cablee
#define DI4_MODE                    IO_ACTIVE_LOW
#define DI4_ACTION                  INPUT_ACTION_NONE
#define DI4_FUNCTION                INPUT_FUNCTION_NONE

// Zmin = D18	 Z probe, cablee sur detecteur lng outil
// G38.2 Z-30.00 F30; descend de 30mm pour recherche le probe, à 30mm/min
// G92 Z19.90 ; puis fait l'origine du Z : Zplate = 19.90
#define DI5_MODE                    IO_ACTIVE_LOW   
#define DI5_ACTION                  INPUT_ACTION_NONE
#define DI5_FUNCTION                INPUT_FUNCTION_NONE

// Zmax = D19, cablee sur fin de course
#define DI6_MODE                    IO_ACTIVE_LOW
#define DI6_ACTION                  INPUT_ACTION_NONE
#define DI6_FUNCTION                INPUT_FUNCTION_LIMIT


// Amin  = D58 reconfigured as External ESTOP
#define DI7_MODE                    IO_ACTIVE_LOW
#define DI7_ACTION                  INPUT_ACTION_HALT
#define DI7_FUNCTION                INPUT_FUNCTION_SHUTDOWN

// Amax = D59 not used
#define DI8_MODE                    IO_MODE_DISABLED
#define DI8_ACTION                  INPUT_ACTION_NONE
#define DI8_FUNCTION                INPUT_FUNCTION_NONE

// Hardware interlock input = D60
#define DI9_MODE                    IO_ACTIVE_LOW
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

#define G54_X_OFFSET 0            // G54 is traditionally set to all zeros
#define G54_Y_OFFSET 0
#define G54_Z_OFFSET 0
#define G54_A_OFFSET 0
#define G54_B_OFFSET 0
#define G54_C_OFFSET 0

#define G55_X_OFFSET (X_TRAVEL_MAX/2)    // set to middle of table
#define G55_Y_OFFSET (Y_TRAVEL_MAX/2)
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
