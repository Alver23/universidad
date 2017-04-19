SET SERVEROUTPUT ON

ACCEPT EQUIPOS PROMPT 'Con cuantos equipos de computos desea iniciar ? : ';

DECLARE
  TEMP_INICIAL NUMBER (18,8) := 274.817;
  TEMP_FINAL DECIMAL ;
  TEMPERATURA NUMBER (18,8);
  FAHRENGEIH DECIMAL;
  KELVIN DECIMAL;
  CELSIUS DECIMAL;
  CANTIDAD DECIMAL;
  
BEGIN
  TEMPERATURA := TEMP_INICIAL;
  CANTIDAD := &EQUIPOS;
  
   IF CANTIDAD >= 0 AND CANTIDAD <= 16 THEN
  -- KELVIN = (CANTIDAD *  (-271.15));
    TEMPERATURA := TEMPERATURA + (CANTIDAD *  (2));
    TEMP_FINAL := TEMPERATURA - 273.15;
   
      IF TEMPERATURA > 298.15 THEN
        DBMS_OUTPUT.PUT_LINE ('Por favor realizar un enfrianmiento forzoso, los equipos esta en riezgo, temperatura actual es ' || TEMP_FINAL || ' °C');
      ELSE
        DBMS_OUTPUT.PUT_LINE ('La temperatura actual es : '|| TEMP_FINAL || ' °c');
      END IF;
   
   END IF;  
  
END;
