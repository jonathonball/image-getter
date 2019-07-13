#ifndef DAEMONIZE_HEADER
#define DAEMONIZE_HEADER

void daemonize() {
    pid_t pid, sid;
    pid = fork();
    if (pid < 0) {
        speak("Unable to fork process");
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        speak("Forked into daemon process");
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0) {
        speak("Unable to create session");
        exit(EXIT_FAILURE);
    }

    char *work_dir = get_environment_value("WORK_DIR");
    if ((chdir(work_dir)) < 0) {
        speak("Cannot change to working directory");
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    return;
}

#endif
