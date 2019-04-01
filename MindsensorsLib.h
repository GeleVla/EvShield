/*
 * EVShield interface library for MindSensors Sensors
*/

#ifndef MINDSENSORSLIB_H
#define MINDSENSORSLIB_H

#include "EVShield.h"

//Angle Sensor
#define AS_Command 0x41
#define ANGLE 0x42
#define RAW_READING 0x46

//Distnx
#define DISTNx_Command 0x41
#define DISTNx_Distance 0x42
#define DISTNx_Voltage 0x44
#define DISTNx_SensorType 0x50

//IRThermometer
#define IRThermometer_Command 0x41
#define IRThermometer_Ambient_Temperature_C 0x42
#define IRThermometer_Target_Temperature_C 0x44
#define IRThermometer_Ambient_Temperature_F 0x46
#define IRThermometer_Target_Temperature_F 0x48

//LightSensorArray
#define LightSensorArray_Calibrated 0x42
#define LightSensorArray_Uncalibrated 0x6A
#define LightSensorArray_White_Limit 0x4A
#define LightSensorArray_Black_Limit 0x52
#define LightSensorArray_White_Calibration 0x5A
#define LightSensorArray_Black_Calibration 0x62
#define LightSensorArray_Command 0x41

//LineLeader
#define LineLeader_Raw_Calibrated 0x49
#define LineLeader_Raw_Uncalibrated 0x74
#define LineLeader_White_Limit 0x51
#define LineLeader_Black_Limit 0x59
#define LineLeader_White_Calibration 0x64
#define LineLeader_Black_Calibration 0x6C

#define LineLeader_Command 0x41
#define LineLeader_Steering 0x42
#define LineLeader_Average 0x43
#define LineLeader_Result 0x44
#define LineLeader_SetPoint 0x45
#define LineLeader_Kp 0x46
#define LineLeader_Ki 0x47
#define LineLeader_Kd 0x48
#define LineLeader_Kp_Factor 0x61
#define LineLeader_Ki_Factor 0x62
#define LineLeader_Kd_Factor 0x63

//MagicWand
#define MagicWand_WR_Register 0x00

//PFMate
#define PF_Commmand 0x41
#define PF_Channel 0x42
#define PF_Channel_1 1
#define PF_Channel_2 2
#define PF_Channel_3 3
#define PF_Channel_4 4

#define PF_Control 0x43
#define PF_Control_Both 0
#define PF_Control_A 1
#define PF_Control_B 2

#define PF_Speed_A 0x45
#define PF_Speed_B 0x47
#define PF_Speed_Slow 1
#define PF_Speed_Medium 4
#define PF_Speed_Full 7

#define PF_Operation_A 0x44
#define PF_Operation_B 0x46
#define PF_Operation_Float 0
#define PF_Operation_Forward 1
#define PF_Operation_Reverse 2
#define PF_Operation_Brake 3

//PSPNx
#define PSPNx_Command 0x41
#define PSPNx_ButtonSet1 0x42
#define PSPNx_ButtonSet2 0x43
#define PSPNx_XLeftJoystick 0x44
#define PSPNx_YLeftJoystick 0x45
#define PSPNx_XRightJoystick 0x46
#define PSPNx_YRightJoystick 0x47

#define BS2_Button_L2 0
#define BS2_Button_R2 1
#define BS2_Button_L1 2
#define BS2_Button_R1 3
#define BS2_Button_Triangle 4
#define BS2_Button_Circle 5
#define BS2_Button_Cross 6
#define BS2_Button_Square 7

#define BS1_Button_Select 0
#define BS1_Button_L3 1
#define BS1_Button_R3 2
#define BS1_Button_Start 3
#define BS1_Button_Up 4
#define BS1_Button_Right 5
#define BS1_Button_Down 6
#define BS1_Button_Left 7

// Color Registers for PiLight.
#define PILIGHT_RED 0x42
#define PILIGHT_GREEN 0x43
#define PILIGHT_BLUE 0x44

//RTC
#define RTC_Seconds 0x00
#define RTC_Minutes 0x01
#define RTC_Hours 0x02
#define RTC_Day_of_Week 0x03
#define RTC_Day_of_Month 0x04
#define RTC_Month 0x05
#define RTC_Year 0x06

/**
 This class interfaces with mindsensors Angle sensor attached to EVShield
 */
class AngleSensor : public EVShieldI2C
{
  public:
    /** Constructor for the class; may supply an optional custom i2c address 	*/
    AngleSensor(uint8_t i2c_address = 0x30);

    /** Write a command byte at the command register of the device */
    uint8_t issueCommand(char command);

    /** Get the angle position  
	 *  @return angle value*/
    long getAngle();

