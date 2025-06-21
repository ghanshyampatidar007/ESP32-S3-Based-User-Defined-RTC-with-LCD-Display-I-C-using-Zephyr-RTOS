🕒 ESP32-S3 Based User-Defined RTC with LCD Display (I²C) using Zephyr RTOS

📘 Project Summary
This project demonstrates how to implement a user-defined real-time clock (RTC) system using the ESP32-S3 microcontroller and display time and user-defined information on an LCD 2004A display via I²C communication, running under the Zephyr RTOS.

It showcases both the use of Zephyr's built-in features and the development of a custom LCD driver, providing complete control over low-level I²C communication and HD44780 command handling.


🧰 What We're Using

✅ Hardware Components:

ESP32-S3 DevKitC: The main microcontroller board.

LCD 2004A (20x4 character): For displaying custom time and user messages.

PCF8574 I²C Backpack: Used to interface the LCD with I²C, reducing GPIO usage.

I²C Lines:

SDA – GPIO1

SCL – GPIO2

Pull-up Resistors (4.7kΩ) on SDA/SCL for reliable I²C signaling.


✅ Software & Tools:

Zephyr RTOS: Real-time operating system managing timing, drivers, and task execution.

VS Code + Zephyr SDK: Development environment and toolchain.

CMake & Ninja: Build system tools supported by Zephyr.


⚙️ Key Implementation Features
🧠 Custom User-Defined RTC

This project does not use an external RTC module (like DS1307 or DS3231).

Instead, it uses Zephyr’s k_uptime_get() to track system uptime.

A manual time-set offset is added at boot to simulate real-world clock time.

Time is displayed in HH:MM:SS format and updated regularly.


💡 I²C Used Creatively

The parallel LCD interface is managed through a PCF8574 I²C I/O expander.

This allows LCD control using just 2 GPIOs (SDA/SCL), demonstrating efficient hardware usage.

I²C protocol is leveraged to its limit, handling command/data writes, control bits, delays, and display updates with precision timing.


🛠️ Custom LCD Driver (HD44780 over I²C)

A fully custom LCD driver was developed for this project.

It directly controls the HD44780-based 2004A display via I²C, handling:

Initialization sequences

Command and data writes

Cursor positioning

Text printing

This provides full control and flexibility compared to off-the-shelf libraries.

🔧 Zephyr Built-in Driver Use

Zephyr’s built-in I²C API (i2c_write, device_get_binding, etc.) is used to interact with the LCD at the bus level.

This keeps the application modular and portable within the Zephyr ecosystem.


🖥️ Final Output

At runtime, the LCD displays:

  TIME:  12:34:56

  NAME:  GHANSHYAM

The time ticks in real-time (updated per second).

The name is static or can be customized from code.


📌 Highlights
✅ Demonstrates custom driver development in Zephyr.

✅ Uses I²C efficiently to reduce pin usage.

✅ No external RTC needed — software RTC logic used.

✅ Compatible with any I²C HD44780 LCD via PCF8574.
