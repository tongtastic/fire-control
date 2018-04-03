
int DWELL = 20;
int RATE = 30;
int SOLENOID = 2;
int SEMI = A4;
int FULLAUTO = A5;
int SEMISTATE = LOW;
int SEMISTATUS = LOW;

void setup()
{
  pinMode( SOLENOID, OUTPUT ); // Solenoid
  pinMode( SEMI, INPUT_PULLUP ); // Semi Auto
  pinMode( FULLAUTO, INPUT_PULLUP ); // Full Auto

}

void loop()
{

  SEMISTATE = digitalRead( SEMI );
  
  if( SEMISTATUS != SEMISTATE )
  {

    if( SEMISTATE == LOW ) {

      semiAuto();

    }

    delay( 50 );

    SEMISTATUS = SEMISTATE;

  }
  

  if( digitalRead( FULLAUTO ) == LOW )
  {

    fullAuto();

  }
  
}

void semiAuto()
{

  digitalWrite( SOLENOID, HIGH );

  delay( DWELL );

  digitalWrite( SOLENOID, LOW );
  
}

void fullAuto()
{

  digitalWrite( SOLENOID, HIGH );

  delay( DWELL );

  digitalWrite( SOLENOID, LOW );

  delay( RATE );

  if( digitalRead( FULLAUTO ) == LOW )
  {

    fullAuto();

  }

}