    /** Get the raw reading from the device (twice the angle value) 
	 *  @return raw reading*/
    long getRawReading();

    /** Reset the angle value to zero.
	 */
    void reset();
};

/**
  This class interfaces with DIST-Nx attached to EVShield 
	*/
class DISTNx : public EVShieldI2C
{
  public:
    /** device constructor for DISTNx; custom i2c address is an optional parameter */
    ISTNx(uint8_t i2c_address = 0x02);

    /** issue a byte command to the command register of the device */
    uint8_t issueCommand(char command);

    /** power on the device module */
    bool energize();

    /** power off the device module */
    bool deEnergize();

    /** get the distance of from the DISTNx in millimeters */
    int getDist();

    /** get the output voltage of the sensor */
    int getVolt();

    /** get the Sharp IR module type */
    short getType();
};

/**
  This class interfaces with IRThermometer attached to EVShield 
	*/
class IRThermometer : public EVShieldI2C
{
  public:
    /** device constructor for IRThermometer; custom i2c address is an optional parameter */
    IRThermometer(uint8_t i2c_address = 0x2A);

    /** issue a byte command to the command register of the device */
    uint8_t issueCommand(char command);

    /** get the Ambient Temperature  from the IRThermometer in Celsius*/
    float getAmbientTemperatureC();

    /** get the Target Temperature  from the IRThermometer in Celsius*/
    float getTargetTemperatureC();

    /** get the Ambient Temperature  from the IRThermometer in Fahrenheit*/
    float getAmbientTemperatureF();

    /** get the Target Temperature  from the IRThermometer in Fahrenheit*/
    float getTargetTemperatureF();
};

/**
  This class interfaces with LightSensorArray attached to EVShield 
  */
class LightSensorArray : public EVShieldI2C
{
  public:
    /** Class constructor for LightSensorArray; custom i2c address is an optional parameter */
    LightSensorArray(uint8_t i2c_address = 0x02);

    /** Write a command byte to the command register of the device */
    uint8_t issueCommand(char command);

    /** Calibrate the current input to the device as white */
    bool calibrateWhite();

    /** Calibrate the current input to the device as black */
    bool calibrateBlack();

    /** Turn off the LEDs on the device and put it in the sleep state */
    bool sleep();

    /** Turn on the LEDs and wake up the device */
    bool wakeUp();

    /** Configure Sensor for US region (and regions with 60 Hz electrical frequency). */
    bool configureUS();

    /** Configure sensor for European region (and regions with 50 Hz electrical frequency). */
    bool configureEurope();

    /** Configure sensor for universal frequency (in this mode the sensor adjusts for any frequency, this is also the default mode). */
    bool configureUniversal();

    /** Get the raw readings from the sensor that is calibrated based on black and white calibration values
      @return  array of 8 bytes of the sensors' calibrated values. */
    uint8_t *getCalibrated();

    /** Get the raw uncalibrated sensor values straight from the sensor 
      @return  array of 8 bytes of the sensors' uncalibrated values. */
    uint8_t *getUncalibrated();

    /** Get the limit at which white changes to black */
    uint8_t *getWhiteLimit();

    /** Get the limit at which black changes to white */
    uint8_t *getBlackLimit();

    /** Calibrate White
      @return Current calibration of white */
    uint8_t *getWhiteCalibration();

    /** Calibrate Black
      @return the current calibration of black */
    uint8_t *getBlackCalibration();
};

/**
  This class interfaces with NXTLineLeader sensor attached to EVShield 
  */
class LineLeader : public EVShieldI2C
{
  public:
    /** class constructor for LineLeader; custom i2c address is an optional parameter */
    LineLeader(uint8_t i2c_address = 0x02);

    /** write a command byte to the command register of the device */
    uint8_t issueCommand(char command);

    /** calibrate the current input to the device as white */
    bool calibrateWhite();

    /** calibrate the current input to the device as black */
    bool calibrateBlack();

    /** turn off the LEDs on the device and put it in the sleep state */
    bool sleep();

    /** turn on the LEDs and wake up the device */
    bool wakeUp();

    /** Color inversion (White line on a black background)
  */
    bool invertLineColorToWhite();

    /** Reset Color inversion (black line on a white background, this is also the default).
  */
    bool resetColorInversion();

    /**
Take a snapshot, this command looks at the line under the sensor and stores the width and position of the line in sensor’s memory. Subsequently, sensor will use these characteristics of line to track it. This command inverts the colors if it sees a white line on black background. (PID parameters are not affected).
  */
    bool takeSnapshot();

    /** Configure Sensor for US region (and regions with 60 Hz electrical frequency).
  */
    bool configureUS();

    /** Configure sensor for European region (and regions with 50 Hz electrical frequency)
  */
    bool configureEurope();

