Demo 1

# Introduction

In this demo, there is only 1 button input and only 1 LED output.

This is the most simple example.

# Functional description

There are 4 operation modes:
- mode 0: LED is kept off.
- mode 1: LED is kept on.
- mode 2: LED is blinking as 1 second on and 1 second off.
- mode 3: LED is blinking as 0.3 second on and 0.3 second off.

After power on reset, it is in mode 0.

In mode 0, if the button is pressed longer than 3 seconds, it will goto mode 1.

In mode 1, if the button is pressed longer than 3 seconds, it will go back to mode 0.
In mode 1, if the button is pressed shorter than 0.5 second, it will go to mode 2.

In mode 2, if the button is pressed longer than 3 seconds, it will go back to mode 0.
In mode 2, if the button is pressed shorter than 0.5 second, it will go to mode 3.

In mode 3, if the button is pressed longer than 3 seconds, it will go back to mode 0.
In mode 3, if the button is pressed shorter than 0.5 second, it will go to mode 0.
