// DispensadorEfectivo.java
// Representa al dispensador de efectivo del ATM

public class DispensadorEfectivo 
{
   // el número inicial predeterminado de billetes en el dispensador de efectivo
   private final static int CUENTA_INICIAL = 500;
   private int cuenta; // número restante de billetes de $20 
   
   // el constructor sin argumentos de DispensadorEfectivo inicializa cuenta con el valor predeterminado
   public DispensadorEfectivo()
   {
      cuenta = CUENTA_INICIAL; // establece el atributo cuenta al valor predeterminado
   } // fin del constructor de DispensadorEfectivo

   // simula la acción de dispensar el monto especificado de efectivo
   public void dispensarEfectivo( int monto )
   {
      int billetesRequeridos = monto / 20; // número de billetes de $20 requeridos
      cuenta -= billetesRequeridos; // actualiza la cuenta de billetes
   } // fin del método dispensarEfectivo

   // indica si el dispensador de efectivo puede dispensar el monto deseado
   public boolean haySuficienteEfectivoDisponible( int monto )
   {
      int billetesRequeridos = monto / 20; // número de billetes de $20 requeridos

      if ( cuenta >= billetesRequeridos  )
         return true; // hay suficientes billetes disponibles
      else 
         return false; // no hay suficientes billetes disponibles
   } // fin del método haySuficienteEfectivoDisponible
} // fin de la clase DispensadorEfectivo