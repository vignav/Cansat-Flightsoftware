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
    // open the file. 
    //logFile = SD.open("logs.txt", FILE_WRITE);
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
    }
}