    /** Configure sensor for universal frequency (in this mode the sensor adjusts for any frequency, this is also the default mode).
  */
    bool configureUniversal();

    /** returns the current setpoint used by the PID control on the device */
    uint8_t getSetPoint();

    /** set the desired point relative to the 8 sensors for PID control */
    bool setSetPoint(uint8_t spoint);

    /** get the current proportion factor for PID control */
    uint8_t getKp(uint8_t kp);

    /** set the proportion factor for PID control */
    bool setKp(uint8_t kp);

    /** get the current integral factor for PID control */
    uint8_t getKi(uint8_t ki);

    /** set the integral factor for PID control */
    bool setKi(uint8_t ki);

    /** get the current derivative factor for PID control */
    uint8_t getKd(uint8_t kd);

    /** set the derivative factor for PID control */
    bool setKd(uint8_t kd);

    /**
	Get the Kp factor
	@return kp factor
	*/
    uint8_t getKpFactor(uint8_t kpfact);

    /**
	Set the Kp factor
	*/
    bool setKpFactor(uint8_t kpfact);

    /**
	Get the Ki factor
	@return ki factor
	*/
    uint8_t getKiFactor(uint8_t kifact);

    /**
	Set the Ki factor
	*/
    bool setKiFactor(uint8_t kifact);

    /**
	Get the Kd factor
	@return kd factor
	*/
    uint8_t getKdFactor(uint8_t kdfact);

    /**
	Set the Kd factor
	*/
    bool setKdFactor(uint8_t kdfact);

    /** current steering value, add or subtract from the speed of motors on each side */
    int getSteering();

    /** returns a weighted average of the current position of the line in relation to the sensor */
    unsigned char getAverage();

    /** returns a byte of the current result; each bit corresponds to one light sensor */
    unsigned char getResult();

    /**
    get the raw readings from the sensor that is calibrated based on black and white calibration values
    @return  array of 8 bytes of the sensors' calibrated values.
  */
    uint8_t *getRawCalibrated();

    /** get the raw uncalibrated sensor values straight from the sensor 
    @return  array of 8 bytes of the sensors' uncalibrated values.
	*/
    uint8_t *getRawUncalibrated();

    /** get the limit at which white changes to black */
    uint8_t *getWhiteLimit();

    /** get the limit at which black changes to white */
    uint8_t *getBlackLimit();

    /** returns the current calibration of white */
    uint8_t *getWhiteCalibration();

    /** returns the current calibration of black */
    uint8_t *getBlackCalibration();
};

/**
  This class interfaces with Magic Wand attached to EVShield 
	*/
class MagicWand : public EVShieldI2C
{

  public:
    /** class constructor for the MagicWand; the i2c address for this device cannot be changed */
    MagicWand(uint8_t devAddr = 0x70);

    /** light the want; each bit of the byteToWrite represents one LED; 0 is on and 1 is off */
    void lightWand(uint8_t byteToWrite);
};

/**
  This class interfaces with NumericPad attached to EVShield 
	*/
class NumericPad : public EVShieldI2C
{
  public:
    /** class constructor for the NumericPad with an optional custom i2c address parameter */
    NumericPad(uint8_t i2c_address = 0xB4);

    /** Initialize the keypad for communication with host.
    This function also sets up the capacitance values for
    the keypad with appropriate sensitiviy */
    void InitializeKeypad();

    /** Get the key pressed on the keypad. 
    @param waitPeriod   how long to wait for user to press key (seconds).
    @param keyHolder    return value of the key user pressed in that time. 
    @return true        if there was a key pressed in specified time.
    @return false       if no key pressed in the specified time.
  */
    bool GetKeyPress(int waitPeriod /* seconds */, byte &keyHolder);

    /** Get all the keys pressed by the user at the present moment
  function returns:
  integer value of all keys, each bit that is set to 1 represents a key that is pressed.
  the bits are set as per keyMap. Only 12 bits can be 1.
  */
    int GetKeysPressed();
};

/**
  This class interfaces with PFMate attached to EVShield 
	*/
class PFMate : public EVShieldI2C
{
  public:
    /** class constructor for PFMate with optional custom i2c address as a parameter */
    PFMate(uint8_t i2c_address = 0x48);

    /** issue char command byte to the command register of the PFMate */
    uint8_t issueCommand(char command);

    /** send the data to the PF receiver */
    bool sendSignal();

    /** control the PF motors on the channel the receiver is set to, which motors to control, the operation for the motors, and the speed to run them */
    void controlMotor(uint8_t channel, uint8_t control, uint8_t operation, uint8_t speed);

    /** set which channel the PF receiver is on so the PFMate can talk with it */
    bool setChannel(uint8_t channel);

