STM32F4 Debugging with OpenOCD, GDB, and STLINK
This guide will help you set up a debugging environment for STM32F4 microcontrollers using OpenOCD, GDB, and STLINK, integrated with Visual Studio Code.

Prerequisites
STM32F4 Development Board (e.g., STM32F401RETx)
ST-Link v2 Programmer or any compatible STLINK device.
OpenOCD (Open On-Chip Debugger)
GCC ARM Toolchain (for compiling and debugging)
Visual Studio Code (VSCode) with the cortex-debug extension
Step 1: Install Dependencies
Install OpenOCD
Ubuntu/Debian:
bash
Copy
Edit
sudo apt update
sudo apt install openocd
Install GCC ARM Toolchain
Download the ARM GCC toolchain from the official website.

Alternatively, install it via package manager (if available):

bash
Copy
Edit
sudo apt install gcc-arm-none-eabi
Install Visual Studio Code and Extensions
Install Visual Studio Code.
Install the Cortex-Debug extension for STM32 development.
Step 2: OpenOCD Configuration Files
You need the OpenOCD configuration files for the ST-Link and the STM32 target.

ST-Link interface configuration: interface/stlink-v2.cfg
STM32F4 target configuration: target/stm32f4x.cfg
These files should already exist in your OpenOCD installation under the following directories:

/usr/share/openocd/scripts/interface/stlink-v2.cfg
/usr/share/openocd/scripts/target/stm32f4x.cfg
If not, you can download them from the OpenOCD repository or copy them from an existing installation.

Step 3: OpenOCD Commands
To start OpenOCD with your STM32F4 board, run the following command:

bash
Copy
Edit
openocd -f interface/stlink-v2.cfg -f target/stm32f4x.cfg
OpenOCD will start and listen for GDB connections on port 3333.

Step 4: Visual Studio Code Configuration
In Visual Studio Code, you’ll configure two tasks:

Launch Configuration (Run OpenOCD with STLINK)
Attach Configuration (Attach GDB to OpenOCD)
Launch Configuration: Debugging with STLINK
This configuration launches OpenOCD and GDB together, running the program on the STM32F4.

json
Copy
Edit
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debugging STLINK STM32F4",
            "type": "cortex-debug",
            "request": "launch",
            "servertype": "stlink",
            "cwd": "${workspaceFolder}",
            "executable": "./Template_proj.elf",
            "armToolchainPath": "/opt/gcc-arm-none-eabi-10.3-2021.10/bin/",
            "gdbPath": "/opt/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gdb",
            "device": "STM32F401RETx",
            "configFiles": [
                "interface/stlink-v2.cfg",
                "target/stm32f4x.cfg"
            ],
            "svdFile": "${workspaceFolder}/STM32F401.svd",
            "runToEntryPoint": "main",
            "postRestartCommands": [
                "monitor reset halt",
                "load"
            ],
            "preLaunchTask": "Build Project"
        }
    ]
}
Attach Configuration: Debugging with OpenOCD (Already Running)
This configuration attaches GDB to an already running OpenOCD server. Run OpenOCD first, then use this configuration to connect and debug.

json
Copy
Edit
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debugging OpenOCD STM32F4",
            "type": "cortex-debug",
            "request": "attach",
            "servertype": "stlink",
            "target": "localhost:3333",
            "cwd": "${workspaceFolder}",
            "executable": "./Template_proj.elf",
            "armToolchainPath": "/opt/gcc-arm-none-eabi-10.3-2021.10/bin/",
            "gdbPath": "/opt/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gdb",
            "device": "STM32F401RETx",
            "configFiles": [
                "interface/stlink-v2.cfg",
                "target/stm32f4x.cfg"
            ],
            "svdFile": "${workspaceFolder}/STM32F401.svd",
            "runToEntryPoint": "main",
            "autorun": [
                "monitor reset halt",
                "load",
                "monitor reset init"
            ],
            "preLaunchTask": "Build Project"
        }
    ]
}
Key Points:
servertype: Set to stlink for STLINK-based debugging.
gdbPath: Path to your ARM GCC GDB binary (arm-none-eabi-gdb).
configFiles: Configuration files needed for OpenOCD (interface/stlink-v2.cfg and target/stm32f4x.cfg).
svdFile: Optional file for viewing STM32F4 peripheral registers in VSCode.
runToEntryPoint: Run to the specified entry point (main() in this case).
preLaunchTask: Task to build your project before launching the debugger.
Step 5: Building and Debugging
Build the Project
In the terminal, run the following command to compile the project:

bash
Copy
Edit
make
Or use the VSCode Tasks system to automate this as preLaunchTask.

Start Debugging
Launch OpenOCD (if using the attach configuration):

bash
Copy
Edit
openocd -f interface/stlink-v2.cfg -f target/stm32f4x.cfg
Start the Debugging Session in VSCode by selecting the Debugging STLINK STM32F4 or Debugging OpenOCD STM32F4 configuration and clicking Run.

GDB Commands
Once the debugger is connected, you can use common GDB commands like:

monitor reset halt: Reset and halt the target.
load: Load the program to the target.
run: Start execution.
break main: Set a breakpoint at the main() function.
step / next: Step through the code.
continue: Continue execution until the next breakpoint.
Troubleshooting
OpenOCD fails to start: Make sure that your STLINK device is properly connected. Try using different USB ports.
GDB fails to connect: Ensure that OpenOCD is running before trying to attach with GDB.
ST-Link errors: Check that the correct drivers for ST-Link are installed on your system.
