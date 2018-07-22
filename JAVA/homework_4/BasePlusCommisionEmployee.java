public class BasePlusCommisionEmployee extends CommisionEmployee{
    private int baseSalary;

    public BasePlusCommisionEmployee(){
        super();
        baseSalary = 0;
    }
    public BasePlusCommisionEmployee(String fN, String lN, String sSN, int gS, double cR, int bS){
        super(fN, lN, sSN, gS, cR);
        baseSalary = bS;
    }

    public final void setBaseSalary(int bS){
        baseSalary = bS;
    }
    public final int getBaseSalary(){
        return baseSalary;
    }

    @Override
    public int earning(){
        return super.earning() + baseSalary;
    }

    @Override
    public String toString(){
        return 
            "Base Plus Commision Employee:" +
            "\nFirst Name: " + getFirstName() +
            "\nLast Name: " + getLastName() +
            "\nSocial Security Number: " + getSocialSecurityNumber() +
            "\nGross Sales: " + getGrossSales() +
            "\nCommision Rate: " + getCommisionRate() +
            "\nBase Salary: " + getBaseSalary() +
            "\nEarning: " + earning();
    }
}
