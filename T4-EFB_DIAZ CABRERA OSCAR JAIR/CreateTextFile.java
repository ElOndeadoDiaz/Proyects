//Escribir datos en un archivo de texto secuencial con la clase Formatter.
import java.io.FileNotFoundException;
import java.lang.SecurityException;
import java.util.Formatter;
import java.util.FormatterClosedException;
import java.util.NoSuchElementException;
import java.util.Scanner;

import com.deitel.ch17.AccountRecord;

public class CreateTextFile{
    private Formatter output; //objeto utilizado para generar texto en un archivo
    
    //Permitir al usuario abrir el archivo
    public void openFile(){
      try {
          output=new Formatter("clients.txt"); //abre el archivo
        }
      catch(SecurityException securityException) {
          System.err.println("No tiene acceso de escritura a este archivo.");
          System.exit(1); //termina el programa
            }
        catch(FileNotFoundException fileNotFoundException) {
            System.err.println("Error al abrir o crear archivo.");
            System.exit(1);//termina el programa
        }//end catch
    }//fin del metodo abri archivo
    
    //agrega registros al archivo
    public void addRecords(){
        //objeto que se escribirá en el archivo
         Scanner input = new Scanner(System.in);
         AccountRecord record = new AccountRecord();
        
       
        
        System.out.printf("%s\n%s\n%s\n%s\n\n",
        "Para finalizar la entrada, escriba el indicador de fin de archivo",
        "En UNIX/Linux/Mac OS X, escriba <ctrl> d y luego presione Enter",
        "En Windows, escriba <ctrl> z y luego presione Enter.",
        "Ingrese: numeroCuenta Nombre Apellido NIP saldoDisponible saldoTotal");
        
        System.out.printf("? ");
        
        while(input.hasNext())//bucle hasta el indicador de fin de archivo
        {
            try //valores de salida al archivo
            {
                //recuperar datos para su salida
                record.setAccount(input.nextInt()); //lee numero de cuenta
                record.setFirstName(input.next()); //lee el primer nombre
                record.setLastName(input.next()); //lee el apellido
                record.setPin(input.nextInt());//NIP
                record.setSaldoDisponible(input.nextDouble());  //SaldoDisponible
                record.setSaldoTotal(input.nextDouble());   //saldo total
                
                if(record.getAccount()>0){
                    //escribe un nuevo registro
                    output.format("%d %s %s %d %.2f %.2f\n", 
                    record.getAccount(),
                    record.getFirstName(), 
                    record.getLastName(), 
                    record.getPin(),
                    record.getSaldoDisponible(),
                    record.getSaldoTotal());
                }// fin del if
                else{
                    System.out.println("Numero de cuenta debe ser mayor que 0.");
                }//fin del else
            }//fin de try
            catch(FormatterClosedException formatterClosedException){
                System.err.println("Error al escribir en el archivo.");
                return;
            }//fin del catch
            catch(NoSuchElementException elementException){
                System.err.println("Entrada invalida. Intente de nuevo.");
                input.nextLine(); //Descartar entrada para que el usuario pueda intentarlo de nuevo
            }//fin del catch
            
            System.out.printf("? ");
        }//fin del ciclo
    }//fin del metodo addRecords
    
    //cerrar archivo
    public void closeFile(){
        if(output!=null)
            output.close();
    }// fin del metodo closeFile
}//fin de la clase