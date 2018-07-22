public class CommisionEmployee extends Employee{
    private int grossSales;
    private double commisionRate;

    public CommisionEmployee(){
        super();
        grossSales = 0;
        commisionRate = 0.0;
    }
    public CommisionEmployee(String fN, String lN, String sSN, int gS, double cR){
        super(fN, lN, sSN);
        grossSales = gS;
        commisionRate =cR;
    }

    public final void setGrossSales(int gS){        //final���Σ����ܱ����า��
        grossSales = gS;
    }
    public final void setCommisionRate(double cR){
        commisionRate = cR;
    }
    public final int getGrossSales(){
        return grossSales;
    }
    public final double getCommisionRate(){
        return commisionRate;
    }

    @Override
    public int earning(){
        return (int)(grossSales*commisionRate);
    }

    @Override
    public String toString(){
        return 
            "Commision Employee:" +
            "\nFirst Name: " + getFirstName() +
            "\nLast Name: " + getLastName() +
            "\nSocial Security Number: " + getSocialSecurityNumber() +
            "\nGrossSales: " + getGrossSales() +
            "\nCommissionRate: " + getCommisionRate() +
            "\nEarning: " + earning();
    }
}
