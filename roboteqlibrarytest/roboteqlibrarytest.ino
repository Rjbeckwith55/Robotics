#include <RobotEQ.h>
#define CHANNEL_1 1

// Configure Motor Controllers
RobotEQ controller(&Serial);

void setup() {
  Serial.begin(9600);
}

void loop() {
    int voltage;
    int amps;

    if (controller.isConnected()) {
        Serial.println("Connected");
        voltage = controller.queryBatteryVoltage();
        amps = controller.queryBatteryAmps();

        controller.commandMotorPower(CHANNEL_1, 200);
    }
}
