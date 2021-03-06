# Introduction to Robotics, FMI UniBuc 2021

## Description

  Introduction to Robotics laboratory homeworks, taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest. Each homework includes requirements, implementation details, code and image files to monitor and showcase my learning process.

# Homeworks

## 1. Homework #0
  Installed [Arduino IDE](https://www.arduino.cc/en/software) & created this repo for storing and monitoring all files.

## 2. Homework #1

  1) **Components:** RGB led (x1), potentiometers (x3), 330Ω resistors (x3) and wires (x15)

  2) **Technical task:** Use a separat potentiometer in controlling each of the color of the RGB led (Red,Green and Blue). The control must be done with digital electronics.
  
  3) **Picture of the circuit:** 
  
      <img src="https://user-images.githubusercontent.com/61471997/138553789-233b42b2-70c2-454b-8a99-07e9f6b14e9b.jpg" data-canonical-src="https://user-images.githubusercontent.com/61471997/138553789-233b42b2-70c2-454b-8a99-07e9f6b14e9b.jpg" width="400" height="500" />

  4) **Video:** <a href="https://www.youtube.com/watch?v=n3mSYVlwWYk" target="_blank">here</a>

  5) You can find the code [here](RGB_LED_3_potentiometers.ino).

## 3. Homework #2

  1) **Components:** RGB led (x5), button (x1), buzzer (x1), 330Ω resistors (x2) and wires (x11)

  2) **Technical task:** Building the traffic lights for a crosswalk. 2 LEDs represent the traffic lights for pedestrians (red & green) and 3 LEDs represent the traffic lights for vehicles (red, yellow & green).

  3) **Picture of the circuit:**
  
      <img src="https://user-images.githubusercontent.com/61471997/139835966-d7bad546-0751-4ee3-95e9-bb27711fa9a9.jpeg" data-canonical-src="https://user-images.githubusercontent.com/61471997/139835966-d7bad546-0751-4ee3-95e9-bb27711fa9a9.jpeg" width="400" height="500" />
      
  4) **Video:** <a href="https://www.youtube.com/shorts/D7a8uw-gKKc" target="_blank">here</a>

  5) You can find the code [here](traffic_light.ino).

## 3. Homework #3

  1) **Components:** 7-segment display, buzzer (x1), 100Ω resistor (x1), 330Ω resistors (x2), 1MΩ resistors (x3) and wires (x15).

  2) **Technical task:** Building an EMF (electromagnetic field) detector.

  3) **Picture of the circuit:**

      <img src="https://user-images.githubusercontent.com/61471997/140937758-0d30a945-d546-43b9-8c55-0ed8b4ec7ca0.jpg" data-canonical-src="https://user-images.githubusercontent.com/61471997/140937758-0d30a945-d546-43b9-8c55-0ed8b4ec7ca0.jpg" width="400" height="500" />
      
  4) **Video:** <a href="https://www.youtube.com/watch?v=VjAoJ53yiV4" target="_blank">here</a>

  5) You can find the code [here](EMF_detector.ino).

## 4. Homework #4

  1) **Components:** 4 digit 7-segment display (x1), joystick (x1),  74hc59 shift register  (x1), 330Ω resistors (x4), and wires.

  2) **Technical task:** 
      - In the first state you can cycle through the digits by tilting the joystick left or right. The blinking dot indicated the current digit
      - When pressing the button we switch to the second state. Locked in on a digit, tilting the joystick up and down we increment or decrement the digit's value. When pressing the button again the value is saved and we return to the first state.
      - Values are saved in eeprom, so on a reset, the last saved value is loaded.

  3) **Picture of the circuit:**

      <img src="https://user-images.githubusercontent.com/61471997/141974246-e6c5721b-bbc5-41a0-92dc-92a3203fcf36.jpg" data-canonical-src="https://user-images.githubusercontent.com/61471997/141974246-e6c5721b-bbc5-41a0-92dc-92a3203fcf36.jpg" width="400" height="500" />
      
  4) **Video:** <a href="https://www.youtube.com/watch?v=4iLLTVzR0OU" target="_blank">here</a>

  5) You can find the code [here](Four_Digits_Digital_Switcher.ino).
