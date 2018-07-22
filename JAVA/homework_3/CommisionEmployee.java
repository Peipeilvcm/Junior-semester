/**
 * 作者：裴子祥
 * 班级：计科7班
 * 学号：2015211921
 * 时间：2017.12.11
 */
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

    public final void setGrossSales(int gS){        //final修饰，不能被子类覆盖
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