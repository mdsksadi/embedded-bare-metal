# embedded-bare-metal
This repository documents my practice bare-metal embedded systems programming.

The repository is based on: 
- [GitHub](https://github.com/lowbyteproductions/bare-metal-series/tree/main)
- [YouTube](https://www.youtube.com/watch?v=uQQsDWLRDuI&list=PLP29wDx6QmW7HaCrRydOnxcy8QmW0SNdQ)

## Who is this for?
- Fols who are learning about low-level programming.
- People who have played with platforms like Arduino, but want to pop the hood.
- Those working in industry, who've only used propriatery tools and frameworks.
- Fols wanting to understand specific concepts, e.g., building a bootloader, or firmware signing mechanism.

## Goals 
- Cover fundamentals of programming a modern microcontroller 
- Use open—source stack (gcc, tibopencm3) 
- Bare metal (no RTOS) 
- Explore and understand the setup and use of various key peri pherals 
- Bootloader, allowing firmware updates over USB serial 
- Signed firmware mechanism 

## Non-Goals
- Perfect, production-ready firmware (think: Edecational MVP)
- Bug free code (**I will make mistake**)
- Optimal utilisation of every resource
- Comparehensive overview of the c programming language
- The best file structure / code organisation / modularity / design pattern usage / etc.

## Used-HW
STM32L432KC
