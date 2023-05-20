#include <SD.h>
#include <SPI.h>

File telemetryFile;
File logFile;

void SDsetup()
{
    if (!SD.begin(BUILTIN_SDCARD)) {
        //failed
        return;
    }
}
void failedWrite (){
    // Runs when writing to Sd card fails
}
void saveTelemetryInSdCard( String telemetryString )
{
    // if the file opened okay, write to it:
    telemetryFile = SD.open("telemetry.csv", FILE_WRITE);
    if (telemetryFile) {
        telemetryFile.println(telemetryString);
        telemetryFile.close();
    } else {
        // Failed to write to file
        failedWrite();
    }
}

void log( String logdata ){
    logFile = SD.open("logs.txt", FILE_WRITE);
    if (logFile) {
        logFile.println(logdata);
        logFile.close();
    } else {
        // Failed to write to file
        failedWrite();
    }
}
