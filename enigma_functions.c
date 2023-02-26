#include "enigma.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *ROTOR_CONSTANTS[] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ", // Identity Rotor (index 0 - and useful for testing):
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
        "AJDKSIRUXBLHWTMCQGZNPYFVOE",
        "BDFHJLCPRTXVZNYEIWGAKMUSQO",
        "ESOVPZJAYQUIRHXLNFTGKDCMWB",
        "VZBRGITYUPSDNHLXAWMJQOFECK",
        "JPGVOUMFYQBENHZRDKASXLICTW",
        "NZJHGRCXMYSWBOUFAIVLPEKQDT",
        "FKQHTLXOCBJSPDZRAMEWNIUYGV",
};

// This method reads a character string from the keyboard and 
// stores the string in the parameter msg.
// Keyboard input will be entirely uppercase and spaces followed by 
// the enter key.  
// The string msg should contain only uppercase letters spaces and 
// terminated by the '\0' character
// Do not include the \n entered from the keyboard
void Get_Message(char msg[]){
	// read the input into msg
	fgets(msg, 80, stdin);

	// remove the newline char
	if (strlen(msg) > 0 && msg[strlen(msg) - 1] == '\n'){
		msg[strlen(msg) - 1] = '\0';
	}
	

    return;
}

// This function reads up to 4 characters from the keyboard
// These characters will be only digits 1 through 8. The user
// will press enter when finished entering the digits.
// The rotor string filled in by the function should only contain 
// the digits terminated by the '\0' character. Do not include
// the \n entered by the user. 
// The function returns the number of active rotors.
int Get_Which_Rotors(char which_rotors[]){
	// read input into which_rotors
	fgets(which_rotors, 5, stdin);

	// remove the newline character
	if (strlen(which_rotors) > 0 && which_rotors[strlen(which_rotors) - 1] == '\n'){
		which_rotors[strlen(which_rotors) - 1] = '\0';
	}
    // return the number of rotors added
    return strlen(which_rotors);
} 

// This function reads an integer from the keyboard and returns it 
// This number represents the number of rotations to apply to the 
// encryption rotors.  The input will be between 0 and 25 inclusive
int Get_Rotations(){
	// initialize num_rotations
	int num_rotations;
	// read the char to num rotations
	scanf("%d", &num_rotations);

    return num_rotations;
}


// This function copies the rotors indicated in the which_rotors string 
// into the encryption_rotors.  For example if which rotors contains the string 
// {'3', '1', '\0'} Then this function copies the third and first rotors into the 
// encryption rotors array in positions 0 and 1.  
// encryptions_rotors[0] = "BDFHJLCPRTXVZNYEIWGAKMUSQO"
// encryptions_rotors[1] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
void Set_Up_Rotors(char encryption_rotors[4][27], char which_rotors[5]){
	int rotor;

	// loop through which_rotors
	for (int i  = 0; i < strlen(which_rotors); i++){
		// check chars and set the rotor
		if (which_rotors[i] == '1'){
			rotor = 1;
		}
		 if (which_rotors[i] == '2'){
                        rotor = 2;
                }
		  if (which_rotors[i] == '3'){
                        rotor = 3;
                }
		   if (which_rotors[i] == '4'){
                        rotor = 4;
                }
		   if (which_rotors[i] == '5'){
                        rotor = 5;
                }
		   if (which_rotors[i] == '6'){
                        rotor = 6;
                }
             	   if (which_rotors[i] == '7'){
                        rotor = 7;
                }
 	           if (which_rotors[i] == '8'){
                        rotor = 8;
                }
                strcpy(encryption_rotors[i], ROTOR_CONSTANTS[rotor]);


	}


    return;
}

// Takes an array and it's length and rotates each element of the array
// one position to the right. Helper method for the Appliy_Rotations
// method
void Rotate_Right(char array[], int length){
	char temp = array[length - 1];
	
	// loop through array and shift each element right, then add
	// the last value back as the first element
	for (int i = (length - 2); i >= 0; i--){
		array[i + 1] = array[i];
	}
		array[0] = temp;
}

