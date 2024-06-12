#include <DS1302.h>

// DS1302 RTC pin definitions
#define DS1302_CLK  18   // Clock pin
#define DS1302_DAT  19   // Data pin
#define DS1302_RST  21   // Reset pin

// Initialize DS1302
DS1302 rtc(DS1302_RST, DS1302_DAT, DS1302_CLK);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

  // Initialize RTC module
  rtc.halt(false);  // Ensure the clock is running
  rtc.writeProtect(false);  // Disable write protection

  // Uncomment the following lines to set the time and date if the RTC module is not set
  // rtc.setDOW(SUNDAY);         // Set Day-of-Week to SUNDAY
  // rtc.setTime(12, 0, 0);      // Set the time to 12:00:00 (24hr format)
  // rtc.setDate(1, 1, 2022);    // Set the date to January 1, 2022

  Serial.println("DS1302 RTC initialized");

}

void loop() {
  // put your main code here, to run repeatedly:
 // Read and print the current time and date from the RTC module
  Time currentTime = rtc.getTime();

  // Print time
  Serial.print("Time: ");
  Serial.print(currentTime.hour);
  Serial.print(":");
  if (currentTime.min < 10) {
    Serial.print("0");
  }
  Serial.print(currentTime.min);
  Serial.print(":");
  if (currentTime.sec < 10) {
    Serial.print("0");
  }
  Serial.println(currentTime.sec);

  // Print date
  Serial.print("Date: ");
  Serial.print(currentTime.date);
  Serial.print("/");
  Serial.print(currentTime.mon);
  Serial.print("/");
  Serial.println(currentTime.year);
 // Print Day of the Week
  Serial.print("Day of the Week: ");
  Serial.println(rtc.getDOWStr());

  // Wait 1 second before updating the time
  delay(1000);

}
