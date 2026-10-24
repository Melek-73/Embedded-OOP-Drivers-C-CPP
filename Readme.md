# Embedded OOP Drivers in C and C++

Low-level embedded firmware development on the **STM32F7 Discovery board**, using C and C++.

This repository contains GPIO and UART driver and library implementations developed from scratch, along with LED classes demonstrating object-oriented programming in C and C++.

## Repository Structure

```text
Embedded-OOP-Drivers-C-CPP/
│
├── GPIO_driver_C/
├── GPIO_driver_C++/
├── LedClass_uartDriver_C/
└── LedClass_uartDriver_C++/
```

## Implemented Features

### GPIO Driver

- GPIO initialization and pin configuration.
- Input and output modes.
- GPIO pin reading, writing, and toggling.
- Peripheral clock enabling through RCC registers.
- Direct register manipulation using bit masks and bitwise operations.

### UART Driver

- UART driver and library implementation in C and C++.
- Peripheral configuration and register-level access.
- Integration of the driver into embedded applications.
- Testing and debugging on the target hardware.

### LED Classes and OOP

- LED class implementation in C and C++.
- `PowerLED` and `MedicalLED` derived classes.
- Inheritance and polymorphism in C++.
- Polymorphism in C using function pointers and a virtual function table (vtable).

## Hardware and Tools

- **Board:** STM32F7 Discovery (STM32F746NGHx)
- **Languages:** C and C++
- **IDE:** Keil µVision
- **Hardware documentation:** STM32 datasheets and reference manuals

## Getting Started

Clone the repository:

```bash
git clone https://github.com/Melek-73/Embedded-OOP-Drivers-C-CPP.git
cd Embedded-OOP-Drivers-C-CPP
```

1. Navigate to the desired project folder.
2. Open the corresponding Keil project file (`.uvprojx`).
3. Build the project.
4. Program the STM32F7 Discovery board.
5. Run and test the implementation.

## Skills

- Embedded C and C++ programming.
- GPIO and UART driver development.
- Memory-mapped I/O and peripheral register configuration.
- RCC clock configuration and bitwise register manipulation.
- Reading STM32 datasheets and reference manuals.
- Object-oriented programming and modular firmware design.
- Hardware testing and debugging.
