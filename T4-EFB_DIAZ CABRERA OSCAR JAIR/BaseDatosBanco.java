// BaseDatosBanco.java
// Representa a la base de datos de información de cuentas bancarias

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import com.deitel.ch17.AccountRecord;

public class BaseDatosBanco
{
   private List<Cuenta> cuentas; // lista dinamica de oibjetos Cuenta
   
   // constructor: carga cuentas desde archivo
   public BaseDatosBanco()
   {
      cuentas = new ArrayList<>();
      cargarCuentasDesdeArchivo("clients.txt"); 
   }
   
   //Metodo para cargar cuentas desde un archivo de texto
   private void cargarCuentasDesdeArchivo(String nombreArchivo){
       try (Scanner input=new Scanner(new File(nombreArchivo))){
           while (input.hasNext()){
               int numeroCuenta=input.nextInt();
               String nombre = input.next();
               String apellido = input.next();
               int pin = input.nextInt();
               double saldoDisponible = input.nextDouble();
               double saldoTotal = input.nextDouble();
               
               //Crear AccountRecord y luego Cuenta
               AccountRecord record = new AccountRecord(numeroCuenta, nombre, apellido, pin, saldoDisponible, saldoTotal);
               Cuenta cuenta = new Cuenta(record.getAccount(), record.getPin(), record.getSaldoDisponible(), record.getSaldoTotal());
               cuentas.add(cuenta);
           }
       }catch (FileNotFoundException e){
           System.err.println("Archivo no encontrado: " + nombreArchivo);
           e.printStackTrace();
       }catch (Exception e){
           System.err.println("Error al leer el archivo de cuentas.");
           e.printStackTrace();
       }
   }//fin del Metodo
   
   //Buscar una cuenta por numero
   private Cuenta obtenerCuenta(int numeroCuenta){
       for(Cuenta cuenta:cuentas){
           if (cuenta.obtenerNumeroCuenta()==numeroCuenta)
           return cuenta;
       }
       return null;
   }
   
   /* obtiene el objeto Cuenta que contiene el número de cuenta especificado
   private Cuenta obtenerCuenta( int numeroCuenta )
   {
      // itera a través de cuentas, buscando el número de cuenta que coincida
      for ( Cuenta cuentaActual : cuentas )
      {
         // devuelve la cuenta actual si encuentra una coincidencia
         if ( cuentaActual.obtenerNumeroCuenta() == numeroCuenta )
            return cuentaActual;
      }  //fin de for

      return null; // si no se encontró una cuenta que coincida, devuelve null
   } // fin del método obtenerCuenta*/

   // determina si el número de cuenta y el NIP especificados por el usuario coinciden
   // con los de una cuenta en la base de datos
   public boolean autenticarUsuario( int numeroCuentaUsuario, int nipUsuario )
   {
      // trata de obtener la cuenta con el número de cuenta
      Cuenta cuentaUsuario = obtenerCuenta( numeroCuentaUsuario );
      return cuentaUsuario != null && cuentaUsuario.validarNIP(nipUsuario);
   } // fin del método autenticarUsuario

   // devuelve el saldo disponible de la Cuenta con el número de cuenta especificado
   public double obtenerSaldoDisponible( int numeroCuentaUsuario )
   {
      return obtenerCuenta( numeroCuentaUsuario ).obtenerSaldoDisponible();
   } // fin del método obtenerSaldoDisponible

   // devuelve el saldo total de la Cuenta con el número de cuenta especificado
   public double obtenerSaldoTotal( int numeroCuentaUsuario )
   {
      return obtenerCuenta( numeroCuentaUsuario ).obtenerSaldoTotal();
   } // fin del método obtenerSaldoTotal

   // abona un monto a la Cuenta a través del número de cuenta especificado
   public void abonar( int numeroCuentaUsuario, double monto )
   {
      obtenerCuenta( numeroCuentaUsuario ).abonar( monto );
   } // fin del método abonar

   // carga un monto a la Cuenta con el número de cuenta especificado
   public void cargar( int numeroCuentaUsuario, double monto )
   {
      obtenerCuenta( numeroCuentaUsuario ).cargar( monto );
   } // fin del método cargar
} // fin de la clase BaseDatosBanco