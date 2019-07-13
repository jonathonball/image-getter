# image-getter
Super light-weight image downloader.

# Environment

## Defaults
The following ENV values have defaults but can be overridden:
  - `LOG_FILE`: `/tmp/image-getter.log` Where to store the log file
  - `WORK_DIR`: `/tmp` Path to execute in
  - `TMP_FILE`: `/tmp/image-getter.jpg` Place to store most recent download
  - `USER_AGENT`:`image-getter` How the app identifies itself to a remote host

## Required
The following ENV values do not have defaults and must be set in the environment.
  - `REMOTE_URL` Image source URL

# Compile
Steps to compile.

        apt update
        apt install libcurl4-dev libcurl4-openssl-dev
        cd /path/to/this/directory
        gcc -o image-getter main.c -l curl
