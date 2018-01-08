

// --------------------------------------------- CanNet_Relay ---------------------------------------------
#ifndef CanNet_Relay_h
  #define CanNet_Relay_h

  #include "Arduino.h"

  class CanNet_Relay {

    public:
      // --------------------------------------------- Setup ---------------------------------------------
      CanNet_Relay(byte Start_Pin, byte End_Pin);


      // --------------------------------------------- CanNet_Relay ---------------------------------------------
      void Set_State(byte Relay_Number, byte State);
      void Set_State_Delay(byte Relay_Number, byte State, unsigned int Delay_Multiplyer, byte Delay);
      bool Get_State(byte Relay_Number);


    private:
      // --------------------------------------------- private ---------------------------------------------

      byte _Relay_Begin_Pin;
      byte _Relay_End_Pin;



  };

#endif