    /** set which motor to control */
    bool setControl(uint8_t control);

    /** set the operation of motor A */
    bool setOperationA(uint8_t operation);

    /** set the operation of motor B */
    bool setOperationB(uint8_t operation);

    /** set the speed of motor A */
    bool setSpeedA(uint8_t speed);

    /** set the speed of motor B */
    bool setSpeedB(uint8_t speed);
};

/**
  This class interfaces with PSP-Nx attached to EVShield 
	*/
class PSPNx : public EVShieldI2C
{
  public:
    /** class constructor for the PSPNx class with an optional custom i2c address parameter */
    PSPNx(uint8_t i2c_address = 0x02);

    /** issue a character command byte to the command register of the PSPNx */
    uint8_t issueCommand(char command);

    /** power on the joystick receiver */
    bool energize();

    /** power off the joystick receiver */
    bool deEnergize();

    /** set the mode of the joystick to digital */
    bool setDigitalMode();

    /** set the mode of the joystick to analog */
    bool setAnalogMode();

    /** get the x-coordinate of the left joystick, 
	@return number between -100 and +100 and zero when the joystick is neutral.
	*/
    int8_t getXLJoy();

    /** get the y-coordinate of the left joystick
	@return number between -100 and +100 and zero when the joystick is neutral.
	*/
    int8_t getYLJoy();

    /** get the x-coordinate of the right joystick
	@return number between -100 and +100 and zero when the joystick is neutral.
	*/
    int8_t getXRJoy();

    /** get the y-coordinate of the right joystick
	@return number between -100 and +100 and zero when the joystick is neutral.
	*/
    int8_t getYRJoy();

    /** get the current button status of button set 1 and button set 2 */
    void getButtons(int8_t *buttons1, int8_t *buttons2);
};

/**
 * \struct color
 Color related data
 */
struct color
{
    byte r; /*!<Color value of red generated by the PiLight */
    byte g; /*!<Color value of green generated by the PiLight */
    byte b; /*!<Color value of blue generated by the PiLight */
};

/**
  This class interfaces with PiLight sensor attached to EVShield 
  */
class PiLight : public EVShieldI2C
{
  public:
    /** constructor for the PiLight; may supply an optional custom i2c address */
    PiLight(uint8_t i2c_address = 0x30);

    /** 
   * Get the read, green, and blue color values from the PiLight
   * @param color structure
   * @return parameter is returned with values */
    void readPiLight(color &currcolor);

    /** 
   * Set a time out time in seconds 
   * @param timeoutValue will turn off PiLight after a specified time if no communication */
    void setTimeout1(uint8_t timeoutValue);

    /** 
   * Set the color of the PiLight 
   * @param red set the value of the red color
   * @param green set the value of the green color
   * @param blue set the value of the blue color
   * @return parameter is returned with values */
    void createPiLight(uint8_t red, uint8_t green, uint8_t blue);
};

/**
  This class interfaces with RTC attached to EVShield 
	*/
class RTC : public EVShieldI2C
{
  public:
    /** class constructor of the RTC with an optional custom i2c address parameter */
    RTC(uint8_t i2c_address = 0xD0);

    /** get the current seconds reading of the clock (0-59) */
    uint8_t getSeconds();

    /** get the current minutes reading of the clock (0-59) */
    uint8_t getMinutes();

    /** get the current hours reading of the clock (1-24) */
    uint8_t getHours();

    /** get the current day of the week reading of the clock (0-7 starting on Sunday) */
    uint8_t getDayWeek();

    /** get the current day reading of the clock (1-31) */
    uint8_t getDayMonth();

    /** get the current month of the year reading of the clock (1-12) */
    uint8_t getMonth();

    /** get the current year reading of the clock */
    uint8_t getYear();

  private:
    uint8_t BCDToInteger(uint8_t b);
};

typedef enum
{
    SE_None = 0,
    SE_Front,
    SE_Left,
    SE_Right
} SE_Zone;

/**
  This class interfaces with EVTSumoEyes sensor attached to EVShield 
	*/
class SumoEyes : public EVShieldAGS
{
  public:
    /** initialize the SumoEyes with a pointer to the EVShield and the bankport it is connected to */
    bool init(EVShield *shield, SH_BankPort bp);

    /** set the analog type of the sensor */
    bool setType(int8_t type);

    /** set the analog mode of the sensor to get readings for long range */
    bool setLongRange();

    /** set the analog mode of the sensor to get readings for short range */
    bool setShortRange();

    /** detect the where the obstacle is */
    SE_Zone detectObstacleZone();

    /** convert the detected zone to a readable string */
    char *OBZoneToString(SE_Zone ob);

  private:
    bool isNear(int reference, int delta, int comet);
};
#endif