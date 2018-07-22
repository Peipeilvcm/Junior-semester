
public class HourlyEmployee extends Employee{
    private int wage;
    private int hours;

    public HourlyEmployee(){
        super();
        wage = hours = 0;
    }
    public HourlyEmployee(String fN, String lN, String sSN, int wg, int hr){
        super(fN, lN, sSN);
        wage = wg;
        hours = hr;
    }

    public final void setHours(int hr){             //final修饰，不能被子类覆盖
        hours = hr;
    }
    public final void setWage(int wg){
        wage = wg;
    }
    public final int getHours(){
        return hours;
    }
    public final int getWage(){
        return wage;
    }

    @Override
    public int earning(){
        return wage*hours;
    }

    @Override
    public String toString(){
        return 
            "Hourly Employee:" + 
            "\nFirst Name: " + getFirstName() +
            "\nLast Name: " + getLastName() +
            "\nSocial Security Number: " + getSocialSecurityNumber() +
            "\nWage: " + getWage() +
            "\nHours: " + getHours() + 
            "\nEarning: " + earning();
    }

}
