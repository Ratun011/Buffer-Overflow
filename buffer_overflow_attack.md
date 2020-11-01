# buffer_overflow_13

//Author name: Akib Ahmed

#1. Create c file and write the code: <br>
 •	At first, we create a c file containing the code we are given, naming it vulnerable.c. Then we see the code in the terminal using the cat vulnerable.c command.
![](Screen_Shots/0.png)

#2. Disabling memory randomization, enabling core dumps: <br>
•	Then we check the current state of randomization with the command cat /proc/sys/kernel/randomize_va_space
![](Screen_Shots/1.png)

•	As the value is 2, that means memory randomization is true. So, we have to turn of the randomization using the following command:
![](Screen_Shots/2.png)

•	We check that the value has actually changed:
![](Screen_Shots/3.png)

•	Then we check ulimit:
![](Screen_Shots/4.png)

•	After that we set ulimit to unlimited and check again:
![](Screen_Shots/5.png)

#3. Compiling the c program: <br>
•	Then we compile the c program and run it by the following command which may be terminated because of the unavailability of a library function. If it is terminated then we have to install the library using the command:
![](Screen_Shots/6.png)

•	Many packages will be installed during the whole process. After finishing, then we have to compile and run the file again:
![](Screen_Shots/7.png)

#4. Using GNU Debugger (GDB) and Exploit Buffer: <br>
•	Then we enter into the gdb terminal using gdb ./vulnerable
![](Screen_Shots/8.png)

•	First disassemble main to know the function state of main in memory: 
![](Screen_Shots/9.png)

•	Then disassemble login to know the state of login in memory
![](Screen_Shots/10.png)

•	Similarly, disassemble user:
![](Screen_Shots/11.png)

•	Then execute the file and give a wrong password, so that exploit the functionalities can be easily monitored:
![](Screen_Shots/12.png)

•	Again, disassemble login:
![](Screen_Shots/13.png)

•	Furthermore, we will set 2 breakpoints. 
•	The 1st one will be set to the register of the scanf() function which takes input. Next time, when we run the program, a breakpoint will appear in the time of giving input.
![](Screen_Shots/14.png)

•	The 2nd one will be in a stage, where the input is loaded and stored in a register before approaching the next call function. Thus, we can know the register, which stored the wrong password at the time we tried to login.
![](Screen_Shots/15.png)

•	When we run the program after setting the breakpoint, we will hit the 1st breakpoint.
![](Screen_Shots/16.png)

•	Then using x/20x $esp command we want to see the nature of the 20 registers specifically.
![](Screen_Shots/17.png)

•	We continue our process using command c:
•	But now we got hit in breakpoint 2.
![](Screen_Shots/18.png)

•	Then again, we see the conditions of 20 registers:
![](Screen_Shots/19.png)

•	Then we go out of the gdb (using ctrl+shift+z) and create a text file to give input:
![](Screen_Shots/20.png)

•	Again, we enter in gdb (using command: fg) and disassemble login:
![](Screen_Shots/21.png)

•	Here we have to take the register value (which we get after execute ‘disassemble login’ command) of the user function. This is mainly the register, from where the user function is called. Then we have to go out of the gdb again and insert a password in the text file we created. From the next time we will use this text file as the input.  Now we will use 28 ‘A’s and a form of reverse order of the user register as the password and this input will overflow in the buffer registers. This input will be replaced in the instruction pointer (eip) which will grant the access for the user giving a long password and using the buffer overflow we will get the access granted.
![](Screen_Shots/22.png)

•	Now, we get back in the gdb and run the file using the text we created. Then similarly we will hit the two breakpoints we created before. In the 2nd breakpoint we will find the register number we gave (after a number of A(41)’s we put in the text file). That given register is the way for us to get access to the user account.
![](Screen_Shots/23.png)

•	We can check the register name and the work of it using the command x/i 0x565562b9. We see that it will show the user from the login function because of the buffer overflow we executed. Now if we command c to continue then we will see that the password is incorrect, but we have access to the user machine. That is our goal.
![](Screen_Shots/24.png)

•	Now if we go out of gdb, we will be able to gain the access using the terminal command also.
![](Screen_Shots/25.png)

•	In the beginning, we turned off the memory randomization. If we turn on that now and then run the buffer overflow attack in the terminal, we won’t be getting the access anymore.
![](Screen_Shots/26.png)
