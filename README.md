# sttptime
Monitor how long you've used certain apps. Inteded to be an app
to monitor 'playtime' for apps that aren't installed on Steam.

## Compiling
Requires a C++ compiler. Then just run `make`

## Usage
***Note: I have not implemented a Service for sttptime, so this will be changed once I do***

***Note 2: sttptime installs a configuration file for apps to track at `C:\Users\%USERNAME%\AppData\sttptime.log`***


1. Run the backend (`bin/sttptime-backend.exe`)
2. Run the frontend (`bin/sttptime.exe`), and configure/add apps.

Now, as you use the game's you've added, sttptime will track it and add it
to the file mentioned earlier.