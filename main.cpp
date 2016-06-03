// This #include statement was automatically added by the Particle IDE.
#include "common.h"

// telnet defaults to port 23
TCPServer server = TCPServer(23);
TCPClient client;
bool readCommand = false;

void setup()
{
  // start listening for clients
  server.begin();

  // Make sure your Serial Terminal app is closed before powering your device
  Serial.begin(9600);
}

void loop() {
  if (client.connected()) {
    char readChar = client.read();

    if (readChar == SYNC_CHAR) {
        readCommand = true;
    }
    else {
    if (readCommand) {
        APIEnum api = (APIEnum) readChar;
        String input = client.readStringUntil(SYNC_CHAR);

        switch (api) {
            case SERIAL_BEGIN:
                Serial.print("Received input for api SERIAL_BEGIN: ");
                Serial.begin(input.toInt());
                break;

            case SERIAL_END:
                Serial.print("Received input for api SERIAL_END: ");
                Serial.end();
                break;

            case SERIAL_WRITE:
                Serial.print("Received input for api SERIAL_WRITE: ");
                Serial.print(input);
                break;

            case SERIAL_WRITELN:
                Serial.print("Received input for api SERIAL_WRITELN: ");
                Serial.println(input);
                break;

            default:
                Serial.print("Received input for unknown api: ");
                break;

        }
        readCommand = false;
    }
    }

  }
  else {
    // if no client is yet connected, check for a new connection
    client = server.available();
  }
}
