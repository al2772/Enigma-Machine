# Enigma-Machine
Uses rotors to encrypt and decrypt messages. The user will input a message in all caps, then will choose up to 4 rotors (numbered 1-8) to encrypt the message. Next, the user is asked to enter the number of times each rotor will be rotated. Finally, the program returns a encrypted message followed by the message decrypted again.

To compile:

gcc -g enigma_functions.c enigma_driver.c -Wall

To run:

./a.out

Example:

Enter the message to be encrypted or decrypted: IRONMAN VS BATMAN

Which rotors will be used to encrypt the message: 1287

Enter the number of rotations to apply to the encryption rotors: 25

The encrypted message is: WNXBEHB PO UHSEHB

The decrypted message is: IRONMAN VS BATMAN
