
public class SalaridEmployee extends Employee {
	
	private int weeklySalary;
	
	public SalaridEmployee() {
		// TODO Auto-generated constructor stub
		super();
        weeklySalary = 0;
	}

	public SalaridEmployee(String fN, String lN, String sSN, int wS){
        super(fN, lN, sSN);
        weeklySalary = wS;
    }
	
	public final void setWeeklySalary(int wS){          //final修饰，不能被子类覆盖
        weeklySalary = wS;
    }
    public final int getWeeklySalary(){
        return weeklySalary;
    }

    @Override
    public int earning(){
        return weeklySalary*4;
    }

    @Override
    public String toString(){
        return 
            "Salarid Employee:" +
            "\nFirst Name: " + getFirstName() +
            "\nLast Name: " + getLastName() +
            "\nSocial Security Number: " + getSocialSecurityNumber() +
            "\nSalary: " + getWeeklySalary() +
            "\nEarning: " + earning();
    }
}
