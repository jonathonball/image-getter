#ifndef CURL_WRAPPER_HEADER
#define CURL_WRAPPER_HEADER
#include "environment.h"

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

void get_image() {
    FILE *fp;
    CURL *curl_handle;
    char *pagefilename = get_environment_value("TMP_FILE");
    FILE *pagefile;
    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, get_environment_value("USER_AGENT"));
    curl_easy_setopt(curl_handle, CURLOPT_URL, get_environment_value("REMOTE_URL"));
    curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
    pagefile = fopen(pagefilename, "wb");
    if(pagefile) {
      curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, pagefile);
      curl_easy_perform(curl_handle);
      fclose(pagefile);
    }
    curl_easy_cleanup(curl_handle);
}
#endif