// This function rotates the characters in each of the active encryption rotors
// to the right by rotations.  For example if rotations is 3 encryption_rotors[0]
// contains "BDFHJLCPRTXVZNYEIWGAKMUSQO" then after rotation this row will contain
// SQOBDFHJLCPRTXVZNYEIWGAKMU.  Apply the same rotation to all for strings in 
// encryption_rotors
void Apply_Rotation(int rotations, char encryption_rotors[4][27]) {
	// loop through each rotor
	for (int i = 0; i < 4; i++){
		// rotate for the number of rotations
		for (int j = 0; j < rotations; j++){
			Rotate_Right(encryption_rotors[i], strlen(encryption_rotors[i]));
	}
	}

    return;
}

// This function takes a string msg and applys the enigma machine to encrypt the message
// The encrypted message is stored in the string encryped_msg 
// Do not change spaces, make sure your encryped_msg is a \0 terminated string
void Encrypt(char encryption_rotors[4][27], int num_active_rotors, char msg[], char encrypted_msg[]){
	// make an array to store the indexes of each char
	int index[strlen(msg)];

	for (int k = 0; k < num_active_rotors; k++){
		for (int i = 0; i < strlen(msg); i++){
	// find each letter of message in the identity rotor
			for (int j = 0; j < strlen(ROTOR_CONSTANTS[0]); j++){
				if (msg[i] == ' '){
					index[i] = -1;
			}
				if (msg[i] == ROTOR_CONSTANTS[0][j]){
					index[i] = j;
			}
		}
	}

	// loop through the length of message and at each index number
	// add the corresponding letter to encrypted_msg
	for (int i = 0; i < strlen(msg); i++){
		// loop through encryption_rotors
		for (int j = 0; j < 27; j++){
		       if (index[i] == -1){
		       	msg[i] = ' ';
		       }
       		       if (index[i] == j){
			msg[i] = encryption_rotors[k][j];
 			}
		}
	}
	}

	for (int i = 0; i < strlen(msg); i++){
		encrypted_msg[i] = msg[i];
	}
	
	encrypted_msg[strlen(encrypted_msg) + 1] = '\0';

	return;
}


// This function takes a string msg and applys the enigma machine to decrypt the message
// The encrypted message is stored in the string encryped_msg and the decrypted_message 
// is returned as a call by reference variable
// remember the encryption rotors must be used in the reverse order to decrypt a message
// Do not change spaces, make sure your decrytped_msg is a \0 terminated string
void Decrypt(char encryption_rotors[4][27], int num_active_rotors, char encrypted_msg[], char decrypted_msg[]) {
	
	 // make an array to store the indexes of each char
        int index[strlen(encrypted_msg)];

        for (int k = num_active_rotors-1; k >= 0; k--){
                for (int i = 0; i < strlen(encrypted_msg); i++){
        // find each letter of message in the identity rotor
                        for (int j = 0; j < strlen(encryption_rotors[k]); j++){
                                if (encrypted_msg[i] == ' '){
                                        index[i] = -1;
                        }
                                if (encrypted_msg[i] == encryption_rotors[k][j]){
                                        index[i] = j;
                        }
                }
        }
		

        // loop through the length of message and at each index number
        // add the corresponding letter to encrypted_msg
        for (int i = 0; i < strlen(encrypted_msg); i++){
                // loop through encryption_rotors
                for (int j = 0; j < 27; j++){
                       if (index[i] == -1){
                       encrypted_msg[i] = ' ';
                       }
                       if (index[i] == j){
                        encrypted_msg[i] = ROTOR_CONSTANTS[0][j];
                        }
                }

        }
        }

   strcpy(decrypted_msg, encrypted_msg);

 return;
}
