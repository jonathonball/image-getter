#ifndef ENVIRONMENT_HEADER
#define ENVIRONMENT_HEADER

struct environment_detail {
    char *key;
    char *value;
    char *type;
    int valid;
} environment_details[NUM_ENV_KEYS] = {
    { "LOG_FILE", "/tmp/image-getter.log", "file", 1 },
    { "DUMP_DIR", "/tmp", "directory", 1 },
    { "WORK_DIR", "/tmp", "directory", 1 },
    { "SINGLE_FILE_MODE", "true", "boolean", 1 },
    { "TMP_FILE", "/tmp/image-getter.jpg", "file", 1 },
    { "USER_AGENT", "image-getter", "string", 1 },
    { "REMOTE_URL", NULL, "url", 0 },
    { "TIMEOUT", "60", "int", 1 }
};

char* get_environment_value(char *key) {
    for (int i = 0; i < NUM_ENV_KEYS; i++) {
        if (environment_details[i].key == key) {
            return environment_details[i].value;
        }
    }
    return NULL;
}

int validate_dir_path(char *maybe_path) {
    // IMPLEMENT ME, PLEASE I'M BEGGING YOU
    return 1;
}

int interpret_boolean_str(char *boolean) {
    if (boolean == "true") {
        return 1;
    }
    if (boolean == "false") {
       return 0;
    }
    return -1;
}

int validate_boolean(char *maybe_boolean) {
    if (interpret_boolean_str(maybe_boolean) == -1) {
        return 0;
    }
    return 1;
}

int validate_url(char *url) {
    // ADD ACTUAL VALIDATION HERE
    if (url == NULL) {
        return 0;
    }
    return 1;
}

void validate_environment_detail(int index) {
    if (environment_details[index].type == "directory") {
        if (! validate_dir_path(environment_details[index].value)) {
            speak("Encountered invalid file path");
            environment_details[index].valid = 0;
        } else {
            environment_details[index].valid = 1;
        }
    }
    if (environment_details[index].type == "boolean") {
        if (! validate_boolean(environment_details[index].value)) {
            speak("Boolean value must be the strings 'true' or 'false'");
            environment_details[index].valid = 0;
        } else {
            environment_details[index].valid = 1;
        }
    }
    if (environment_details[index].type == "url") {
        if (! validate_url(environment_details[index].value)) {
            speak("Encountered invalid URL");
            environment_details[index].valid = 0;
        } else {
            environment_details[index].valid = 1;
        }
    }
    if (! environment_details[index].valid) {
        speak(environment_details[index].key);
    }
    return;
}

void validate_environment_details() {
    int validation_status = 1;
    for (int i = 0; i < NUM_ENV_KEYS; i++) {
        validate_environment_detail(i);
    }
    for (int i = 0; i < NUM_ENV_KEYS; i++) {
        if (! environment_details[i].valid) {
            speak("Unable to validate environment");
            exit(EXIT_FAILURE);
        }
    }
    return;
}

void gather_environment_details() {
    char *value_from_environment;
    for (int i = 0; i < NUM_ENV_KEYS; i++) {
        value_from_environment = getenv(environment_details[i].key);
        if (value_from_environment != NULL) {
            environment_details[i].value = value_from_environment;
        }
    }
    return;
}

void discuss_environment() {
  speak("The following ENV details were found:");
  for (int i = 0; i < NUM_ENV_KEYS; i++) {
      printf("\t%s: %s\n", environment_details[i].key, environment_details[i].value);
  }
}

#endif