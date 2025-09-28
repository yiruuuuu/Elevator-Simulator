# Elevator-Simulator
You are tasked with developing an elevator system that has two elevators and ten floors. Your 
program should include a user interface that allows users to input the desired floor number, 
and the current floor for each elevator should be displayed. 
Requirements: 
1. Define a class called "Elevator" that has the following attributes and methods: 
Attributes: 
● "current_floor": an integer representing the current floor of the elevator. 
2. Methods: 
● "display_floor()": a method that displays the current floor of the elevator. 
● "move(current: int, floor: int)": a method that moves the elevator to the 
specified floor. This method should set the "current_floor" attribute to the 
specified floor and call the "display_floor()" method to display the current floor. 
3. Create two "Elevator" objects named "elevator1" and "elevator2". 
4. Implement a user interface that allows users to input their current floor and the 
desired floor number. The program should move the elevators to the specified floors 
and display their current floors. 
Optional (Bonus): 
1. The elevator moving speed is one floor per second. 
2. Implement Unit Test. 
3. Remote Control: Implement client and server into this simulator. This is the use case 
for a security guard monitoring the elevator remotely in the central control room. 
