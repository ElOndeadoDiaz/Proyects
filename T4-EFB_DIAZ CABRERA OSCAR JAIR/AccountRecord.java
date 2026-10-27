package com.deitel.ch17;

public class AccountRecord{
    private int account;
    private String firstName;
    private String lastName;
    private int pin;
    private double saldoDisponible;
    private double saldoTotal;
    
    //Un constructor sin argumentos llama a otro constructor con valores predeterminados
    public AccountRecord(){
        this(0, "", "", 0, 0.0, 0.0); //llamar al constructor de seis argumentos
    }// fin del constructor sin argumentos
    
    //inicializa un registro
    public AccountRecord(int acct, String first, String last, int pin, double saldoDisponible, double saldoTotal){
        setAccount(acct);
        setFirstName(first);
        setLastName(last);
        setPin(pin);
        setSaldoDisponible(saldoDisponible);
        setSaldoTotal(saldoTotal);
    }//fin del constructor con seis argumentos
    
    //set account Number
    public void setAccount(int acct){
        this.account=acct;
    }//fin del metodo
    
    //get account Number
    public int getAccount(){
        return account;
    }
    
    //set first name
    public void setFirstName(String first){
        this.firstName=first;
    }//fin del metodo
    
    //get first name
    public String getFirstName(){
        return firstName;
    }
    
    //set last name
    public void setLastName(String last){
        this.lastName=last;
    }//fin del metodo
    
    //get last name
    public String getLastName(){
        return lastName;
    }
    
    //set del pin
    public void setPin(int pin){
        this.pin=pin;
    }//fin del set
    
    //get del pin
    public int getPin(){
        return pin;
    }
    
    //set saldoDisponible
    public void setSaldoDisponible(double saldo){
        this.saldoDisponible=saldo;
    }//fin del metodo
    
    //get saldoDisponible
    public double getSaldoDisponible(){
        return saldoDisponible;
    }//fin del metodo getBalance
    
    //set saldoTotal
    public void setSaldoTotal(double saldo){
        this.saldoTotal=saldo;
    }
    //fin del get de saldoTotal
    //get saldoTotal
     public double getSaldoTotal() {
        return saldoTotal;
    }
    //fin del get
}//fin de la clase Registro de cuenta