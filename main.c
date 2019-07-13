/**
 * image-getter
 * Inspirations:
 * - http://www.netzmafia.de/skripten/unix/linux-daemon-howto.html
 * - https://curl.haxx.se/libcurl/c/url2file.html
 */
#define NUM_ENV_KEYS 8
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
#include "speak.h"
#include "environment.h"
#include "daemonize.h"
#include "curl.h"

int main(int argc, char **argv, char **environ) {
    speak("Attempting initialization");
    gather_environment_details();
    validate_environment_details();
    discuss_environment();
    daemonize();
    int interval = atoi(get_environment_value("TIMEOUT"));
    while (1) {
        get_image();
        sleep(interval);
    }
    speak("Reached graceful shutdown");
    exit(EXIT_SUCCESS);
}


// Probable trash
//#include <sys/types.h>
//#include <stdio.h>
//#include <fcntl.h>
//#include <errno.h>
//#include <syslog.h>
//#include <string.h>
//#include <regex.h>
