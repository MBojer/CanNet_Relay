

// --------------------------------------------- CanNet_Relay ---------------------------------------------
#include "Arduino.h"
#include "CanNet_Relay.h"


// --------------------------------------------- Setup ---------------------------------------------
CanNet_Relay::CanNet_Relay(byte Start_Pin, byte End_Pin) {

  _Relay_Begin_Pin = Start_Pin;
  _Relay_End_Pin = End_Pin;

  for (int i = _Relay_Begin_Pin; i < _Relay_End_Pin + 1; i ++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, 1);
  }

} // CanNet_Relay


// --------------------------------------------- Functions ---------------------------------------------
void CanNet_Relay::Set_State(byte Relay_Number, byte State)
{
} // Set_State


void CanNet_Relay::Set_State_Delay(byte Relay_Number, byte State, unsigned int Delay_Multiplyer, byte Delay)
{
} // Set_State_Delay


bool CanNet_Relay::Get_State(byte Relay_Number)
{



} // Get_State



void Relay(String Relay_Number_String, int Relay_State, int Relay_Begin_Pin, int Relay_End_Pin) {

  if (Relay_Number_String == "AA") {

    for (int x = Relay_Begin_Pin; x < Relay_End_Pin + 1; x ++) {
      // I2C_Broadcast("T1N" + String(x - Relay_Begin_Pin + 1) + "V4" + String(digitalRead(x)));
      delay(150);
    }
    return;
  }

  else {

    int Relay_Number = Relay_Number_String.toInt();

    Relay_Number = Relay_Number + Relay_Begin_Pin - 1;

    pinMode(Relay_Number, OUTPUT);

    if (Relay_State == 1) { // --- ON ---
      digitalWrite(Relay_Number, 0);
    }

    else if (Relay_State == 2) { // --- OFF ---
      digitalWrite(Relay_Number, 1);
    }

    else if (Relay_State == 3) {  // Flip State

      if (digitalRead(Relay_Number) == 1) {
        digitalWrite(Relay_Number, 0);
      }

      else {
        digitalWrite(Relay_Number, 1);
      }
    }


    // I2C_Broadcast("T1N" + String(Relay_Number - Relay_Begin_Pin + 1) + "V4" + String(digitalRead(Relay_Number)));
  }

} // End marker for I2C Relay
