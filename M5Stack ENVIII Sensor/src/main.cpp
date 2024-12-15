/* ###################################################################################
 * # A minimal example to read the sensors of the M5Stack Unit ENV III               #
 * ###################################################################################
 * # See platformio.ini for supported boards and configuration.                      #
 * # Adjust the settings in platformio.ini to match your board and preferences.      #
 * ###################################################################################
 */
#include <Arduino.h>

#include <M5Stack.h>
#include <M5UnitENV.h> 

#include <stdlib.h>


// sensors of the M5Stack Unit ENVIII
SHT3X sht3x; // Temperature and Humidity Sensor SHT30
QMP6988 qmp; // Pressure and Altitude Sensor QMP6988


void setup() {
  // Serial Speed is defined in platformio.ini
  Serial.begin(MONITOR_SPEED);
  
  // I2C Pins are defined in platformio.ini.
  while (!sht3x.begin(&Wire, SHT3X_I2C_ADDR, SDA_PIN, SCL_PIN, I2C_SPEED)) {
    Serial.println(F("Couldn't find SHT3X"));
    delay(1000);
  }

  // I2C Pins are defined in platformio.ini
  while (!qmp.begin(&Wire, QMP6988_SLAVE_ADDRESS_L, SDA_PIN, SCL_PIN, I2C_SPEED)) {
    Serial.println(F("Couldn't find QMP6988"));      
    delay(1000);
  }

}



void loop() {
  Serial.println(F("----------M5Stack Unit ENVIII-------------"));
  Serial.println(F("Reading sensors..."));

  // read temperature and humidity sensor SHT3X
  if (sht3x.update()) {
    Serial.println(F("-----SHT3X (Temperature and Humidity)-----"));
    Serial.print(F("Temperature: "));
    Serial.print(sht3x.cTemp);
    Serial.println(F(" degrees C"));
    Serial.print(F("Humidity: "));
    Serial.print(sht3x.humidity);
    Serial.println(F("% rH"));
    Serial.println(F("------------------------------------------\r\n"));

  }

  // read temperature and pressure sensor QMP6988
  if (qmp.update()) {
    Serial.println(F("-----QMP6988 (Pressure and Altitude)------"));
    Serial.print(F("Temperature: "));
    Serial.print(qmp.cTemp);
    Serial.println(F(" degrees C"));
    Serial.print(F("Pressure: "));
    Serial.print(qmp.pressure);
    Serial.println(F(" Pa"));
    Serial.print(F("            "));
    Serial.print(qmp.pressure / 100);
    Serial.println(F(" hPa"));
    Serial.print(F("Approx altitude: "));
    Serial.print(qmp.altitude);
    Serial.println(F(" m"));
    Serial.println(F("------------------------------------------\r\n"));
  }

  delay(1000);

}
