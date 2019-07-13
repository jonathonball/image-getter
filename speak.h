#ifndef SPEAK_HEADER
#define SPEAK_HEADER

const char *APP_NAME = "[image-getter]";

void speak(char* message) {
    printf("%s %s\n", APP_NAME, message);
}

void logger(char* message) {
  // fp = fopen("/tmp/image-getter.log", "a");
  // fseek(fp, 0, SEEK_END);
  // printf("Some string!!\n");
  // fprintf(fp, "Tacos\n");
  // fclose(fp);
}

#endif