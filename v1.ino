
int DWELL = 20; // how long to open solenoid ms
int RATE = 30; // how long to wait after closing solenoid ms
int SOLENOID = 2; // solenoid control pin
int SEMI = A4; // semi auto switch pin
int FULLAUTO = A5; // full auto switch pin
int SEMISTATE = LOW; // start state of semi switch
int SEMISTATUS = LOW; // current state of semi switch

void setup()
{
  pinMode( SOLENOID, OUTPUT ); // Solenoid
  pinMode( SEMI, INPUT_PULLUP ); // Semi Auto
  pinMode( FULLAUTO, INPUT_PULLUP ); // Full Auto

}

void loop()
{

  SEMISTATE = digitalRead( SEMI ); // read current status of semi switch
  
  if( SEMISTATUS != SEMISTATE ) // not the same as last / start status (must be LOW)
  {

    if( SEMISTATE == LOW ) { // switch is closed

      semiAuto(); // fire semi auto shot

    }

    delay( 50 ); // wait to prevent the switch bouncing

    SEMISTATUS = SEMISTATE; // set current state to current trigger state

  }
  

  if( digitalRead( FULLAUTO ) == LOW ) // full auto switch is closed
  {

    fullAuto(); // fire full auto

  }
  
}

void semiAuto()
{

  digitalWrite( SOLENOID, HIGH ); // open solenoid

  delay( DWELL ); // wait to clear barrel

  digitalWrite( SOLENOID, LOW ); // close solenoid
  
}

void fullAuto()
{

  digitalWrite( SOLENOID, HIGH ); // open solenoid

  delay( DWELL ); // wait to clear barrel

  digitalWrite( SOLENOID, LOW ); // close soleniod

  delay( RATE ); // wait for next shot

  if( digitalRead( FULLAUTO ) == LOW ) // if trigger is still pulled
  {

    fullAuto(); // call function again

  }

}

