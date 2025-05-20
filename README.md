# Smart-Home-Automation-System

### Project Overview 📖
This project implements an intelligent home automation system on an ATmega32 microcontroller. It monitors environmental conditions using sensors (LM35 temperature, LDR light, and flame detector) and automatically controls lighting, fan speed, and safety alerts. A 16×2 LCD displays real-time status, and an H-bridge circuit drives a PWM-controlled fan motor.  

### Objective 🎯
- Automate lighting based on ambient light intensity using LDR readings.  
- Adjust fan speed automatically via PWM-driven motor control in response to temperature changes (LM35 sensor).  
- Detect fire incidents with a flame sensor and trigger alarm/buzzer plus LCD alerts.  
- Provide clear, on‑screen feedback through an LCD (temperature, light intensity, fan status, and alerts).  
- Modularize drivers for ADC, GPIO, PWM, LCD, sensors, LEDs, motor, flame detection, and buzzer.  

### Features 🚀
1. **Automatic Lighting Control**: Three LEDs (Red, Green, Blue) indicate light intensity:  
   - < 15%: All LEDs ON  
   - 16–50%: Red & Green ON  
   - 51–70%: Red ON  
   - \> 70%: All LEDs OFF  
2. **Automatic Fan Speed Control**:  
   - ≥ 40 °C: 100% PWM duty cycle  
   - 35–< 40 °C: 75% duty cycle  
   - 30–< 35 °C: 50% duty cycle  
   - 25–< 30 °C: 25% duty cycle  
   - < 25 °C: Fan OFF  
3. **Fire Detection & Alert**:  
   - Flame sensor triggers audible buzzer and displays "Critical alert!" on LCD  
   - System remains in alert state until flame cleared  
4. **LCD Display**:  
   - Row 1: `FAN is ON` or `FAN is OFF`  
   - Row 2: `Temp= xxC  LDR= yy%`  

### Hardware Components 🛠️
- **Microcontroller**: ATmega32 @ 16 MHz  
- **Sensors**:  
  - LM35 temperature sensor (ADC1 / PA1)  
  - LDR light sensor (ADC0 / PA0)  
  - Flame sensor (PD2)  
- **Display**: 16×2 LCD in 8‑bit mode (PD0→RS, PD1→E, PORTC→Data)  
- **Motor Control**: H-Bridge (IN1: PB0, IN2: PB1, EN: OC0/PB3)  
- **Status LEDs**: Red (PB5), Green (PB6), Blue (PB7)  
- **Buzzer**: PD3  

### Operation Flow 🔄
1. **Initialization**: Configure ADC, GPIO, PWM (Timer0), LCD, sensors, LEDs, motor, flame sensor, and buzzer drivers.  
2. **Sensor Readings** (periodic):  
   - Read LDR → calculate intensity (%)  
   - Read LM35 → convert ADC value to °C  
3. **Control Logic**:  
   - **Lighting**: Update LED pattern based on LDR thresholds  
   - **Fan Speed**: Set PWM duty cycle via `PWM_Timer0_Start(duty)` according to temperature ranges  
   - **Fire Alert**: If flame detected → `Buzzer_on()`, display "Critical alert!", halt normal control until clear  
4. **Display Update**: Refresh LCD with fan status and sensor values  

### Drivers & API 📚
- **ADC Driver**:
  ```c
  void ADC_init(void);
  uint16 ADC_readChannel(uint8 channel);

- **GPIO Driver**: Configure pin directions and levels
  
- **PWM Driver (Timer0):**
  ```c
  void PWM_Timer0_Start(uint8 duty_cycle);

- **LCD Driver:** 8‑bit interface (RS, E, Data)
  
- **LDR Driver:**
  ```c
  uint16 LDR_getLightIntensity(void);

- **LM35 Driver:** Course‑provided ADC-based temperature reading
  
- **LED Driver:**:
  ```c
  void LEDS_init(void);
  void LED_on(LED_ID id);
  void LED_off(LED_ID id);

- **DC Motor Driver:**
  ```c
  void DcMotor_Init(void);
  void DcMotor_Rotate(DcMotor_State state, uint8 speed);

- **Flame Sensor:**
  ```c
  void FlameSensor_init(void);
  uint8 FlameSensor_getValue(void);

- **Buzzer Driver:**
  ```c
  void Buzzer_init(void);
  void Buzzer_on(void);
  void Buzzer_off(void);  

### Simulation on Proteus 🖥️
![image](https://github.com/user-attachments/assets/073098cd-e6ce-43a7-a3ae-a10c607f08b7)
